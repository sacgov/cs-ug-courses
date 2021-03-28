function b = divvy(a,k)
b = a;
b(mod(b,k)~=0)= b(mod(b,k)~=0)*k;
