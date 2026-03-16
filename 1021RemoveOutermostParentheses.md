#approach 
1. create string same to given string 
1.if character is ( then push it in stack index at which it is 
2. if ) is there then save the top of stack and remove it
3. if after removing it stack became empty then in answer at that index put * 
4. means all the opening and closing of last bracket are * 
5. now make result string and one by tranverse answer string if it contain * then jump else put in result 
return result 
  
  


           
