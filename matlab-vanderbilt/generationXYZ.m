function A = generationXYZ(m)
if m < 1966
    A = 'O';
elseif m>=1966 && m<=1980
    A ='X';
elseif m>1980 && m <= 1999
    A = 'Y';
elseif m>2012
    A = 'K'
else
    A = 'Z'
end
