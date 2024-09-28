# Caricamento delle librerie necessarie
library(ggplot2)
library(gridExtra)

# 1. Distribuzione Binomiale
n <- 10
p <- 0.5
x_binom <- 0:n
y_binom <- dbinom(x_binom, size = n, prob = p)

# Grafico della Distribuzione Binomiale
plot_binom <- ggplot(data.frame(x_binom, y_binom), aes(x = x_binom, y = y_binom)) +
  geom_segment(aes(xend = x_binom, yend = 0), color = "blue") +
  geom_point(size = 3, color = "blue") +
  ggtitle("Distribuzione Binomiale (n=10, p=0.5)") +
  ylim(0, max(y_binom) + 0.05)

# 2. Distribuzione di Poisson
mu <- 3
x_poisson <- 0:15
y_poisson <- dpois(x_poisson, lambda = mu)

# Grafico della Distribuzione di Poisson
plot_poisson <- ggplot(data.frame(x_poisson, y_poisson), aes(x = x_poisson, y = y_poisson)) +
  geom_segment(aes(xend = x_poisson, yend = 0), color = "red") +
  geom_point(size = 3, color = "red") +
  ggtitle("Distribuzione di Poisson (λ=3)") +
  ylim(0, max(y_poisson) + 0.05)

# 3. Distribuzione Ipergeometrica
N <- 20
K <- 7
n <- 12
x_hypergeom <- 0:n
y_hypergeom <- dhyper(x_hypergeom, m = K, n = N - K, k = n)

# Grafico della Distribuzione Ipergeometrica
plot_hypergeom <- ggplot(data.frame(x_hypergeom, y_hypergeom), aes(x = x_hypergeom, y = y_hypergeom)) +
  geom_segment(aes(xend = x_hypergeom, yend = 0), color = "green") +
  geom_point(size = 3, color = "green") +
  ggtitle("Distribuzione Ipergeometrica (N=20, K=7, n=12)") +
  ylim(0, max(y_hypergeom) + 0.05)

# 4. Distribuzione Binomiale Negativa
r <- 5
p <- 0.4
x_nbinom <- 0:20
y_nbinom <- dnbinom(x_nbinom, size = r, prob = p)

# Grafico della Distribuzione Binomiale Negativa
plot_nbinom <- ggplot(data.frame(x_nbinom, y_nbinom), aes(x = x_nbinom, y = y_nbinom)) +
  geom_segment(aes(xend = x_nbinom, yend = 0), color = "purple") +
  geom_point(size = 3, color = "purple") +
  ggtitle("Distribuzione Binomiale Negativa (r=5, p=0.4)") +
  ylim(0, max(y_nbinom) + 0.05)

# 5. Distribuzione Geometrica
p_geom <- 0.3
x_geom <- 1:20
y_geom <- dgeom(x_geom - 1, prob = p_geom)

# Grafico della Distribuzione Geometrica
plot_geom <- ggplot(data.frame(x_geom, y_geom), aes(x = x_geom, y = y_geom)) +
  geom_segment(aes(xend = x_geom, yend = 0), color = "orange") +
  geom_point(size = 3, color = "orange") +
  ggtitle("Distribuzione Geometrica (p=0.3)") +
  ylim(0, max(y_geom) + 0.05)

# 6. Distribuzione Uniforme
a <- 0
b <- 1
x_uniform <- seq(a, b, length.out = 100)
y_uniform <- dunif(x_uniform, min = a, max = b)

# Grafico della Distribuzione Uniforme
plot_uniform <- ggplot(data.frame(x_uniform, y_uniform), aes(x = x_uniform, y = y_uniform)) +
  geom_line(color = "brown") +
  ggtitle("Distribuzione Uniforme (a=0, b=1)") +
  ylim(0, max(y_uniform) + 0.05)

# 7. Distribuzione Gamma
alpha <- 2
beta_param <- 1
x_gamma <- seq(0, 10, length.out = 100)
y_gamma <- dgamma(x_gamma, shape = alpha, scale = 1/beta_param)

# Grafico della Distribuzione Gamma
plot_gamma <- ggplot(data.frame(x_gamma, y_gamma), aes(x = x_gamma, y = y_gamma)) +
  geom_line(color = "cyan") +
  ggtitle("Distribuzione Gamma (α=2, β=1)") +
  ylim(0, max(y_gamma) + 0.05)

# 8. Distribuzione Esponenziale
lambda_exp <- 1
x_expon <- seq(0, 10, length.out = 100)
y_expon <- dexp(x_expon, rate = lambda_exp)

# Grafico della Distribuzione Esponenziale
plot_expon <- ggplot(data.frame(x_expon, y_expon), aes(x = x_expon, y = y_expon)) +
  geom_line(color = "magenta") +
  ggtitle("Distribuzione Esponenziale (λ=1)") +
  ylim(0, max(y_expon) + 0.05)

# 9. Distribuzione Normale
mu_norm <- 0
sigma <- 1
x_norm <- seq(-4, 4, length.out = 100)
y_norm <- dnorm(x_norm, mean = mu_norm, sd = sigma)

# Grafico della Distribuzione Normale
plot_norm <- ggplot(data.frame(x_norm, y_norm), aes(x = x_norm, y = y_norm)) +
  geom_line(color = "yellow") +
  ggtitle("Distribuzione Normale (μ=0, σ=1)") +
  ylim(0, max(y_norm) + 0.05)

# Combinazione dei grafici
grid.arrange(plot_binom, plot_poisson, plot_hypergeom, plot_nbinom, plot_geom, plot_uniform,
             plot_gamma, plot_expon, plot_norm, ncol = 3)
