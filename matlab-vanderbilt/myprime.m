function a = myprime(n)
a = 1;
for i = 2:n-1
    if(mod(n,i) == 0)
        a =0;
        break;
    end
end