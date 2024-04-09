function [ Ainv ] = gaussJordan(A)
%GAUSSJORDAN - Algoritmo di Gauss-Jordan per il calcolo dell’inversa
    n = size(A, 1); % matrice quadrata
    A = [A eye(n)];
    for k = 1 : n
        [~, ind] = max( abs(A(k:n, k)) ); % serve solo l’indice, non il valore
        ind = ind(1) + k - 1; % prende solo il primo elemento con modulo massimo
        if (k ~= ind)
            % scambio di righe
            A( [k,ind], : ) = A( [ind,k], : );
        end
        % calcolo e memorizzazione dei moltiplicatori
        A( [1:(k-1), (k+1):n], k ) = A( [1:(k-1), (k+1):n], k ) / A(k,k);
        % operazione di base: aggiornamento mediante diade
        A( [1:(k-1), (k+1):n], (k+1):(2*n) ) = ...
            A( [1:(k-1), (k+1):n], (k+1):(2*n) ) - ...
            A( [1:(k-1), (k+1):n], k ) * A(k, (k+1):(2*n) );
    
    end
    Ainv = diag( 1.0 ./ diag(A(:, 1:n)) ) * A( :, (n+1):(2*n) );
end