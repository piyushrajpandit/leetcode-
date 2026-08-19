/* 
we have to do calculate left left is the maximum element of weight
and right is the sum of all elment 
int daysneeded we have to calucate = 1 ;
and now current weight = 0;
  start a for loop and calculate currentweight if currentweight + weight  is less than mid 
  then add it else increse the dayneeded and start form that weight 
now we have if days >= daysNeeded   so allowed days days are more then needed days so we need to 
search in left part so right = mid;
and 
else
we need to search in right part left = mid + 1




mid works
   ↓
KEEP mid
   ↓
right = mid


mid doesn't work
   ↓
THROW AWAY mid
   ↓
left = mid + 1





*/
