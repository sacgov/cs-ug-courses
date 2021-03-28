function n = one_per_n(x)
sum =0;
n = -1;
for i = 1:10000
    sum = sum + (1/i);
    if(sum>=x)
        n = i;
        break;
    end
end