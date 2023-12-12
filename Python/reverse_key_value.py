'''
Inversione key - value per trovare una key dato il value
'''

dict = {
    'Boss Nass':'Star Wars',
    'Tom Bombadil':'The Lord of the Rings',
    'Hari Seldon':'Foundation series',
    'Polliver':'Game of Thrones',
    'Jules Winnfield':'Pulp Fiction',
    'The Mule':'Foundation series',
    'Flynn Rider':'Rapunzel',
    'Yoda':'Star Wars',
    'Vince Vega':'Pulp Fiction',
}

dict_invertito = {}

for key, value in dict.items():
    dict_invertito.setdefault(value, []).append(key)


print(dict_invertito)