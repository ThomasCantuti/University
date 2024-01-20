class Progetto:
    def __init__(self, codice, titolo, coordinatore, organizzazione, importo, tipo):
        self._codice = codice
        self._titolo = titolo
        self._coordinatore = coordinatore
        self._organizzazione = organizzazione
        self._importo = importo
        self._tipo = tipo 

    def getTipo(self):
        return self._tipo

    def getCodice(self):
        return self._codice

    def __str__(self):
        return self._tipo +"\t"+ self._titolo +"\t"+ str(self._codice) +"\t"+ self._coordinatore +"\t"+ self._organizzazione +"\t"