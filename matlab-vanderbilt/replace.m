function c = replace(c , c1,c2 )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
for i = 1:length(c(:))
    for k = 1:length(c{i})
        if(c{i}(k) == c1)
            c{i}(k) = c2
        end
    end
end


end

