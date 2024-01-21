import sys
import argparse

from Ricerca import Ricerca
from Innovazione import Innovazione
from Ricercatore import Ricercatore
from Partecipazione import Partecipazione

class Gestione:
    def __init__(self, arg):
        self._arg = arg

    def main(self):
        progetti = []
        ricercatori = []
        progetto_dict = {}
        try:
            f = open("/home/thomas/Documenti/GitHub/University/Python/Esami/Gestione_progetti_ricerca/progetti.txt", "r")
            line = f.readline().strip()
            while(line != ''):
                tok = line.split()
                cod = int(tok[0])
                tipo = tok[1]
                titolo = f.readline().strip()
                coordinatore = f.readline().strip()
                organizzazione = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                if(tipo == "ricerca"):
                    argomento = tok[0]
                    partner = int(tok[1])
                    importo = float(f.readline().strip())
                    r = Ricerca(cod, titolo, coordinatore, organizzazione, importo, argomento, partner)
                    progetti.append(r)
                    progetto_dict[cod] = r
                else:
                    aziende = int(tok[0])
                    importo = float(tok[1])
                    i = Innovazione(cod, titolo,coordinatore, organizzazione, importo, aziende)
                    progetti.append(i)
                    progetto_dict[cod] = i

                line = f.readline().strip()
            f.close()
        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        try:
            f = open("/home/thomas/Documenti/GitHub/University/Python/Esami/Gestione_progetti_ricerca/ricercatori.txt", "r")
            line = f.readline().strip()
            while(line != ''):
                nome = line
                cognome = f.readline().strip()
                r = Ricercatore(cognome, nome)
                ricercatori.append(r)
                line = f.readline()
                # a capo o termine
                while(line != "\n" and line != ''):
                    tok = line.split()
                    codice_progetto = int(tok[0])
                    orario = float(tok[1])
                    progetto = progetto_dict[codice_progetto]
                    partecipazione = Partecipazione(progetto, orario)
                    r.addPartecipazione(partecipazione)
                    line = f.readline()
                line = f.readline().strip()

            f.close()
        except IOError as i:
            print(i)

        # stampa elenco progetti
        print("tipo, titolo, codice, coordinatore, organizzazione, argomento, partner, aziende, import totale in migliaia di euro")

        for p in progetti:
            print(p)

        print("\n")

        # stampa elenco ricercatori
        for r in ricercatori:
            print(r)

        print("\n")

        try:
            cognome = self._arg
            for ricercatore in ricercatori:
                if ricercatore._cognome == cognome:
                    partecipazione = ricercatore.getImpegno_Max()
                    print(ricercatore._nome +"\t"+ ricercatore._cognome +"\t"+ str(partecipazione._orario) +"\t"+ partecipazione._progetto._titolo)

        except IOError as i:
            print(i)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('cognome', action='store')
    pa = parser.parse_args()
    g = Gestione(pa.cognome)
    g.main()