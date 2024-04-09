# ESPERIMENTO ESPONENZIALE
rm(list=ls())

x<-seq(-1,10, 0.1)

lambda=2

#plot(x, dexp(x, lambda), type='l')
# generiamo un vettore di dati esponenziali

n_exp = 100 # numero di esperimenti
m_values = 1000 # numero di realizzazioni della v. a. per esperimento
n = n_exp * m_values

dataExp<-rexp(n, rate=lambda)

histData <- hist(dataExp, breaks = 100, freq = FALSE)
matDataExp <- matrix(dataExp, nrow = m_values, ncol = n_exp)
rs = rowSums(matDataExp)
cs = colSums(matDataExp)
rsMatDataExp = rowSums(matDataExp)

# il valore atteso di ogni elemento di ogni matrice di partenza (dataExp/matDataExp) è 1/lambda
# la varianza di ogni elemento in dataExp/matDataExp è 1/lambda^2

mu_data = 1 / lambda
var_data = 1 / (lambda ^ 2)

mu_rs = n_exp * mu_data
var_rs = n_exp * var_data
sd_rs = sqrt(var_rs)

hist(rsMatDataExp, breaks = 70, freq = FALSE)

xval = seq(35, 65, 0.5)
pdfteo = dnorm(xval, mean = mu_rs, sd = sd_rs)
lines(xval, pdfteo, type = "l", col = "red")