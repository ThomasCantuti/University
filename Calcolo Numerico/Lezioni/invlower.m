function [L] = invlower(L)
% INVLOWER - Sovrascrive una matrice triang. sup. invert. con la propria
% inversa
% SYNOPSIS:
% [L] = invlower(L)
% INPUT:
% L (double array) - Matrice triangolare inferiore da invertire
% OUTPUT:
% L (double array) - La matrice in input sovrascritta con la propria inversa
n = size(L);
if (any(abs(~diag(L))))
    warning('Elementi molto piccoli nella diag di L');
end
if ( isempty(find(~diag(L))) )
    L(n,n) = 1 ./ L(n,n);
    for i = 2 : n
        L(i,i) = 1 / L(i,i);
        for j = 1 : i - 1
            L(i,j) = -( L(i, j:i-1)*L(j:i-1, j) )*L(i,i);
        end
    end
else
    error('la matrice e'' singolare');
end
end