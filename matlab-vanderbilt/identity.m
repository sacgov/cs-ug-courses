function A = identity(m)
A = zeros(m);
for a = 1:m
    A(a,a) = 1;
end
end
