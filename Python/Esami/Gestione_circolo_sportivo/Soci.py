class Soci:
    def __init__(self, codice, nome, cognome, eta, categoria):
        self._codice = codice
        self._cognome = cognome
        self._nome = nome
        self._eta = eta
        self.categoria = categoria
        self._prenotazioni = []

    def addPrenotazione(self, prenotazione):
        self._prenotazioni.append(prenotazione)
    
    def getPrenotazioni(self):
        return self._prenotazioni

    def __str__(self):
        return str(self._codice) +"\t"+ self._nome +"\t"+ self._cognome +"\t"+ str(self._eta) +"\t"+ str(self.categoria) +"\t"+ str([str(p) for p in self._prenotazioni])