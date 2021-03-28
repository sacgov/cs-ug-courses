function a = sparse_array_out(b,filename)
fid = fopen(filename,'w+');
a = false;
if fid < 0
    a = false;
end
dims = uint32(size(b));
z = b(b~=0)
q = size(z(:));
dims = uint32([dims q(1)]);
dims
fwrite(fid,dims,'uint32');
for i = uint32(1:dims(1))
    for j = uint32(1:dims(2))
        if(b(i,j)~=0)
            i
            j
            b(i,j)
            fwrite(fid,i,'uint32');
            fwrite(fid,j,'uint32');
            fwrite(fid,b(i,j),'double');
        end
    end
end
fclose(fid);
a = true;
            
    
