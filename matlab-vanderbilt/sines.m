function [ s1 , s2, sums] = sines(pts,amp,n1,n2)
if(nargin == 3)
    n2 = n1*1.05;
end
if(nargin == 2)
    n2 = 105;
    n1 = 100;
end
if(nargin == 1)
    n2 = 105;
    n1 = 100;
    amp = 1;
end
if(nargin == 0)
    n2 = 105;
    n1 = 100;
    amp = 1;
    pts = 1000;
end
v1 = 0:(n1*2*pi)/(pts - 1):n1*2*pi;
v2 = 0:(n2*2*pi)/(pts - 1):n2*2*pi;
v1 = sin(v1).*(amp);
v2 = sin(v2).*(amp);
s1 = v1;
s2 = v2;
sums = s1 + s2;