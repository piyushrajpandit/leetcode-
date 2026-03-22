#include<iostream>
using namespace std;

class kQueue {
public;     
          int n;
          int k;
          int *front;
          int *rear;
          int *arr;
          int freeSpot;
          int *next;

kQueue(int n, int k){
                      this-> n =n;
                      this-> k=k;
                      front = new int[k];
                      rear = new int[k];
              for(int i=0 ; i<k; i++){
                front[i]= -1;
                rear[i]= -1;
              }
              for(int i=0; i< n; i++){
                next[i]= i+1;
              }
              next[n-1]= -1;
              }
              arr =new int[n];
              freespot = 0;
        
}
void enqueue(int data, int qn){
        //overflow
          if(freeSpot == -1){
            cout << "No empty space is present " << endl;
        return ;
          }
        //find first free index
        int index = freespot;
        
        //check whether first element
        if(front[qn-1] ==-1){
          front[qn-1] = index;
        }
        else{
          //link new element to the prev element
          next[reat[qn-1]]= index;
        }
          //update next
          next[index]=-1;
        
          //update rear
          rear[qn-1] = index;
        
          //push element
          arr[index] = data;
    }
index dequeue(int qn){
        //underflow
        if(front[qn-1] ==-1){
          cout << "queue is underflow " << endl;
          return ;
        }
        //find index to pop
        int index = front[qn-1];
      
        //front ko aage badho 
        front[qn-1] = next[index];
      
        //freeslot ko mange karo 
        next[index] = freeSpot;
        freespot = index;
        return arr[index];
}
          

  
}


