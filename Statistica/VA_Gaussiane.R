rm(list = ls())

#dnorm, rnorm, pnorm
#v.a. normale con valore atteso e dev standard unitaria
x = seq(-6, 6, 0.1)

#dnorm: permette di valutare la pdf di una v.a. gaussiana
y = dnorm(x, mean = 0, sd = 1, log = FALSE)
plot(x, y, type = "l", col = "blue")

y1 = dnorm(x, mean = 2, sd = 1, log = FALSE)
lines(x, y1, type = "l", col = "red")

y2 = dnorm(x, mean = 0, sd = 3, log = FALSE)
lines(x, y2, type = "l", col = "green")

#rnorm
rnorm(1, 0, 1)
x1 = rnorm(10000, 0, 1)
hist(x1, breaks = 70, freq = FALSE)
x2 = seq(-3, 3, 0.1)
lines(x2, dnorm(x2, mean = 0, sd = 1), type = "l", col = "red")

#regola empirica
n = 10000
x1 = rnorm(n, 0, 1)
sum(x1 >= -1 & x1 <= 1)/n
sum(x1 >= -2 & x1 <= 2)/n
sum(x1 >= -3 & x1 <= 3)/n