scrivere in MySQL la seguente query:
```sql
SELECT *
FROM INVITATO
WHERE plus1 = TRUE;
```

```sql
SELECT *
FROM CIBO
WHERE calorie > 100
```

Seleziona nome e cognome di tutti gli invitati
```sql
SELECT nome, cognome
FROM INVITATO
WHERE presenza = TRUE
```

Numero di persone al turno con orario 9
```sql
SELECT COUNT(*)
FROM INVITATO
WHERE ora_turno = '09:00:00'
```

Numero di persone a cui dovrà dare il passaggio
```sql
SELECT COUNT(*)
FROM INVITATO
WHERE CF != CF1 AND CF_guidatore = CF1
```

```sql
SELECT *
FROM ALLERGENE.denominazione NOT IN (
    SELECT DISTINCT den_allergene
    WHERE CIBO_ALLERGENE
)
UNION (
    SELECT DISTINCT den_allergene
    WHERE BEVANDA_ALLERGENE
)
```
