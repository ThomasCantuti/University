% Cantuti Thomas
% 187390

close all
clear all
clc

% ------------------
%  esercizio 1
% ------------------

% p(x) = 3*x^6 - 9*x^5 + 11*x^3 - pi*x^2 - 2
p = [3, -9, 0, 11, -pi, 0, -2];

prompt = ['Inserire il punto (numero reale) nel quale valutare il polinomio:' ...
    'x0 = '];
x0 = input(prompt);

[r1, q1] = ruffiniHorner(p, x0);
[r2, q2] = ruffiniHorner(q1, x0);
[r3, q3] = ruffiniHorner(2*q2, x0);

fprintf('Valore del polinomio in x0: p(x0) = %f\n', r1);
fprintf('Valore della derivata prima in x0: p,(x0) = %f\n', r2);
fprintf('Valore della derivata seconda in x0: p ,(x0) = %f\n', r3);

% verifica con polyval(p, x0)
% pk(x0) = k! * qk --> k = passo