class Campo:
    def __init__(self, codice, campo, larghezza, lunghezza, costo, sport):
        self._codice = codice
        self._campo = campo
        self._larghezza = larghezza
        self._lunghezza = lunghezza
        self._costo = costo
        self._sport = sport
        # self._prenotazioni = 0

    def getSport(self):
        return self._sport

    def getCodice(self):
        return self._codice

    def getCosto(self):
        return self._costo
    
    """
    def addPrenotazioni(self):
        self._prenotazioni += 1

    def incasso(self):
        return self._prenotazioni * self._costo
    """

    def __str__(self):
        return self._sport + "\t" + self._campo + "\t" + str(self._codice) + "\t"