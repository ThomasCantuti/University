close all
clear all
clc

x = 0.92;
q = x * 2;
fprintf("%.1f\n", q);
for i= 1 : 7
    if(q > 1)
        q = (q - 1) * 2;
    else
        q = q * 2;
    end
    fprintf("%.1d", fix(q));
end

disp('\n');