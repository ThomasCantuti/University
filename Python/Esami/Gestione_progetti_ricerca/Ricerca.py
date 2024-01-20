from Progetto import Progetto

class Ricerca(Progetto):
    def __init__(self, codice, titolo, coordinatore, organizzazione, importo, argomento, partner):
        super().__init__(codice, titolo, coordinatore, organizzazione, importo, "ricerca")
        self._argomento= argomento
        self._partner = partner

    def __str__(self):
        return super().__str__() + self._argomento +"\t"+ str(self._partner) +"\t-\t"+ str(self._importo*1000)