% Cantuti Thomas
% 187390

% ----------------
%   esercizio 4
% ----------------

close all
clear all
clc

disp('Esercizio 4');

A = [9 -3 1; -2 9 0; -2 0 9];
Dinv = diag( 1./diag(A) );

J = - Dinv * (triu(A, 1) + tril(A, -1));
G = - tril(A) \ triu(A, 1);

rsJ = max( abs( eig(J) ) );
rsG = max( abs( eig(G) ) );

fprintf('Il raggio spettrale di J e'' %e\n',  rsJ);
fprintf('Il raggio spettrale di G e'' %e\n',  rsG);
fprintf('La vel. asint. di conv. di J e'' %f\n', -log(rsJ) );
fprintf('La vel. asint. di conv. di J e'' %f\n', -log(rsG) );

b = [5 -2 3]';
tol = 1e-5;
maxit = 100;
x0 = [0 0 0]';

% soluzione con Jacobi
[x, k] = jacobi(A, b, x0, maxit, tol);
fprintf('Iterazioni = %g\n', k);
fprintf('Soluzione approssimata con Jacobi: ');
x

% soluzione con Gauss - Seidel
xold = x0;
y = (tril(A) \ b);
k = 0;
stop = 0;
while(~ stop)
    k = k + 1;
    xG = G * xold + y;
    stop = (k == maxit) || (norm(xold - xG, inf) < tol*norm(xG, inf));
end
fprintf('Iterazioni = %g\n', k);
fprintf('Soluzione approssimata con Gauss-Seidel: ');
xG