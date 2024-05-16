import pandas as pd

# Strutture dati in pandas
## esempio di dataframe
data = pd.DataFrame({'Nome': ['Mario', 'Luigi'], 'Cognome': ['Rossi', 'Luigi'], 'Età': ['22', '37']})
print(data)

# Esempio di Series = lista di valori o colonna
data2 = pd.Series(['Mario', 'Luigi'], index=['Persona1', 'Persona2'])
print('\nEsempio di Series: ')
print(data2)

# Lettura di un file CSV
df = pd.read_csv('winemag-data-130k-v2.csv', index_col=0)

## Operazioni sul dataset
print(df.columns)

n_rows, n_columns = df.shape
print('righe:', n_rows, 'colonne:', n_columns)

print(df.head(3))

# per richiamare la colonna del dataframe
print(df.price)
# print(df['price'])

# tipo di dato all'interno della colonna
print(df.price.dtype)
print(df.dtypes)

# accesso ai vari valori della colonna
df.price[1]

# selezionare sottomatrici utilizzando indici numerici
df.iloc[0:3, 0:3]
# selezionare sottomatrici utilizzando labels
df.loc[0:3, ['country', 'description', 'designation']]
# selezionare righe che hanno certe caratteristiche
df.loc[(df.country == 'Italy') & (df.points >= 90)] # & -> and, | -> or
# restituisce tutte le righe che hanno nan su price
df.loc[df.price.isnull()]
# restituisce tutti i valori della colonna senza ripetizioni
df.taster_name.unique()
# restituisce quante volte i valori sono ripetuti nella colonna
df.taster_name.value_counts()

df_taster = df.copy() # copia del dataset per non sporcare il dataset originale
row_taster = df_taster.taster_twitter_handle.loc[df_taster.taster_twitter_handle == '@kerinokeefe']
print("Numero di occorrenze di @kerinokeefe: ", len(row_taster))
print("Numero di occorrenze di @kerinokeefe: ", df_taster.taster_twitter_handle.value_counts()['@kerinokeefe'])

df_taster['taster_twitter_handle'] = df_taster.taster_twitter_handle.replace('@kerinokeefe', '@kerino')
print("Numero di occorrenze di @kerino: ", df_taster.taster_twitter_handle.value_counts()['@kerino'])