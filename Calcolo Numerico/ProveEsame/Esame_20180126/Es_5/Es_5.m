% Cantuti Thomas
% 187390

% --------------
%  esercizio 5
% --------------

close all
clear all
clc

disp('Esercizio 5');

f = @(x)( 1/3 * exp( -7 * (x - 3).^2 ) );
a = 1; b = 5;
xx = linspace(a, b, 201);
yy = f(xx);
fig1 = figure(1);
pause
N = 10;
for n = 1 : N
    x = linspace(a, b, n + 1)';
    y = f(x);
    [zz] = polyLagrange(x, y, xx);
    plot([xx(1); xx(end)], [0;0], 'k-', ...  % asse ascisse
          xx, yy, 'b-', ...                  % grafico funzione
          xx, zz, 'r-', ...                  % grafico del polinomio interpolante
          x, zeros(size(x)), 'ko', ...       % nodi di interpolazione
          x, y, 'ro');                       % valori del polinomio nei nodi
    th = title ( sprintf ('Funzione e polinomio interpolante di grado %d', n) ) ;
    set ( th ,'FontSize' ,16 ) ;
    xlabel ('Intervallo di interpolazione ') ;
    ylabel ('Valori di f(x) e p_n(x)') ;
    pause(2)
end