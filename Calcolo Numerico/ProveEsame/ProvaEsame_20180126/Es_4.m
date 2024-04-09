% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 4
% ---------------

close all
clear all
clc

disp('Esercizio 4');

A = [9 -3 -1; -2 9 0; -2 0 9];
Dinv = diag( 1./ diag(A) );
J = - Dinv * (triu(A, 1) + tril(A, -1));
G = -(tril(A)) \ triu(A, 1);
rhoJ = max( abs( eig(J) ) );
rhoG = max( abs( eig(G) ) );
RinfJ = -log( rhoJ );
RinfG = -log( rhoG );

fprintf('Jacobi:\nRaggio spettrale = %e\nVelocita'' asintotica = %g\n', rhoJ, RinfJ);
fprintf('Gauss-Seidel:\nRaggio spettrale = %e\nVelocita'' asintotica = %g\n', rhoG, RinfG);

b = [5 -2 3]';
tol = 1.0e-5;
maxit = 100;
x0 = [0 0 0]';

% metodo Jacobi
disp('Metodo Jacobi');
[x, k] = jacobi(A, b, x0, maxit, tol);
disp('Approssimazione soluzione: ');
x
disp('Numero di iterazioni: ');
k

% metodo Gauss - Seidel
k = 0; stop = 0;
while ( ~ stop )
    k = k + 1;
    xtemp = x ;
    x = G*x + tril(A)\b ;
    stop = ( norm ( xtemp - x , inf ) < tol * norm (x , inf ) ) || ( k == maxit ) ;
end
if ( k == maxit )
    error (' convergenza non raggiunta ') ;
else
    disp('Metodo Gauss-Seidel');
    disp('Approssimazione soluzione: ');
    x
    disp('Numero di iterazioni: ');
    k
end