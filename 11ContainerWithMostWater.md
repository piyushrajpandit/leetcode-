#apprach 
we find the max water store so we want two strick one with max height and one with minimum height 
to do that at starting make first index as min_height and last index is max_height
now lets check if min_height is grete than max_height then reverse it make min_height to last index and max_height to first index
you also want width between those two so for starting take w = height.size() -1 means full as width
and area = min_height* w  this will be our simple formula to calculate it 
now we have to traverse it till width > 0 
make index = min_index;
  while(height at that index < min_height
  we have to do one thing check if min_index < max_index if this is the case make index++ else index-- and ater doing this also make w--
  and at last make a safe condition if w < 1 break the loop
similarty do if height at index > max_height 
make min_height = max_height 
and max_hieght = hieght at that index
else make min_height = height at that index 
and at lase find the max are by max function if new area is max then change max are to that else move on 




          
