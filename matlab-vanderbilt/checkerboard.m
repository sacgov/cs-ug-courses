function A = checkerboard(m,n)
A = zeros(m,n);
A(1:2:end,1:2:end) = 1;
A(2:2:end,2:2:end) = 1;
end

