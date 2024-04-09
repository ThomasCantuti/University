% Cantuti Thomas
% 187390

% -------------
%  Esercizio 6
% -------------

close all
clear all
clc

disp('Esercizio 6');

f = @(x) tan(1-x)-2/3;
fprimo = @(x)-tan(x-1)^2-1;
a = 2.7; b = 4;
x0 = 2.8;
tolx = 1e-5;
tolf = 1e-7;
maxit = 10;
trace = 1;

[x , it, xk, fk] = myNewton ( f , fprimo , x0 , tolx , tolf , maxit, trace );

xx = linspace(a, b);
plot(xx, f(xx), 'b-', ...
    xx, zeros(size(xx)), 'k', ...
    xk, zeros(size(xk)), 'ko', ...
    xk, fk, 'ro');

xlabel('x'), ylabel('y'), title('Grafico con metodo di Newton');