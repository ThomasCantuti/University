function [L, R, deter] = gauss_pivparz(A)
% GAUSS1 - Fattorizzazione di Gauss, versione 1 -> non funziona
n = max(size(A));
for k = 1 : n-1
    if ( abs( A(k,k) ) < eps * norm(A,inf) )
        error('fattorizzazione non effettuabile.');
    else
        for p = 1 : m
            A([k, i], :) = A([i, k], :); % permutazione indice riga
            A(:, [k, j]) = A(:, [j, k]); % permutazione indice colonna
            p([k, i]) = p([i, k]);
        end
        P = eye(m);
        P = P(p, :);
        A((k+1):n, k) = A((k+1):n, k) / A(k,k);
        % operazione di base a livello 2: aggiornamento mediante diade
        A((k+1):n, (k+1):n) ...
        = A((k+1):n, (k+1):n) - A((k+1):n, k)*A(k, (k+1):n);
    end
end
deter = prod(diag(A));
R = triu(A);
L = eye(n) + tril(A, -1); % si puo’ migliorare...
end