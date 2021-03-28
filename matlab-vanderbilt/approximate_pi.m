function [pi2 k] = approximate_pi(delta)
k =0;
pi2 =0;
while(abs(pi - pi2)>delta)
    pi2 = pi2 + sqrt(12)*((-3)^-k)/(2*k +1)
    k = k +1;
end
k = k -1;