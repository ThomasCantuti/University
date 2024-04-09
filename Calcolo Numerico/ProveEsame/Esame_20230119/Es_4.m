% Cantuti Thomas
% 187390

% ---------------
%   Esercizio 4
% ---------------

close all
clear all
clc

disp('Esercizio 4');

A = [8/3 -1 1/2; 2/5 7/3 1/2; 3/5 -1/3 4];
Dinv = diag( 1./diag(A) );
J = - Dinv \ (triu(A, 1) + tril(A, -1))
G = - tril(A) \ triu(A, 1)