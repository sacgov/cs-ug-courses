function A = quadrants(n)
A1 = ones(n);
A4 = ones(n);
A3 = ones(n);
A2 = ones(n);
A1(:) = 1;
A2(:) = 2;
A3(:) = 3;
A4(:) = 4;
A = [A1 A2; A3 A4];
end