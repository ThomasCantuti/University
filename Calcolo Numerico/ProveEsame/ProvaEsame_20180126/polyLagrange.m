function [p, coeff] = polyLagrange(x, y, punti)
% POLYLAGRANGE - Polinomio interpolante nella forma di Lagrange
% INPUT
% x (double array) - vettore dei nodi o punti di osservazione
% y (double array) - vettore delle osservazioni
% punti (double array) - vettore dei punti in cui calcolare il
% polinomio di Lagrange
% OUTPUT
% p (double array) - valore del polinomio nei punti
% coeff (double array) - coefficienti del polinomio di Lagrange
    if ( isempty(x) || isempty(y))
        error("dati vuoti")
    elseif (~isnumeric(x) || ~isnumeric(y) || ~isnumeric(punti))
        error("dati non numerici")
    elseif (~isvector(x) || ~isvector(y) || (numel(x) ~= numel(y)))
        error("i dati x e y devono avere le stesse dimensioni")
    end
    n1 = numel(y); coeff = zeros(size(x)); p = zeros(size(punti));
    for k = 1 : n1
        coeff(k) = y(k) / prod( x(k) - x([1:(k-1), (k+1):n1]) );
    end
    for j = 1 : numel(punti)
        ij = find( punti(j) == x );
        if isempty(ij)
            % calcolo del polinomio di Lagrange
            p(j) = prod( punti(j) - x ) * sum( coeff ./ (punti(j) - x) );
        else
            p(j) = y( ij(1) );
        end
    end
end