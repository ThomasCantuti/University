% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 3
% ---------------

close all
clear all
clc

disp('Esercizio 3');

A = [2 0 0 1; -1 0.5 0 0; 3/10 0 3/5 0; -3 1/5 -1/10 1/2];
b = [0 -2 -1 0]';
[L, R, p, deter] = gauss2(A);
x = utrisol(R, ltrisol(L, b(p)));
P = eye(4); P = P(p, :);
x1 = A \ b;
fprintf('Differenza tra x e x1: %e\n', abs( x - x1 ));
disp('Soluzione: ');
x
fprintf('Residuo normalizzato: %e\n', norm(b-A*x, 'inf')/norm(b, 'inf'));


B = A*A';
[Lchol, flag] = chol(B, 'lower');
if(~flag)
    disp('B e'' definita positiva');
    c = [8/3 -1/5 3/10 -9/5]';
    xchol = utrisol(Lchol', ltrisol( Lchol, c ))
else
    disp('B non e'' definita positiva');
end
