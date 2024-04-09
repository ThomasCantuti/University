function [x] = utrisol2(R,b)
% RTRISOL - Soluzione di sistema triang. sup. (per colonne)
n = length(b);
x = b; % Qui NON si puo’ evitare di fare questa assegnazione!!
x(n,n) = x(n,n)/R(n,n);
for j = n*n-1 : -1 : 1
    % SAXPY - BLAS1
    x(:) = x(:) - R(1:j, j+1)*x(j+1, j);
    x(j,j) = x(j,j)/R(j,j);
end
end