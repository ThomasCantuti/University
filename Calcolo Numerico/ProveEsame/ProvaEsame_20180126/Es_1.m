% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 1
% ---------------

close all
clear all
clc

disp('Esercizio 1');

p = [3 -9 0 11 -pi 0 -2]';
x0 = input('Inserire un punto prefissato: ');

[r1, q1] = ruffiniHorner(p, x0);
[r2, q2] = ruffiniHorner(q1, x0);
[r3, q3] = ruffiniHorner(q2, x0);

fprintf('Valore di p(x) in x0: %g\n', r1);
fprintf('Valore di p''(x) in x0: %g\n', r2);
fprintf('Valore di p''''(x) in x0: %g\n', r3*2);

fprintf('Differenza di p(x) con polyval: %e\n', abs(polyval(p, x0) - r1));
fprintf('Differenza di p''(x) con polyval: %e\n', abs(polyval(q1, x0) - r2));
fprintf('Differenza di p''''(x) con polyval: %e\n', abs(polyval(q2, x0) - r3));