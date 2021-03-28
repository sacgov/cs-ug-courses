function a = sparse_array_in(filename)
fid = fopen(filename,'r');
if fid < 0
    error('error opening file %s\n',filename);
end
dims = fread(fid,3,'uint32');
a = zeros(dims(1) ,dims(2))
for i = 1:dims(3)
    k = fread(fid,1,'uint32');
    j = fread(fid,1,'uint32');
    l = fread(fid,1,'double');
    a(k,j) = l
end
fclose(fid);
end