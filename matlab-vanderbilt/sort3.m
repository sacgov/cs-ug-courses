function v = sort3(m,n,k)
if(m>=n)
    if(m>=k)
        c =m;
        if(k>=n)
            b = k;
            a = n;
        else
            a = k;
            b = n;
        end
    else
        c = k;
        a = n;
        b = m;
    end
else
        if(n>=k)
        c =n;
        if(k>=m)
            b = k;
            a = m;
        else
            a = k;
            b = m;
        end
    else
        c = k;
        a = m;
        b = n;
    end
    
end
v = [a b c]
    