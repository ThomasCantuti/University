function [alpha, res, r] = regressLineare(A, y)
%regressLineare - Calcola soluzione e residui del problema lineare
% INPUT
% A (double, array) - Matrice di regressione lineare
% y (double, array) - Vettore delle osservazioni
% OUTPUT
% alpha (double, array) - Vettore soluzione
% res (double) - Norma 2 del vettore residuo
% r (double, array) - Vettore residuo
    [m, n] = size(A);
    [Q, R] = qr(A);
    ytilde = Q' * y;
    alpha = R(1:n, 1:n) \ ytilde(1:n);
    r = Q * [zeros(n,1); ytilde(n+1 : m)]; % residuo: r = y - A*alpha
    res = norm(r,2)^2; % res = norm(ytilde(n+1:m),2)^2;
end