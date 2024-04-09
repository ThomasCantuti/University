function [x, it] = secanti(fname, x0, x1, tolx, tolf, maxit)
% Metodo delle secanti
it = 0;
if ( abs(x1 - x0) < tolx ), x = (x0 + x1) / 2; return; end
fx0 = feval(fname, x0); if ( abs(fx0) < tolf ), x = x0; return; end
fx1 = feval(fname, x1); if ( abs(fx1) < tolf ), x = x1; return; end
stop = 0;
while ( ~stop )
    it = it + 1;
    t = fx0 / fx1;
    d = (x1 - x0) / (1 - t);
    x = x1 - d;
    fx = feval(fname, x);
    stop = ( (abs(fx) < tolf && abs(d) < tolx + eps*abs(x1)) ...
           || fx == 0 || it == maxit );
    fx0 = fx1;
    fx1 = fx;
    x0 = x1;
    x1 = x;
end
if ( it >= maxit )
    fprintf('\nRaggiunto il massimo numero di iterazioni.\n');
end