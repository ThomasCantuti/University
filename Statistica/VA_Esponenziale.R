rm(list = ls())

#dexp, pexp, qexp, rexp (rate è lambda)
#creo vettore x di valutazione di pdf exp
x = seq(-1, 10, 0.1)
lambda = 2
y = dexp(x, rate = lambda)

plot(x, y, type = 'l')

n = 1000 #numero di dati che voglio generare
dataExp = rexp(n, rate = lambda)
#histData = hist(dataExp, breaks = 70)#con breaks ci sono più intervalli
histData = hist(dataExp, breaks = 70, freq = FALSE)#con freq si calcola la prob di massa
#plot(histData$counts/n, type = 'l')
h = histData$breaks[2]
xval = seq(min(dataExp), max(dataExp), h)
lines(xval, histData$counts/n/h, type = 'l', col="blue")