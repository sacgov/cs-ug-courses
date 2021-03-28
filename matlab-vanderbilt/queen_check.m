function a = queen_check(m)
a = 1;
m
dim = size(m);
for i = 1:dim(1)
    r1 = m(i,1:end);
    if(sum(r1) > 1)
        a =0
        break
    end
end
if(a == 1)
    for i = 1:dim(1)
        r1 = m(1:end,i);
        if(sum(r1) > 1)
            a =0
        break
        end
    end
end
if(a == 1)
    for i = 1:dim(1)
        r1 = m(end-i+1:end,1:i)
        r1 = diag(r1);
        if(sum(r1)>1)
            a = 0
            break
        end
    end
end
if(a == 1)
    for i = 1:dim(1)
        r1 = m(1:i,end-i+1:end)
        r1 = diag(r1);
        if(sum(r1)>1)
            a = 0
            break
        end
    end
end
m = m(end:-1:1,1:end)
if(a == 1)
    for i = 1:dim(1)
        r1 = m(end-i+1:end,1:i)
        r1 = diag(r1)
        if(sum(r1)>1)
            a = 0
            break
        end
    end
end
if(a == 1)
    for i = 1:dim(1)
        r1 = m(1:i,end-i+1:end)
        r1 = diag(r1);
        if(sum(r1)>1)
            a = 0
            break
        end
    end
end   