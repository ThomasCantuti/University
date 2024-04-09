rm(list = ls())

#Dati del prblema
n = 10 #numero di lanci
p = 0.6 #probabilità di avere testa

#supporto di K
#possibili valori di K
#K = (v.a. {quante teste ottengo in n lanci})
Sk = 0:10
Sk_v2 = seq(0, 10)

#possibili valori della funzione ricompensa, dipende da K
SR = Sk^2 - 7*Sk

#Grafichiamo la ricompensa in funzione del numero di teste
plot(Sk, SR, pch = 19)

#PMF di K -> P(K = k)
pmf_k = choose(n, Sk) * p^Sk * (1 - p)^(n - Sk)
plot(Sk, pmf_k, pch = 19)
pmf_k_v2 = dbinom(Sk, n, p)

#CDF di K -> P(K <= k)
cdf_k = cumsum(pmf_k)
plot(Sk, cdf_k, pch = 19)
cdf_k_v2 = pbinom(Sk, n, p)

#quello che mi aspetto di ricevere
expectation_k = sum(Sk * pmf_k)
expectation_SR = sum(SR * pmf_k)

#imitare il lancio del dado
rbinom(6, 6, 1/6)