function c = pitty(ab)
ab = ab.^2;
c = ab(:,1)+ab(:,2);
c = c.^0.5;
end