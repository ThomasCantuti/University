import pandas as pd

dataset1 = pd.read_csv('winemag-data-130k-v2.csv', index_col=0)

# Gestione dei valori NaN (o null)
dfnan = dataset1.copy()

## Tecnica 1: eliminare le righe che contengono NaN
dfnan.dropna(axis=0, inplace=True)

print(dfnan.shape)
print(dfnan.loc[dfnan.country == 'Egypt'])

## Tecnica 2: eliminare colonne che hanno NaN
dfnan = dataset1.copy()

dfnan.dropna(axis=1, inplace=True)
print(dfnan.shape)
print(dfnan.columns)

## Tecnica 3: come sostituire ai NaN un valore
dfnan = dataset1.copy()

### si usa la stessa regola di sostituzione per ogni NaN
dfnan.fillna(value=0, inplace=True)
print(dfnan.loc[dfnan.country == 'Egypt'])

### si mettono valori che hanno senso
#### Esempio per riempire colonne categoriche (contengono stringhe)
dfnan = dataset1.copy()

n_rows = dfnan[dfnan.country.isnull()].shape[0]
print(n_rows) # righe di NaN

nan_indices = dfnan.loc[dfnan.country.isnull()].index
print(nan_indices)
print(dfnan.loc[nan_indices, 'country'])

mode_country = dfnan.country.mode()[0]
print(mode_country)

df_filled = dfnan.fillna({'country': mode_country})
print(df_filled.loc[nan_indices, 'country'])

#### Esempio per sostituire a valori NaN dei valori numerici
dfnan = dataset1.copy()

n_rows = dfnan[dfnan.price.isnull()].shape[0]
nan_indices = dfnan.loc[dfnan.price.isnull()].index

mean_price = dfnan.price.mean()

df_filled = dfnan.fillna({'price': mean_price})

print(n_rows)
print(nan_indices)

print(dfnan.loc[nan_indices, 'price'])
print(df_filled.loc[nan_indices, 'price'])