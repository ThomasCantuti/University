% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 3
% ---------------

close all
clear all
clc

disp('Esercizio 3');

A = [1 -2 2 0; ...
     -3 2 0 4; ...
     0 -5 1 -2; ...
     0 0 2 1];

b = [0 -2 1 0]';

[L, R, p, deter] = gauss2(A)
x = solupper(R, sollower(L, b(p)))
rn = (b - A*x) / norm(b, 'inf');
fprintf('Residuo normalizzato = %e\n', rn);

% Cholesky
B = A'*A;
[Lchol, p] = chol(B, 'lower');
if (~p)
    disp('B e'' definita positiva');
else
    disp('B non e'' definita positiva')
end

c = [7/3 1 2 -5/6]';
x1 = solupper(Lchol', sollower(Lchol, c))