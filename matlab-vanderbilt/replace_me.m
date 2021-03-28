function x = replace_me(v,a,b,c)
x = [];
if(nargin == 3)
    c = b;
end
if(nargin == 2)
    b= 0;
    c =0;
end
w = [b c];
for i = 1:length(v)
    if(v(i) == a)
        x = [x w];
    else
        x = [x v(i)];
    end
end
    