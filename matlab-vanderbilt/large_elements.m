function a = large_elements(M)
s = size(M);
k =[];
for i = 1:s(1)
    for j = 1:s(2)
        if((i+j)<M(i,j))
            b = [i j];
            if(isempty(k))
                k = b;
            else
                k = [k;b];
            end
        end
    end
end
a =k;
