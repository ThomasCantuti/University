function [x , it, xk, fk] = myNewton ( fname , fpname , x0 , tolx , tolf , maxit, trace )
% NEWTON - Metodo di Newton per il calcolo di uno zero di funzione .
% Applica il metodo iterativo di Newton per determinare un ’ approssimazione
% di uno zero della funzione ’fname ’ , con derivata prima ’fpname ’ ,
% partendo dal punto iniziale x0. La function non verifica le ipotesi
% di convergenza del metodo .
% SYNOPSIS
% [x, it] = newton (fname , fpname , x0 , tolx , tolf , maxit )
% INPUT
% fname ( string o fhandle ) - Function della funzione
% fpname ( string o fhandle ) - Function della derivata prima
% x0 ( double ) - Stima iniziale
% tolx ( double ) - Distanza minima fra iterati successivi
% tolf ( double ) - Soglia verso zero dei valori di f(x)
% maxit ( integer ) - Numero massimo di interazioni
% OUTPUT
% x ( double ) - Approssimazione della soluzione
% it ( integer ) - Numero di iterazioni eseguite
%
tolfp = min( tolf , 10* eps ) ;
xk = zeros(maxit, 1);
fk = zeros(maxit, 1);
% Metodo di Newton
x = x0 ; fx = feval ( fname , x ) ; it = 0;
stop = ( abs ( fx ) < tolf ) ;
while ( ~ stop )
    it = it + 1;
    fpx = feval ( fpname , x ) ;
    if ( abs( fpx ) < tolfp ) , error ('|f''(xk)| troppo piccolo .') ; end
    d = fx / fpx ; x = x - d ; fx = feval ( fname , x ) ;
    stop = ( (abs ( fx ) < tolf && abs ( d ) < tolx * abs ( x )) ...
    || ( fx == 0) || ( it == maxit ) ) ;
    if(trace ~= 0)
        xk(it) = x;
        fk(it) = fx;
    end
end
if ( it >= maxit )
    fprintf ('\ nRaggiunto il massimo numero di iterazioni .\n') ;
end
end % fine della function newton