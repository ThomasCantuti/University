import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import binom, poisson, hypergeom, nbinom, geom, uniform, gamma, expon, beta, norm

# 1. Distribuzione Binomiale
n, p = 10, 0.5
x_binom = np.arange(0, n + 1)
y_binom = binom.pmf(x_binom, n, p)

plt.figure(figsize=(15, 12))

plt.subplot(4, 3, 1)
plt.stem(x_binom, y_binom, basefmt=" ")
plt.title('Distribuzione Binomiale (n=10, p=0.5)')

# 2. Distribuzione di Poisson
mu = 3
x_poisson = np.arange(0, 15)
y_poisson = poisson.pmf(x_poisson, mu)

plt.subplot(4, 3, 2)
plt.stem(x_poisson, y_poisson, basefmt=" ")
plt.title('Distribuzione di Poisson (λ=3)')

# 3. Distribuzione Ipergeometrica
N, K, n = 20, 7, 12
x_hypergeom = np.arange(0, n + 1)
y_hypergeom = hypergeom.pmf(x_hypergeom, N, K, n)

plt.subplot(4, 3, 3)
plt.stem(x_hypergeom, y_hypergeom, basefmt=" ")
plt.title('Distribuzione Ipergeometrica (N=20, K=7, n=12)')

# 4. Distribuzione Binomiale Negativa
r, p = 5, 0.4
x_nbinom = np.arange(0, 20)
y_nbinom = nbinom.pmf(x_nbinom, r, p)

plt.subplot(4, 3, 4)
plt.stem(x_nbinom, y_nbinom, basefmt=" ")
plt.title('Distribuzione Binomiale Negativa (r=5, p=0.4)')

# 5. Distribuzione Geometrica
p_geom = 0.3
x_geom = np.arange(1, 20)
y_geom = geom.pmf(x_geom, p_geom)

plt.subplot(4, 3, 5)
plt.stem(x_geom, y_geom, basefmt=" ")
plt.title('Distribuzione Geometrica (p=0.3)')

# 6. Distribuzione Uniforme
a, b = 0, 1
x_uniform = np.linspace(a, b, 100)
y_uniform = uniform.pdf(x_uniform, a, b - a)

plt.subplot(4, 3, 6)
plt.plot(x_uniform, y_uniform)
plt.title('Distribuzione Uniforme (a=0, b=1)')

# 7. Distribuzione Gamma
alpha, beta_param = 2, 1
x_gamma = np.linspace(0, 10, 100)
y_gamma = gamma.pdf(x_gamma, alpha, scale=1/beta_param)

plt.subplot(4, 3, 7)
plt.plot(x_gamma, y_gamma)
plt.title('Distribuzione Gamma (α=2, β=1)')

# 8. Distribuzione Esponenziale Negativa
lambda_exp = 1
x_expon = np.linspace(0, 10, 100)
y_expon = expon.pdf(x_expon, scale=1/lambda_exp)

plt.subplot(4, 3, 8)
plt.plot(x_expon, y_expon)
plt.title('Distribuzione Esponenziale (λ=1)')

# 9. Distribuzione Normale
mu_norm, sigma = 0, 1
x_norm = np.linspace(-4, 4, 100)
y_norm = norm.pdf(x_norm, mu_norm, sigma)

plt.subplot(4, 3, 9)
plt.plot(x_norm, y_norm)
plt.title('Distribuzione Normale (μ=0, σ=1)')

# 10. Distribuzione Beta
a, b = 2, 5
x_beta = np.linspace(0, 1, 100)
y_beta = beta.pdf(x_beta, a, b)

plt.subplot(4, 3, 10)
plt.plot(x_beta, y_beta)
plt.title('Distribuzione Beta (a=2, b=5)')

plt.tight_layout()
plt.show()
