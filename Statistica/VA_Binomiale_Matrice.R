# ESPERIMENTO BINOMIALE
rm(list=ls())

# Parametri distrubuzione binomiale:
n_bin = 5
p = 0.5

n_exp = 100 # numero di esperimenti
m_values = 1000 # numero di realizzazioni della v. a. per esperimento
n = n_exp * m_values

dataBin<-rexp(n, rate=p)# ???

histData <- hist(dataBin, breaks = 100, freq = FALSE)
matDataBin <- matrix(dataBin, nrow = m_values, ncol = n_exp)
rs = rowSums(matDataBin)
cs = colSums(matDataBin)
rsMatDataBin = rowSums(matDataBin)

# il valore atteso di ogni elemento di ogni matrice di partenza (dataBin/matDataBin) è E[X_i] = n_bin * p
# la varianza di ogni elemento in dataBin/matDataBin è Var[X_i] = n_bin * p * (1 - p)

mu_data = n_bin * p
var_data = n_bin * p * (1 - p)

mu_rs = n_exp * mu_data
var_rs = n_exp * var_data
sd_rs = sqrt(var_rs)

hist(rsMatDataBin, breaks = 70, freq = FALSE)

xval = seq(220, 265, 0.5) # range da definire per vederen dove sta la curva della Gaussiana
pdfteo = dnorm(xval, mean = mu_rs, sd = sd_rs)
lines(rsMatDataBin, pdfteo, type = "l", col = "red")