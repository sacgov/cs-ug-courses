function a = roman(v)
if(strcmp(v, 'I'))
    a = 1;
elseif(strcmp(v, 'II'))
    a = 2;
elseif(strcmp(v, 'III'))
    a = 3;
elseif(strcmp(v, 'IV'))
    a = 4;
elseif(strcmp(v, 'V'))
    a = 5;
elseif(strcmp(v, 'VI'))
    a = 6;
elseif(strcmp(v, 'VII'))
    a = 7;
elseif(strcmp(v, 'VIII'))
    a = 8;
    
elseif(strcmp(v, 'IX'))
    a = 9;
elseif(strcmp(v, 'X'))
    a = 10;
elseif(strcmp(v, 'XI'))
    a = 11;
elseif(strcmp(v, 'XII'))
    a = 12;
elseif(strcmp(v, 'XIII'))
    a = 13;
elseif(strcmp(v, 'XIV'))
    a = 14;
elseif(strcmp(v, 'XV'))
    a = 15;
elseif(strcmp(v, 'XVI'))
    a = 16;
elseif(strcmp(v, 'XVII'))
    a = 17;
elseif(strcmp(v, 'XVIII'))
    a = 18;
elseif(strcmp(v, 'XIX'))
    a = 19;
elseif(strcmp(v, 'XX'))
    a = 20;
else
    a =0;
end
a = uint8(a);