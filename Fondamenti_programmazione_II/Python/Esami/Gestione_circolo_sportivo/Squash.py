from Campo import Campo

class Squash(Campo):
    def __init__(self, codice, campo, larghezza, lunghezza, altezza, piano, costo):
        super().__init__(codice, campo, larghezza, lunghezza, costo, "squash")
        self._altezza = altezza
        self._piano = piano

    def toString(self):
        return super().__str__() + str(self._larghezza) +"\t"+ str(self._lunghezza) +"\t-\t-\t"+ str(self._altezza) +"\t"+ str(self._piano) +"\t"+ self._altezza +"\t"+ str(self._costo)