function n = roman2( num )
fid = fopen('r.txt','rt');
if fid < 0
    error('error opening file %s\n', filename);
end
n = 0;
% Read file as a set of strings, one string per line:
for i =1:399
    oneline = fgets(fid);
    
    
    if(check(oneline,num))
        n = i;
        break;
    %fprintf('%s%s\n',oneline,num);
    %fprintf('%d%d\n',length(oneline),length(num));
    end
     % display one line
end
fclose(fid);
n = uint16(n);

function a = check(o,n1)
a = 1;
for i = 1:length(n1)
 if(n1(i)~=o(i))
     a =0;
     break;
 end
end