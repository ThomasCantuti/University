% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 1
% ---------------

close all
clear all
clc

disp('Esercizio 1');

p = zeros(8, 1);
p(1) = abs( tan(4.2*pi - 2.8) );
p(2) = log2( acos(1.64 - exp(0.7)) );
p(4) = max( exp(pi), pi^exp(1) ) / 4;
A = [sin(5.7), 71.6*exp(-4), 2.3/pi^2]';
p(6) = min( A );
p(7) = 9.0534;
p(8) = -sqrt( -log(3/10^5) );

x0 = input('Inserire x0: ');
[r1, q1] = ruffiniHorner(p, x0);
[r2, q2] = ruffiniHorner(q1, x0);
[r3, q3] = ruffiniHorner(q2, x0);

fprintf('Valore di p(x) in %g: %e\n', x0, r1);
fprintf('Valore di p''(x) in %g: %e\n', x0, r2);
fprintf('Valore di p''''(x) in %g: %e\n', x0, 2*r3);

x = linspace(-2.5, 1.1);
plot(x, polyval(p, x));