function [row,col,nr,nc,s] = maxsubsum(A)
dim = size(A);
s = -1;
for i = 1:dim(1)
    for j = 1:dim(1)
        for k = 1:dim(2)
            for l = 1:dim(2)
                if(i<=j && k<=l)
                    [i j k l]
                    x = A(i:j,k:l)
                    d = sum(x(:))
                    if(s<d)
                        row = i;
                        col = k;
                        nr  = j-i+1;
                        nc  = l - k+ 1;
                        s = d
                    end
                end
            end
        end
    end
end
end