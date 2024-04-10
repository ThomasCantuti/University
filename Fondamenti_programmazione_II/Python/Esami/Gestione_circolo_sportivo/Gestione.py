import sys
import argparse

from Tennis import Tennis
from Squash import Squash
from Socio import Socio
from Prenotazione import Prenotazione

class Gestione:
    def __init__(self, arg):
        self._arg = arg

    def main(self):
        campi = []
        soci = []
        # codice_campi = {}
        try:
            f = open("/home/thomas/Documenti/GitHub/University/Python/Esami/Gestione_circolo_sportivo/campi.txt", "r")
            line = f.readline().strip()
            while(line != ''):
                tok = line.split()
                codice = int(tok[0])
                sport = tok[1]
                nome_campo = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                if(sport == "tennis"):
                    larghezza = float(tok[0])
                    lunghezza = float(tok[1])
                    temperatura = float(tok[2])
                    line = f.readline()
                    terreno = line
                    line = f.readline()
                    costo = float(line)
                    t = Tennis(codice, nome_campo, larghezza, lunghezza, temperatura, terreno, costo)
                    campi.append(t)
                    # codice_campi[codice] = t
                else:
                    larghezza = float(tok[0])
                    lunghezza = float(tok[1])
                    altezza = float(tok[2])
                    piano = int(tok[3])
                    costo = float(tok[4])
                    s = Squash(codice, nome_campo, larghezza, lunghezza, altezza, piano, codice)
                    campi.append(s)
                    # codice_campi[codice] = s

                line = f.readline().strip()
            f.close()
        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        try:
            f = open("/home/thomas/Documenti/GitHub/University/Python/Esami/Gestione_circolo_sportivo/soci.txt", "r")
            line = f.readline().strip()
            while(line != ''):
                codice = int(line)
                line = f.readline().strip()
                tok = line.split()
                nome = tok[0]
                cognome = tok[1]
                line = f.readline().strip()
                tok = line.split()
                eta = int(tok[0])
                categoria = int(tok[1])
                s = Socio(codice, nome, cognome, eta, categoria)
                soci.append(s)
                line = f.readline().strip()
                tok = line.split()
                # fine riga di elementi o termine
                for i in range(0, len(tok), 2):
                    codice_campo = int(tok[i])
                    orario = int(tok[i+1])
                    prenotazione = Prenotazione(codice_campo, orario)
                    s.addPrenotazione(prenotazione)
                    # codice_campi[codice_campo].addPrenotazione()
                line = f.readline().strip()
            f.close()
        except IOError as i:
            print(i)

        # stampa elenco campi
        print("sport, nome del campo, codice, larghezza, lunghezza, temperatura, terreno, altezza, piano, costo")

        for c in campi:
            print(c)

        print("\n")

        # stampa elenco soci
        print("codice, nome e cognome, età, categoria, prenotazioni")

        for s in soci:
            print(s)

        print("\n")


        """
        try:
            codice_campo = int(self._arg)
            print(str(codice_campi.get(codice_campo).incasso()))
        """

        try:
            codice_campo = int(self._arg)
            n_prenotazioni = 0
            for s in soci:
                prenotazioni = s.getPrenotazioni()
                for p in prenotazioni:
                    if (codice_campo == p.getCodice()):
                        n_prenotazioni += 1
            for c in campi:
                if c.getCodice() == codice_campo:
                    incasso = n_prenotazioni * c.getCosto()
            print(str(codice_campo) + "\t" + str(incasso))

        except IOError as i:
            print(i)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('campo', action='store')
    pa = parser.parse_args()
    g = Gestione(pa.campo)
    g.main()