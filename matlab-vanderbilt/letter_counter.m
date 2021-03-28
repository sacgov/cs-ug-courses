function ct = letter_counter(filename)
fid = fopen(filename,'rt');
ct =0;
if fid < 0
    ct = -1;
else
oneline = fgets(fid);
while 2>1
    for i = 1:length(oneline)
        if(isletter(oneline(i)))
            ct = ct + 1;
        end
    end
    oneline = fgets(fid);
    if(~ischar(oneline))
        break;
    end
end
fclose(fid);
end
