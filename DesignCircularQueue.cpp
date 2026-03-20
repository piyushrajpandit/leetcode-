class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear ;
    int size;
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1 ;
    }
    
    bool enQueue(int value) {
        if((front == 0  && rear == size -1) || (rear == (front - 1 + size) % size)){
            cout << " queue is full";
            //to check if queue is full
            return false ;
        }
        else if(front == -1 ){
            front = rear = 0 ;
            // to insert first element 
           

        }
        else if((rear == size -1 )&&(front != 0 )){
            rear = 0 ;
            
        // to maintain cyclic natur 
        }
        else{
            // normal
            rear++ ;
            
        }
        arr[rear] = value;
        return true;

    }
    
    bool deQueue() {
        if(front == -1){
            //to check if queue is empty
            
            return false ;
        }
        int ans = arr[front];
        arr[front] = -1 ;
        if(front == rear){
            //single element 
            front = rear = -1 ;
        }
        else if(front == size -1 ){
            front = 0 ;
            //to maintain cyclic nature

        }
        else{
            //normal
            front++;
        }
        return true;
        
    }
    
    int Front() {
         if(isEmpty()) return -1;
        return arr[front] ;
    }
    
    int Rear() {
           if(isEmpty()) return -1;
        return arr[rear] ;
    }
    
    bool isEmpty() {
          if(front == -1){
            
            return true;

        }
        else{
            return false;
        }
    }
    
    bool isFull() {
             if((front == 0  && rear == size -1) || (rear == (front - 1 + size) % size)){
            
            //to check if queue is full
            return true ;
             }
            else{
                return false;
            }
        }
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
