function c = censor(s,s1)
f = zeros(1,size(s(:)));
for i = 1:length(s)
    if(isempty(strfind(s{i},s1)))
        f(i) = 1;
    end
end
c = s(logical(f));