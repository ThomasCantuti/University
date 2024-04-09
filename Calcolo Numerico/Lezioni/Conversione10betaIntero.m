function [convertito] = Conversione10betaIntero(x, base)
%CONVERSIONE - Conversione di un intero da base 10 a base beta > 1
%qualunque
%   Conversione mediante il metodo delle divisioni successive del numero da
%   base 10 a base beta
%
% SINOPSYS:
%  [ convertito ] = Converisone10betaIntero(x, base)
% INPUT
% x    (double)  - Numero INTERO in base 10 da convertire
% beta (integer) - Nuova base a cui convertire il numero: 
%                  intero > 1
% OUTPUT
% Convertito (string) - Stringa contenente la rappresentazione del numero
% in base beta

q = x;
s = "";
d = "0123456789ABCDEF";
while (q ~= 0)
    r = q - fix(q/base)*base; % resto della divisione intera
    q = fix(q/base); % divisione intera
    s = strcat(d(r+1),s); % concatenazione di stringhe
end
convertito = s;