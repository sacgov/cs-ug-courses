function [vt,vk] = light_time(v)
vk = v.*1.609
vt = vk./300000
vt = vt./60
end