#define _POSIX_C_SOURCE	200809L
#include <stdio.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "utils.h"

#define MAXCHAR 4096

/* Funzione che usa strtol per leggere il numero naturale (ovverosia intero non
 * negativo) all'inizio di una stringa. */
int get_natural(const char *str)
{
        long ret;
        char *endptr;	

        ret = strtol(str, &endptr, 10);

        if (ret == 0 && errno == EINVAL) {
                // nessuna conversione effettuata
                return -1;
        }

        if (errno == ERANGE) {
                if (ret == LONG_MIN) {
                        // underflow
                        return -2;
                } else { // ret == LONG_MAX
                        // overflow
                        return -3;
                }
        }

        if (ret < 0 || ret > INT_MAX) {
                return -4;
        }

        return (int)ret;
}

/* Funzione che calcola la media e che ad ogni lettura con fgets,
 * scrive quello che ha letto sul file descriptor fd_out.
 * Come operazione finale scrive su fd_out anche la media. */ 
void output_with_average(int fd_in, int fd_out)
{
        FILE *stream;
        char str[MAXCHAR], avrg_str[MAXCHAR]; 
        int tot = 0, ret;
        float avrg;
	int lines = 0;

        /* Incapsulo il filedescriptor in un FILE* così posso utilizzare fgets */
        stream = fdopen(fd_in, "r");
        if (stream == NULL) {
                fprintf(stderr, "Could not open file %d", fd_in);
                exit(EXIT_FAILURE);
        }

        /* fgets legge finchè non incontra un \n o \0.
         * In questo caso la sfrutto per leggere riga per riga
         * il risultato della exec  */
        while (fgets(str, MAXCHAR, stream) != NULL) {
                /* Scrivo la riga letta con fgets su fd_out
                 * che nel mio caso sarà il socket descriptor ns */
                if (write_all(fd_out, str, strlen(str)) < 0) {
                        perror("write exec"); 
                        exit(EXIT_FAILURE);
                }

                /* Prendo il numero a inizio riga con get_natural. Assumo che
                 * il separatore sia uno spazio, altrimenti dovrei manipolare
                 * la stringa per trasformare, ad esempio, un separatore ',' in
                 * un separatore ' '. */
                if ((ret = get_natural(str)) >= 0) {
                        tot += ret;
                }

                /* Aggiorna conteggio linee lette */
                lines += 1;
        }

        /* Chiudo file */
        fclose(stream);

        if (lines > 0) {
                /* Calcolo media e la formatto con snprintf */
                avrg = (float)tot / (float)lines;

                /* Preparo messaggio di riassunto */
                snprintf(avrg_str, sizeof(avrg_str), "\nLa Media di cm di neve sugli impianti richiesti è :%f\n", avrg);

                /* Scrivo la media su fd_out, ovvero la socket*/
                if (write_all(fd_out, avrg_str, strlen(avrg_str)) < 0){
                        perror("write finale average");
                        exit(EXIT_FAILURE);
                }
        }
}

