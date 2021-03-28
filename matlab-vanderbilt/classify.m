function A = classify(m)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
s = size(m);
if(s(1,1)>1 && s(1,2)>1)
    A = 2;
elseif s(1,1) == 1 && s(1,2) == 1
    A = 0;
elseif s(1,1) == 0 || s(1,2) == 0
    A = -1;
else 
    A = 1;
end