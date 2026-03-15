#approach
1. ek stack lo
2. ek same string banno copy answer
3. one by one acce chalo string me if front bracket aya to store karo index stack me
4. if closing brackket aya
             aur stack empty nahi hai to stack ka ek eleemnt pop kar do

             nahi to answer ka wo index = "*"  rakh do matlab unmatched closing bracket sab hat gaya
5.  abb stack me agar sirf front bracket hai unmatched aur string pura ho chuka hai to
    answer ke index = stack ke top pe jo index hai waha pe * rakh do
       sare unmatched front bracket ke jagah pe  bhi * aa gaya

6. now loop chalo ek ek kar ke answer ke charackter pe agar * nahi hai to result me push kar do
7. answer return kar do


  
            
   
    
};
