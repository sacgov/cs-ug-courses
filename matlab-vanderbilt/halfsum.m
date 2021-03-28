function a = halfsum(M)
s = size(M);
k =0;
for i = 1:s(1)
    for j = 1:s(2)
        if(i<=j)
            k = k+M(i,j);
        end
    end
end
a =k;
