function a = integerize(A)
m = max(A(:));
if m<2^8
    a = 'uint8';
elseif m<2^16
    a = 'uint16'
elseif m<2^32
    a = 'uint32'
elseif m<2^64
    a = 'uint64'
else
    a = 'NONE'
end