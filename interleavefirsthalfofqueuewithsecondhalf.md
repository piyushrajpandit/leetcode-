means first ka ek element aur second half ka element 

1 task first half alag karo second half alag karo 

put first half in stack jisse wo ulta ho jai ga 

now put stack to queue

abb jo queue me first half(orignal second half) wo first se nikalo aur queue ke puche dal do 

first half of queue for fir se stack me dal do abb wo sidha hogaya 

abb ek elment stack se nikalo aur queue me dalo au ek element queue se nikalo or fir se dal do

while(!s.empty){
int val = s.top();
s.top();
q.push(val);
val = q.front();
q.pop();
q.push(val);
}
