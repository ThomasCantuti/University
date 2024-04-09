% Cantuti Thomas
% 187390

% -------------
%  esercizio 3
% -------------

disp('Esercizio 3');

close all
clear all
clc

A = [1 3 -1; 1 2 1/2; 5 10 -1];
b = [-2 1/2 -1]';

% controllo calcoli
[L, R, p, deter] = gauss2(A);
% soluzione
x1 = solupper(R, sollower(L, b(p)))
% matrice P = Pn * Pn-1 * Pn-2 * ...
P = eye(3); P = P(p, :);
% se norma residuo normalizzato -> norma a num e den
% se residuo normalizzato -> norma a den
% norma residuo normalizzato
fprintf('\nNorma residuo normalizzato = %g\n\n', ...
    norm(b - A*x1, inf) / norm(b, inf));

% confronto fattori ottenuti con quelli dati da lu(A)
[L1, R1, P1] = lu(A);
disp('[L1, U1, P1] = lu(A)');
fprintf('max( | L - L1 | ) = %g\n', max(abs(L(:) - L1(:))));
fprintf('max( | R - R1 | ) = %g\n', max(abs(R(:) - R1(:))));
fprintf('max( | P - P1 | ) = %g\n', max(abs(P(:) - P1(:))));

% seconda parte
n = 30;
x = zeros(n, 1);
for k = 1 : n
    bk = [-2 2^(-k) -1]';
    % [Lk, Rk, pk] = gauss2(A);  -> non serve
    x(k) = norm(R \ (L\bk(p)), inf);
end
plot(x, 'bo');

% altro modo per risolvere in una riga
%n = 30;
%normInfSol = zeros (n ,1) ; normInfSol (1) = norm ( x1 , inf ) ;
%for k = 2 : n
%    b = [ -2 2^( - k ) -1]';
%    normInfSol ( k ) = norm ( R \ ( L \ b ( p ) ) , inf ) ;
%end
%plot ( normInfSol ,'bo') ;