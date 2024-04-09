% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 3
% ---------------

close all
clear all
clc

disp('Esercizio 3');

A = [1 3 -1; 1 2 1/2; 5 10 -1];
b = [-2 1/2 -1]';

[L, R, p, deter] = gauss2(A);
disp('Soluzione: ');
x = solupper(R, sollower(L, b(p)))

nrn = norm(b - A*x, 'inf')/norm(b, 'inf');
fprintf('Norma del residuo normalizzato = %e\n', nrn);

[L1, R1, P1] = lu(A);
fprintf('Differenza matrici trang. sup: \n');
abs(R - R1)
fprintf('Differenza matrici trang. inf: \n');
abs(L - L1)
fprintf('Differenza matrici permutazione: \n');
abs(P1 - P1)

n = 30;
xk = zeros(n, 1);
for k = 1 : n
    bk = [-2 2^-k -1]';
    xk(k) = norm( R \ (L \ bk(p)), 'inf' );
end

plot(xk, 'bo');