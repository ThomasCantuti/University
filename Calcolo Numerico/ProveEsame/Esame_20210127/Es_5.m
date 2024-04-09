% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 5
% ---------------

close all
clear all
clc

disp('Esercizio 5');

a = -4.5; b = -2.5;
n = input('Inserire un numero di punti >= 5: ');
while( n < 5)
    n = input('Inserire un numero di punti >= 5: ');
end
x = linspace(a, b, n)';

f = @(x)cos(x).*(log(x+5)-1);
y = f(x);

A = [x.^2 x ones(size(x))];
B = A'*A; c = A'*y; % Bx = c
q2 = B \ c; % x = B^(-1)*c

q2check = polyfit(x, y, 2)';
fprintf("Differenza tra i coefficienti: %e\n", norm(q2 - q2check, inf));
fprintf('Coefficienti di q2(x):\n');
disp(q2);

xx = linspace(a, b, 201);
yy = f(xx); % coefficienti funzione
yy1 = polyval(q2, xx); % coefficienti polinomio

plot(xx, yy, 'b-', ...
     x, y, 'ko', ...
     xx, yy1, 'r-');

xlabel('valori di x in [-4.5, -2.5]');
ylabel('Osservazioni di funzione, punti, polinomio');
legend('f(x)', '(xj, yj)', 'q2(x)');