function w = neighbor(v)
w =[];
if(isvector(v))
for i = 1:length(v)-1
    w = [w -v(i)+v(i+1)];
    w = abs(w);
end
end
    