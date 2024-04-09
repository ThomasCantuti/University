function [ convertito ] = Conversione10betaFrazionario(x, base)
%CONVERSIONE - Conversione di un intero da base 10 a base beta > 1
%qualunque
%   Conversione mediante il metodo delle moltiplicazioni successive del
%   numero da base 10 a base beta
%
% SINOPSYS:
%  [ convertito ] = Conversione10betaFrazionario(x, base)
% INPUT
% x    (double)  - Numero FRAZIONARIO in base 10 da convertire
% beta (integer) - Nuova base a cui convertire il numero: 
%                  intero > 1
% OUTPUT
% Convertito (string) - Stringa contenente la rappresentazione del numero
% in base beta

p = x;
s = "0.";
d = "0123456789ABCDEF";
i = 1;
N = 3;
while ((p ~= 0) && (i < N))
r = fix(p*base); % parte_intera
p = p*base - r; % parte_frazionaria
s = strcat(s,d(r+1)); % concatenazione di stringhe
i = i+1;

convertito = s;
end

