1  ->  2   ->   3  ->   4
       |________________|


suppose this is the link list and now go through  141 question flyod way 
in that there are two pointer one slow one fast where slow and fast meet then it is confirm that link list is in loop 
so in this question we have to find the starting of the loop 
for that let A = diatance from starting to starting of the loop and 
              B= distance from starting of loop to point of intersection of fast and slow poninter 
            c = distance of loop 


now apply maths formula 
distanace covered by fast = 2* (distance covered by slow)
            (A + C*x + B) =  2*(A + C*y + B)
             A + C*X + B  = 2A + 2CY + 2B
                   A + B  = (X-2Y) C
                   A + B  = K C;   LET X-2Y = K   some constant
                    so it is means that A + B  is we have completed a cycle 
                    so if you are at B and you have to complete a cycle then you have to cover A distance

      if all this is lendy watch https://youtu.be/VxOFflTXlXo?si=pDmuAsb9v8viKBV7
now you have to do find the starting of loop for that put slow at starting of the linklist and crate interction node at intersection point 
one by one slow = slow next 
          and intersection = intersection -> next;
          till intersectin == slow and thats the point if staring of the loop


summary is simple so from intersection you move A steps then you reach starting of the loop.

add this for protection

ListNode* intersection = flyodintersection(head);
