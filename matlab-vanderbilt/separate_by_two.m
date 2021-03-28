function [v2 v1] = separate_by_two(M)
v1 = M(mod(M,2)==1)
v2 = M(mod(M,2)==0)
v1 = v1'
v2 = v2'
end