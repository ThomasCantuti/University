alpha = 0; % estremo iniziale intervallo
beta = 1; % estremo finale intervallo
n = 5; % numero di punti di discretizzazione
h = (beta - alpha) / (n + 1); % passo di discretizzazione

% funzioni in line al posto di creare funzioni.m
c = @(x)(x); 
f = @(x)(-exp(x) .* (1-x) + (16*pi^2 + x) .* sin(4*pi*x));
y = @(x)();

invh2 = 1 / h^2;

A = spdiags([-ones(n, 1)*(invh2), (ones(n, 1)*2*invh2 + c(x)), -ones(n, 1)*2...])
b = sparse(n, 1) * f(x);
b([1, n]) = b([1, n]) + [alpha; beta] * invh2;