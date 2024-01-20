from Progetto import Progetto

class Innovazione(Progetto):
    def __init__(self, codice, titolo, coordinatore, organizzazione, importo, aziende):
        super().__init__(codice, titolo, coordinatore, organizzazione, importo, "innovazione")
        self._aziende = aziende

    def toString(self):
        return super().__str__() +"-\t-\t"+ str(self._aziende) +"\t"+ str(self._importo*1000)