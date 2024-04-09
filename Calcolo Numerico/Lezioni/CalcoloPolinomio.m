clear all;

x = linspace(0.998,1.002,50);
p = [1 -6 15 -20 15 -6 1];

y1 = (x-1).^6;
y2 = polyval(p,x);
y3 = x.^6 - 6*x.^5 + 15*x.^4-20*x.^3+15*x.^2-6*x+1;

plot(x,y1,'-*',x,y2,':+',x,y3,'--x');
legend('(x-1)^6','Horner','sviluppo');
fprintf('x\t (x-1)^6\t Horner \t sviluppo \n');
for i = 1:3:length(x)
    fprintf(['%7.4e\t %6.3e\t %6.3e\t ' ...
               '%6.3e \n'], x(i), y1(i),y2(i),y3(i));
end