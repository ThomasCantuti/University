class Prenotazione:
    def __init__(self, campo, ora):
        self._campo = campo
        self._ora = ora
    
    def getOra(self):
        return self._ora

    def getCodice(self):
        return self._campo

    def __str__(self):
        return "(" + str(self._campo) + "," + str(self._ora) + ")"