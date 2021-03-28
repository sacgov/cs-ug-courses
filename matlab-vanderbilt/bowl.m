function s = bowl(v)
s =0;
c = 0;
i =1;
e =0;
dims = size(v)

while(c<10 && e == 0)
    s1 =0;
    if(i>=dims(2))
        e = 1;
        break;
    end
    if((v(i)==10))
        if((i+2)>dims(2))
            e =1;
            break;
        end
        if(c == 9 && (i+2)~=dims(2))
            e =1;
            break;
        end
        s1 = s1+v(i)+v(i+1)+v(i+2);
        c = c+1;
        i = i+1;
    elseif(v(i)<0 || v(i+1) < 0)
        e = 1;
        break;
    elseif(v(i) + v(i+1) == 10)
            if(c == 9 && (i+2)~=dims(2))
            e =1;
            break;
            end
            s1 = s1+v(i)+v(i+1)+v(i+2);
            i = i+2;
            c = c+1;
    elseif(v(i) + v(i+1) >10)
        e = 1;
        break;
        
    else
            if(c == 9 && (i+1)~=dims(2))
            e =1;
            break;
            end
            s1 = s1+v(i)+v(i+1);
            i = i+2;
            c = c+1;
    end 
    s1
    s = s+ s1;
end
if(e == 1)
    s = -1;
end
end