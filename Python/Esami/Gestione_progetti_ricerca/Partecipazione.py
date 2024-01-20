class Partecipazione:
    def __init__(self, progetto, orario):
        self._progetto = progetto
        self._orario = orario
        self._progetti_tot = 0
        self._impegno_tot = 0
    
    def getOrario(self):
        return self._orario

    def getCodice(self):
        return self._progetto
    
    def getImpegni_Tot(self):
        self._impegno_tot = self._impegno_tot + self._orario
        return self._impegno_tot
    
    def getProgetti_Tot(self):
        self._progetti_tot = self._progetti_tot + self._progetto
        return self._progetti_tot

    def __str__(self):
        return "(" + str(self._progetto) + "," + str(self._orario) + ")"