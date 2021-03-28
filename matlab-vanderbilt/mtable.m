function [A,s] = mtable(m,n)
A = ones(m,n);
for a = 1:m
    for b = 1:n
        A(a,b) = a*b;
    end
end
s = sum(A(:));
end