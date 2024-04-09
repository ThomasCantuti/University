rm(list = ls())
mu = 13.1
sigma = 0.7

s = seq(11, 15.2, 0.1)
f = (1/sqrt(2*pi*sigma^2))*exp(-(x-mu)^2/(2*sigma^2))

fb = pnorm(13.52, mean = mu, sd = sigma)
Fzb = pnorm((13.52 - mu)/sigma, mean = 0, sd = 1)

Fa = pnorm(12.26, mean = mu, sd = sigma)
Fza = pnorm((12.26 - mu)/sigma), mean = mu, sd = sigma)