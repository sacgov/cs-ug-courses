function av = moving_average(i)
persistent v;
persistent c;
if(isempty(c))
    c = 0
end
if(isempty(v))
    v= zeros(1,25);
end
persistent in;
if(isempty(in))
    in = 1;
end
v(1,in) = i;
if(c == 0)
    av = sum(v(:))/in;
else
av = mean(v);
end
if(in == 25)
    c =1;
end
in = mod(in,25)+1;
end
    