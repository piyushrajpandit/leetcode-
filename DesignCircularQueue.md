#approach 

check empty if front == -1 means empty


check if full  if front == 0 and rear == size -1 ;
                  or rear = (front -1 + size)%size


## Push (Enqueue)

1. If full → Overflow  
2. If empty → `front = rear = 0`  
3. Else if `rear == size - 1` → `rear = 0`  
4. Else → `rear++`  
5. Insert element at `arr[rear]`

---

## Pop (Dequeue)

1. If empty → Underflow  
2. If single element → `front = rear = -1`  
3. Else if `front == size - 1` → `front = 0`  
4. Else → `front++`

---


   
    
  

