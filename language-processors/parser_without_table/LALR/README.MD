Enter No.of productions:3
Enter no.of reduced states:
7
Enter no.of terminals:
3
Enter no.of non-terminals:
2
0 s36 s47 -1 1 2 -| 
1 -1 -1 A -1 -1 -| 
2 s36 s47 -1 -1 5 -| 
36 s36 s47 -1 -1 89 -| 
47 r3 r3 r3 -1 -1 -| 
5 -1 -1 r1 -1 -1 -| 
89 r2 r2 r2 -1 -1 -| 
Enter no.of terminals in i/p string:
4
Enter the i/p string:
c
d
c
d


 parsing

0	 c	s36
cdcd$	shift s36
36	 d	s47
dcd$	shift s47
47	 c	r3
cd$	reduce r3
36
89	 c	r2
cd$	reduce r2
0
2	 c	s36
cd$	shift s36
36	 d	s47
d$	shift s47
47	 $	r3
$	reduce r3
36
89	 $	r2
$	reduce r2
2
5	 $	r1
$	reduce r1
0
1	 $	A
string accepted
