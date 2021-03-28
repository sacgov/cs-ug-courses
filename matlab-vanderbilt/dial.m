function a = dial(p)
for i = 1:length(p)
    if(p(i) == 'A' || p(i) == 'B' || p(i) == 'C')
        p(i) = '2';
    elseif(p(i) == 'D' || p(i) == 'E' || p(i) == 'F')
        p(i) = '3';
    elseif(p(i) == 'G' || p(i) == 'H' || p(i) == 'I')
        p(i) = '4';
    elseif(p(i) == 'J' || p(i) == 'K' || p(i) == 'L')
        p(i) = '5';
    elseif(p(i) == 'M' || p(i) == 'N' || p(i) == 'O')
        p(i) = '6';
    elseif(p(i) == 'P' || p(i) == 'R' || p(i) == 'S')
        p(i) = '7';
    elseif(p(i) == 'T' || p(i) == 'U' || p(i) == 'V')
        p(i) = '8';
    elseif(p(i) == 'X' || p(i) == 'Y' || p(i) == 'W')
        p(i) = '9';
    elseif(p(i) == '(' || p(i) == ')' || p(i) == '-' )
        p(i) = ' ';
    elseif(p(i) == 'Q' || p(i) == 'Z' || p(i) == '!')
        p = [];
        break;
    elseif((uint8(p(i))- 48)>9 || (uint8(p(i))- 48)<0)
        p =[];
        break;
    end
end
    a =p;