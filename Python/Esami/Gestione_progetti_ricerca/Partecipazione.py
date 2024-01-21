from Progetto import Progetto

class Partecipazione:
    progetto: Progetto
    def __init__(self, progetto, orario):
        self._progetto = progetto
        self._orario = orario
   
    def getOrario(self):
        return self._orario

    def getCodice(self):
        return self._progetto

    def __str__(self):
        return "(" + str(self._progetto._codice) + "," + str(self._orario) + ")"