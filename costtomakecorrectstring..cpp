// actual you will have {}{}{{{}} , {}}}{{}} this types of string you haave to find the cost to make it valid string means number of { } that yoou have to reverse to get correct string
// aproach 

// remove all the valid bracket {} like this and for remaing do this 
// 1.there are two case if total number of element in string is old then return -1 because their is no case by which you
// can satity { bracket with close 
// 2.now if total number of element are even the 3 cases are possible 
//      1. }}}} only closing bracket 
//      2. {{{{ only opening bracket 
//      3. first }}} then {{{ brakcet 
//               by obersation if a = number of opening bracket and b = number of closing bracket then total number of elemnt the we have to reverse is 
//               result = ((a+1)/2 +(b+1)/2)
//               for all three cases


int findmincost(string str){
  if(str.lenght() %  2 != 0) {
      return -1 ; 
  } 


stack<char> s; 
for(int i =0 ; i< str.length(); i++){
      char ch = str[i];
      if(ch =='{'){
        s.push('{');
      }
      else{
        //ch is close bracket 
            if(!s.empty() && s.top() == '{'){
                  s.pop();
            }
            else{
                  s.push(ch);
            }
      }
  
}
//stack contain invalid expressoion
int a,b =0 ;
while(!s.empty()){
        if(s.top()='{'){
          a++;
        }
        else{
          b++;
        }
        s.pop();
}

int answer = (a+1)/2 +(b+1)/2;
return answer;

