function m = May2015
k = 4;
d = ['Sun';'Mon';'Tue';'Wed';'Thu';'Fri';'Sat'];
for i = 1:31
    m(i).month = 'May';
    m(i).date = i;
    x = uint32(mod(k+i,7)+1);
    m(i).day = d(x,1:end);
    
end
    