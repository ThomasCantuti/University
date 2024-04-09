function [ y ] = CalcoloNormaVettore ( x , p )
% CalcoloNormaVettore − Calcolo della norma di un vettore (1 , 2 o uniforme )
% Calcolo della norma di un vettore x nei 3 casi p = 1 , 2 , infinito
% (N.B. : esiste la funzione predefinita 'norm' )
% SYNOPSIS:
% [ y ] = CalcoloNormaVettore ( x , p )
% INPUT :
% x ( double array ) − il vettore di cui calcolare la norma
% p ( scalar ) − il tipo di norma da calcolare
%                se p = 1 , norma 1
%                se p = 2 , norma 2
%                se p = inf, norma infinito
% OUTPUT:
% y ( double ) − la norma calcolata
%

    if (isempty(find(x)))
        y = 0;
    else
        switch p
            case 1
                y = sum( abs ( x ) ) ;
            case 2
                t = max( abs ( x ) ) ;
                y = sqrt(sum((x/t).^2))*t;
            case inf
                y = max( abs ( x ) ) ;
            otherwise
                error('p non valido');
        end
    end
end