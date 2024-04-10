from Campo import Campo

class Tennis(Campo):
    def __init__(self, codice, campo, larghezza, lunghezza, temperatura, terreno, costo):
        super().__init__(codice,campo, larghezza, lunghezza, costo, "tennis")
        self._temperatura = temperatura
        self.terreno = terreno

    def __str__(self):
        return super().__str__() + str(self._larghezza) +"\t"+ str(self._lunghezza) +"\t"+ str(self._temperatura ) +"\t"+ str(self.terreno) +"\t-\t-\t"+ str(self._costo)