# we have to filp the number 
first thing is if number is 5 then its 3 bit number 101 if number 8 is its 1000 4 bit number so 
how we can find it we can do log2(num)+1 
so log2(5) + 1 is 2+1 = 3 
same apply with other number 
next thing we have to make a mask number 
like number is 3 bit number we will shift 1 3 times to left like 1000 so and then -1 so it bacame 111

now we know we we xor any number with with 1 it is filped so we will xor num with mask
we ussed unsigned because question tell to use positive mumber so c++ can t get confuse 
like if we shift 1 by 31 times it become 10000000000000000000000000000000
compiler may interpt it as negative number of overflown or undefined value so we have to use unsigned 
