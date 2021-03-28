function m = June2015
k = 0;
d = ['Sun';'Mon';'Tue';'Wed';'Thu';'Fri';'Sat'];
m = cell(30,3);
for i = 1:30
    m{i,1}= 'June';
    m{i,2} =i;
    m{i,3} = d(mod(k+i,7)+1,1:end);
    
end

    