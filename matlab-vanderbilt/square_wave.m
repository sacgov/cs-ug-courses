function v = square_wave(n)
v = zeros(1,1001);
for i = 1:1000
    sum =0;
    t = pi*4*(i/1000);
    for k = 1:n
        sum = sum + sin((2*k - 1)*t)/(2*k -1);
    end
    v(i+1) = sum;
end