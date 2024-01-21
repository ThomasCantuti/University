from Partecipazione import Partecipazione

class Ricercatore:
    def __init__(self, cognome, nome):
        self._cognome = cognome
        self._nome = nome
        self._partecipazioni = []

    def addPartecipazione(self, partecipazione):
        self._partecipazioni.append(partecipazione)
    
    def getImpegni_Tot(self):
        tot = 0
        for partecipazione in self._partecipazioni:
            tot += partecipazione._orario
        return tot
    
    def getImpegno_Max(self):
        result: Partecipazione = None
        max = 0
        for partecipazione in self._partecipazioni:
            if partecipazione._orario > max:
                max = partecipazione._orario
                result = partecipazione
        return result

    def __str__(self):
        return self._nome +"\t"+ self._cognome +"\t"+ str(self.getImpegni_Tot()) +"\t"+ str(len(self._partecipazioni)) +"\t"+ str([str(p) for p in self._partecipazioni])