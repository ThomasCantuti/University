% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 1
% ---------------

close all
clear all
clc

disp('Esercizio 1');

p = zeros(7, 1);
p(1) = log10(pi^(7/4)*max(exp(2) - 5, tan(0.5)));
p(2) = cos(nthroot(abs(-0.7*exp(-0.2)), 3));
p(4) = -sin(0.2 + exp(-1.6));
p(6) = acos(3.7*1e-1) + 1/4;
p(7) = log(sqrt(pi^3) + 2/3);

prompt = 'Inserire un numero x0 in input: ';
x0 = input(prompt);

[r1, q1] = ruffiniHorner(p, x0);
[r2, q2] = ruffiniHorner(q1, x0);
[r3, q3] = ruffiniHorner(q2, x0);

fprintf('Valore di p(x) in x0 = %e\n', r1);
fprintf('Valore di p''(x) in x0 = %e\n', r2);
fprintf('Valore di p''''(x) in x0 = %e\n', 2*r3);

a = -1.5; b = 1.3;
xx = linspace(a, b);
plot(xx, polyval(p, xx));