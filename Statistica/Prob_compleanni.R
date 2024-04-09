#Calcolo della probabilità che in un gruppo di n persone
#non ci sia una coppia che condivide il giorno di compleanno

#pulire il workspace
rm(list = ls())

#Lista dei parametri
N_exp = 200 #numero esperimenti
ndays = 365
#numero di persone nel gruppo
#N = seq(from = 1, to = 100, length = 100)
N_vector = 1:100
#inizializzo vettore di tanti 0 quanti sono i valori di N che considero
p_no = rep(0, length(N_vector))
p_almeno2 = rep(0, length(N_vector))
fr = vector()

for (i in 1:length(N_vector)){
  N = N_vector[i]
  #choose() -> coefficiente binomiale
  numero_esiti_favorevoli = factorial(N) * choose(ndays, N)
  numero_esiti_possibili = ndays ^ N

  #prob che non ci siano due persone che condividono il compleanno
  #P(E)
  p_no[i] = numero_esiti_favorevoli / numero_esiti_possibili

  #prob che ci siano almeno due persone con stesso compleanno
  #P(E^c)
  p_almeno2[i] = 1 - p_no[i]
  
  frequenza = vector()
  for(j in 1:N_exp){
    y = sample(1:365, N, replace = TRUE)
    frequenza[j] = anyDuplicated(y)
  }
  fr[i] = sum(frequenza > 0) / N_exp
}

#plot(N_vector, p_no, type = "l")
#lines(N_vector, p_almeno2, type = "l", col = "red")
plot(N_vector, p_almeno2, type = "l", col = "red")
lines(N_vector, fr, type = "l")