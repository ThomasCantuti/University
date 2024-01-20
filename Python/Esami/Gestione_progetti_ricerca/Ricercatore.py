from Partecipazione import Partecipazione

class Ricercatore:
    def __init__(self, cognome, nome):
        self._cognome = cognome
        self._nome = nome
        self._partecipazione = []
        #self._partecipazioni = Partecipazione()

    def addPartecipazione(self, partecipazione):
        self._partecipazione.append(partecipazione)
    
    def getPartecipazione(self):
        return self._partecipazione
    
    def getCognome(self):
        return self._cognome

    def __str__(self):
        return self._nome +"\t"+ self._cognome +"\t"+ str(Partecipazione.getImpegni_Tot()) +"\t"+ str(Partecipazione.getProgetti_Tot()) +"\t"+ str([str(p) for p in self._partecipazione])