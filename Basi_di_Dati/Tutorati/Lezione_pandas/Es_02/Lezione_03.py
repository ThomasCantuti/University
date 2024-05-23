import pandas as pd
from scipy import stats
from mlxtend.preprocessing import minmax_scaling
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np

dataset1 = pd.read_csv('winemag-data-130k-v2.csv', index_col=0)

# Scaling and normalization
dfnan = dataset1.copy()
mean_price = dfnan.price.mean()
df_filled = dfnan.fillna({'price': mean_price})

ydsnet = np.array(df_filled.loc[df_filled.price < 200].price)

scaled_data = minmax_scaling(ydsnet, columns=[0])

# ...

# Esempio di normalizzazione
dfnan = dataset1.copy()
mean_price = dfnan.price.mean()
df_filled = dfnan.fillna({'price': mean_price})

ydsnet = np.array(df_filled.loc[df_filled.price < 200].price)

normalized_data = stats.boxcox(ydsnet)

# ...


# Gestione delle date
dataset2 = pd.read_csv('nfl_play_by_play_2009-2016_v3.csv')

# print(dataset2.columns)
dates = pd.Series(dataset2.Date)
print(dates)
date_parsed = pd.to_datetime(dates)
date_parsed = date_parsed.dt.strftime('%d%m%Y')
print(date_parsed)

data = pd.to_datetime(dates)
data = data.dt.year
print(data)