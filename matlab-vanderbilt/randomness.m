function A = randomness(limit,m,n)
A = 1 + (limit).*rand(m,n);
A  = floor(A);
hist(A);
end