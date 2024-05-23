import pandas as pd

dataset1 = pd.read_csv('winemag-data-130k-v2.csv', index_col=0)

# Raggruppare e ordinare i dati
## Raggruppamenti
print(dataset1.groupby('points').points.count())

print(dataset1.groupby('points').price.min())
print(dataset1.groupby('points').price.max())

print(dataset1.groupby(['country', 'province']).description.agg([len]))
print(dataset1.groupby(['country', 'province']).price.agg([len, 'min', 'max']))

print(dataset1.groupby('winery').apply(lambda dataset1: dataset1.title.iloc[0]))

print(dataset1.groupby('winery').price.mean())

## Ordinamenti
my_winery = dataset1.loc[dataset1.winery == "10 Knots"]
#print(len(my_winery))
#print(my_winery)

my_winery = my_winery.reset_index()
#print(my_winery)

my_winery.sort_values(by='price') # default: ascending = True
my_winery.sort_values(by='price', ascending=False)
print(my_winery.sort_values(by=['country', 'price']))