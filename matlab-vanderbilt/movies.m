function a = movies(h1,m1,d1,h2,m2,d2)
off1 = h1*60 + m1 + d1;
off2 = h2*60 + m2;
diff = off2 - off1;
if (diff<0)
    a = 0;
elseif diff > 30
    a = 0;
else
    a = 1;
end