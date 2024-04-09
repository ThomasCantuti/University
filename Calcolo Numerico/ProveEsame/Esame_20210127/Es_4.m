% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 4
% ---------------

close all
clear all
clc

disp('Esercizio 4');

prompt = 'Inserire numero intero >= 3: ';
n = input(prompt);

while(n < 3)
    n = input(prompt);
end

d0 = 4 * ones(n, 1);
dupper = 2/3 * ones(n, 1);
dlower = -0.5 * ones(n, 1);
An = spdiags([d0, dupper dlower], [0 2 -2], n, n);
bn = - ones(n); bn(2:2:end) = 1/4;

% metodo Jacobi
tol = 1.0e-3; maxit = 100; x = sparse(n, 1); k = 0; stop = 0;
Dinv = diag(  1./diag(An) );
J = - Dinv * (tril(An, -1) + triu(An, 1));
while(~stop)
    k = k + 1;
    xold = x;
    x = J*x + Dinv*bn;
    stop = ( norm(x - xold, 'inf') < tol * norm(x, 'inf') || (k == maxit) );
end

fprintf('Approssimazione della soluzione mediante Jacobi: %e\n', x);
fprintf('Numero di iterazioni: %g\n', k);
fprintf('Massimo modulo degli autovalori di An: %e\n', eigs(J, 1));