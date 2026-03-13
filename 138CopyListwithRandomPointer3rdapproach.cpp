/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void insertAttail(Node *& head ,Node *& tail, int val ){
        Node * newNode = new Node(val);
        if (head == NULL ){
            head = newNode ; 
            tail = newNode ;
            return ;
        }
        else{
            tail -> next = newNode ;
            tail = newNode ;
        }
    }
    Node* copyRandomList(Node* head) {
        //step 1 creteing clone node 
        Node * clonehead=  NULL; 
        Node * clonetail = NULL; 
        Node * temp = head ;
        while (temp != NULL){
            insertAttail(clonehead , clonetail , temp->val);
            temp = temp->next;
        }

        Node * orignalNode  = head ;
        Node * cloneNode = clonehead ;
        while (orignalNode != NULL && cloneNode != NULL){
            Node * next = orignalNode->next; 
            orignalNode->next = cloneNode ; 
            orignalNode = next;
            
            next = cloneNode->next; 
            cloneNode ->next = orignalNode ;
            cloneNode = next;
        }
         temp = head ; 
        while (temp != NULL){
            if(temp->next != NULL){
                if(temp->random!= NULL){
                    temp -> next ->random = temp ->random -> next;
                }
                else{
                    temp ->next->random = NULL;
                }
            }
            temp = temp->next->next ;
        }
    orignalNode = head;
    cloneNode = clonehead;
        while(orignalNode != NULL && cloneNode != NULL){
            orignalNode->next = cloneNode ->next ; 
            orignalNode  = orignalNode ->next ;
            if(orignalNode != NULL){
            cloneNode->next = orignalNode ->next ; 
            }
            cloneNode= cloneNode ->next ;
        }
return clonehead;


    }
};
