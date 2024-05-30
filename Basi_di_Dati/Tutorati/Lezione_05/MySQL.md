1. SELEZIONA TUTTI GLI INVITATI CHE SONO +1
```sql
SELECT *
FROM INVITATO
WHERE plus1 = TRUE;
```

2. SELEZIONA TUTTI I CIBI CHEHANNO PIÙ DI 100 CALORIE
```sql
SELECT *
FROM CIBO
WHERE calorie > 100
```

3. SELEZIONA IL NOME E COGNOME DI TUTTI GLI INVITATI PRESENTI ALLA FESTA E SALVA IL RISULTATO COME LISTA_PARTECIPANTI
```sql
SELECT nome, cognome
FROM INVITATO
WHERE presenza = TRUE
```

4. NUMERO DI PERSONE ALTURNO CON ORARIO 09:00:00
```sql
SELECT COUNT(*)
FROM INVITATO
WHERE ora_turno = '09:00:00'
```

5. NUMERO DI PERSONE A CUI DOVRà DARE UN PASSAGGIO IL GUIDATORE CON CF=CF1
```sql
SELECT COUNT(*)
FROM INVITATO
WHERE CF != CF1 AND CF_guidatore = CF1
```

6. ALLEGENI NON PRESENTI ALLA FESTA **(DISTINCT elimina i duplicati)**
```sql
SELECT *
FROM ALLERGENE.denominazione NOT IN (
    SELECT DISTINCT den_allergene
    FROM CIBO_ALLERGENE
)
UNION (
    SELECT DISTINCT den_allergene
    FROM BEVANDA_ALLERGENE
)
```

7. CIBI E BEVANDE (VOGLIAMO SOLO DENOMINAZIONE E MARCA) CHE SONO SENZA GLUTINE
```sql
SELECT den, marca
FROM (
    (
        SELECT den_cibo AS den, marca_cibo AS marca, den_allergene
        FROM CIBO_ALLERGENE
    )
    UNION
    (
        SELECT den_bevanda AS den, marca_bevanda AS marca, den_allergene
        FROM BEVANDA_ALLERGENE
    )
) AS CB
WHERE den_allergene NOT IN (
    (
        SELECT den_cibo, marca_cibo
        FROM CIBO_ALLERGENE
        WHERE den_allergene = 'glutine'
    )
    UNION
    (
        SELECT den_bevanda, marca_bevanda
        FROM BEVANDA_ALLERGENE
        WHERE den_allergene = 'glutine'
    )
)
```

8. La BEVANDA O LE BEVANDE PIÙ COSTOSE TRA QUELLE PRESENTI
```sql
SELECT *
FROM BEVANDA
WHERE prezzo = (
    SELECT MAX(prezzo)
    FROM BEVANDA
)
```

9. SELEZIONARE NOME E COGNOME DEGLI INVITATI CHE SONO ALLERGICI AD ALMENO UN ALLERGENE
```sql
SELECT DISTINCT nome, cognome
FROM INVITATO, INVITATO_ALLERGENE
WHERE CF = CF_invitato 
```

10. SELEZIONARE TUTTI I TURNI DEL PLANETARIO VUOTI
- query per indicare l'ora del turno e il numero di persone prenotate (si considera che tutte le persone invitate siano in almeno un turno)
```sql
SELECT ora_turno, COUNT(*)
FROM INVITATO
GROUP BY (ora_turno)
```
- query per selezionare i turni vuoti
```sql
SELECT *
FROM TURNO
WHERE ora NOT IN (
    SELECT DISTINCT ora_turno
    FROM INVITATO
)
```

11. SELEZIONARE TUTTI GLI INVITATI CHE SONO GUIDATORI
```sql
SELECT nome, cognome
FROM INVITATO
WHERE CF = CF_guidatore
```

12. SELEZIONARE TUTTI GLI INVITATI MINORENNI
```sql
SELECT nome, cognome
FROM INVITATO
WHERE datanascita > '2006-05-02'
```

13. ASSOCIARE A OGNI INVITATO IL RELATIVO TURNO, LASCIANDO TUTTE LE INFO DEL TURNO
```sql
SELECT *
FROM INVITATO, TURNO
WHERE ora_turno = ora
```

14. TABELLA CHE ASSOCIA A OGNI PERSONA I CIBI E LE BEVANDE CHE NON POSSONO MANGIARE E/0 BERE
```sql
SELECT nome, cognome, den_cibo, marca_cibo
FROM CIBO_ALLERGENE (
    SELECT *
    FROM INVITATO, INVITATO_ALLERGENE
    WHERE CF = CF_invitato
) AS INV_ALL
WHERE INV_ALL.den_allergene = CIBO_ALLERGENE.den_allergene
```