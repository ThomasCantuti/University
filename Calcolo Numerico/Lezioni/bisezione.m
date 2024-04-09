function [c, fc, it] = bisezione(fname, a, b, tol)
%bisezione - Metodo di bisezione per equazioni non lineari scalari
% Descrizione dettagliata
%
% INPUT: fname (string/fhandle) - Function o function handle che calacola la funzione
%        a, b (double) - Estremi dell’intervallo
%        tol (double) - Tolleranza di approssimazione della soluzione
% OUTPUT: c (double) - Approssimazione della soluzione
%         fc (double) - Valore della funzione nell approssimazione della soluzione
%         it (integer) - Numero di iterazioni eseguite
    maxit = ceil( log2( (b - a)/tol ) ); it = 0;
    fprintf('\nNumero massimo di passi necessari = %d\n', maxit);
    fa = feval(fname, a); fb = feval(fname, b);
    if ( sign(fa)*sign(fb) > 0 ), error('Intervallo non corretto');
    elseif (fa == 0), c = a; fc = fa; return; % (fa == 0) e (~fa) sono uguali
    elseif (fb == 0), c = b; fc = fb; return;
    else
        % Metodo di bisezione
        soglia = tol + eps*max( abs([a; b]) ); arresto = 0;
        while ( ~arresto )
            it = it + 1; c = a + (b - a)*0.5;
            fprintf('\n\tit = %d \tc = %g', it, c); % questa riga serve solo per la visualizz.
            fc = feval(fname, c);
            if ( fc == 0 ), break; end
            if ( sign(fc)*sign(fa) > 0 )
                a = c; fa = fc;
            else
                b = c; fb = fc;
            end
            arresto = ( abs(b - a) < soglia ) || ( it == maxit );
        end
    end
    fprintf('\n\n');
end