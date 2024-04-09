function [y] = CalcoloNormaMatrice(A, p)
% CalcoloNormaMatrice − Calcolo della norma di una matrice (1 , di 
% Froubenius , di Turing , uniforme )
% Calcolo della norma di una matrice A nei quattro casi : 1 , Frobenius ,
% Turing , infinito
% SYNOPSIS:
% [ y ] = CalcoloNormaMatrice(A, p) (N.B.: esiste la funzione predefinita 
% 'norm')
% INPUT :
%   A ( double array )     − la matrice di cui calcolare la norma
%   p ( scalar or string ) − il tipo di norma da calcolare
%                            se p = 1 , norma 1
%                            se p = 'Fro', norma di Frobenius ( o di Schur )
%                            se p = 'Tur' , norma di Turing
%                            se p = inf , norma infinito
% OUTPUT:
%   y ( double )           − la norma calcolata
%
    if (isempty(find(A)))
        y = 0;
    else
        switch p
            case 1
            y = max(sum(abs(A))) ;
            case 'Fro'
                t = max(abs(A(:)));
                y = sqrt(sum(A(:)/t).^2) * t;
            case 'Tur'
                y = sqrt(prod(size(A))) * max(abs(A(:)));
            case inf
                y = max(sum(abs(A'))) ;
            otherwise
                error('p non valido');
        end
    end
end