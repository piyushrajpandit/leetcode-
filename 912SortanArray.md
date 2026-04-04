#approach 
first make heap 
2nd move the first element to last
reduce the size by one 
make the rest heap 


heap kaise banana hai 
dekho jo tumhare leaf node hota hai wo to leaf is hota hai to wo check nahi kaarna 
iska matlab size/2 +1 tak to dekna hi nahi 
bake ke liye heapify function call karo 


heapify function 
ye element ko correct position pe pahuchata hai 
jaise tumhara max heap hua to root always greater than child hoga 

karne ka taika simple hai 
first kam jo given element usko largest man lo 
aur    int left = 2 *i+1 ;
        int right = 2 *i +2;
        nikal lo aur check kar lo agar left bada hai largest ko left se change karo 
        right bada hai to right ko change karo 
        aur agar koi sa bhi change kiye ho to un dono ko swap kar do to largest upar chala jai ga 
        aur jo niche aya hai usme heap function fir se call kar do
