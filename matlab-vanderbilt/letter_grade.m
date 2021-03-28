function A = letter_grade(m)
if m < 61
    A = 'F';
elseif m>=61 && m<=70
    A ='D';
elseif m>70 && m <= 80
    A = 'C';
elseif m>90
    A = 'A';
else
    A = 'B'
end
