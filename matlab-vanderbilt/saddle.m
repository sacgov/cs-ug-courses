function a = saddle(m)
dim = size(m)
a = [0 0];
for j = 1:dim(2)
    for i = 1: dim(1)
        q = m(i,j);
        if(max(m(i,1:end)) == q && min(m(1:end,j))==q)
            a = [a;[i j]];
        end
    end
end
a = a(2:end,1:end);
            
            