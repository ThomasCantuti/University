function [L, R, P, Q, deter] = gauss_pivtot(A)
% GAUSS2 - Fattorizzazione di Gauss con pivoting parziale (versione 2)
[m, n] = size(A);
deter = 1;
temp = zeros(1, n);
temp1 = zeros(m, 1);
P = 1 : n;
Q = 1 : m;
tol = eps * norm(A, inf); % tolleranza verso lo zero (trascurabilita’)
for j = 1 : min(m-1,n)
    [amax, ind] = max( abs(A(j : m, j : n)) );
    [~, colind] = max(amax);
    ind = ind + j - 1;
    col = colind + j - 1;
    if (ind ~= j) % pivot non in posizione diagonale: occorre scambiare righe
        % scambio di indici
        aux = P(j); 
        P(j) = P(ind); 
        P(ind) = aux;
        deter = -deter;
        % scambio di righe
        temp = A(ind,:); 
        A(ind,:) = A(j,:); 
        A(j,:) = temp;
    end
    % scambio di colonne
    if (col ~= j)
        temp1 = A(:, j);
        A(:, j) = A(:, indcol);
        A(:, indcol) = temp1;
        
    end
    deter = deter * A(j,j);
    if ( abs(A(j,j)) > tol )
        A(j+1:end, j) = A(j+1:end, j) / A(j,j);
        % operazione di base: aggiornamento mediante diadi
        A(j+1:end, j+1:end) = A(j+1:end, j+1:end) - A(j+1:end, j)*A(j, j+1:end);
    end
end
deter = deter * A(n,n);
R = triu(A);
L = eye(n) + tril(A(1:n,1:n), -1);
end