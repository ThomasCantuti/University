function [z, d] = polyNewton(x, y, xx)
% POLYNEWTON - Valuta in xx il polinomio di Newton su (x, y)
    n = length(x);
    d = tabDiff(x,y);
    z = d(n)*ones(size(xx));
    for i = n-1 : -1 : 1
        z = z .* (xx - x(i)) + d(i);
    end
end