function [x , k ] = jacobi (A , b , x , maxit , tol )
% JACOBI - Metodo iterativo di Jacobi per sistemi lineari .
% Calcola un ’ approssimazione della soluzione del sistema lineare Ax = b
% mediante il metodo iterativo di Jacobi . Per sistemi sparsi e non .
% SYNOPSIS
% [x, k] = jacobi (A, b, x, maxit , tol )
% INPUT
% A ( double array ) - Matrice dei coefficienti del sistema ,
% quadrata , a diagonale non nulla .
% b ( double array ) - Vettore dei termini noti .
% x ( double array ) - In ingresso : vettore iterato iniziale .
% maxit ( integer , positive ) - Numero massimo di iterazioni consentite
% tol ( double , positive ) - Tolleranza verso zero ( soglia di
% trascurabilita ’).
% OUTPUT
% x ( double array ) - In uscita : vettore di approssimazione
% della soluzione del sistema lineare .
%
[m , n ] = size ( A ) ;
if ( m ~= n )
    error ('La matrice dei coefficienti deve essere quadrata ') ;
end
if ( issparse ( A ) )
    d = spdiags (A , 0) ;
else
    d = diag ( A ) ;
end
if ( any( abs ( d ) < eps * norm (d , inf ) ) )
    error ('Almeno un elemento diagonale numericamente troppo piccolo ') ;
end
b = b ./ d ;
k = 0; stop = 0;
while ( ~ stop )
    k = k + 1;
    xtemp = x ;
    x = x - ( A * x ) ./ d + b ;
    stop = ( norm ( xtemp - x , inf ) < tol * norm (x , inf ) ) || ( k == maxit ) ;
end
if ( k == maxit )
    error (' convergenza non raggiunta ') ;
end
end % fine della function jacobi