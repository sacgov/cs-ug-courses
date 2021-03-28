function a = mean_squares(m)
v = 1:m;
v = v.^2;
v = sum(v);
a = v/m;
end
