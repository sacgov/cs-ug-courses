function txt = codeit(txt)
txt = uint16(txt)
for i = 1:length(txt)
    if(txt(i)>=97 && txt(i)<= 122)
        txt(i) = txt(i) - 97;
    if(txt(i)<13)
        txt(i) = 25 - txt(i);
    else
        txt(i) = 12 - (mod(txt(i),13));
    end
    txt(i) = txt(i) + 97;
    elseif ( txt(i)>=65 && txt(i) <= 90)
        txt(i) = txt(i) - 65;
            if(txt(i)<13)
        txt(i) = 25 - txt(i);
    else
        txt(i) = 12 - (mod(txt(i),13));
    end
    txt(i) = txt(i) + 65;
    end    
end
txt = char(txt);