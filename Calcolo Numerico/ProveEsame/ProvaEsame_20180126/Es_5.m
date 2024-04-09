% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 5
% ---------------

close all
clear all
clc

disp('Esercizio 5');

N = 10;
f = @(x) ( exp(-7*(x-3).^2) )/3;
figure(1);
a = 1; b = 5;
xx = linspace(a, b, 201)';
yy = f(xx);

pause
for n = 1 : N
    x = linspace(a, b, n+1)';
    y = f(x);
    [zz] = polyLagrange(x, y, xx);
    plot(xx, yy, 'b', ...                  % funzione
         xx, zz, 'r', ...                  % polinomio interp.
         xx, zeros(size(xx)), 'k', ...     % asse y = 0
         x, zeros(size(x)), 'ko', ...      % nodi di interpolazione
         x, y, 'ro');                      % valori del polinomio nei nodi
    pause(2);
end