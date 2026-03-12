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
        Node * clonehead=  NULL; 
        Node * clonetail = NULL; 
        Node * temp = head ;
        while (temp != NULL){
            insertAttail(clonehead , clonetail , temp->val);
            temp = temp->next;
        }

        //crete a mapping second step 
        unordered_map<Node * , Node * > OldToNew;
        Node * orignalNode= head ;
        Node * cloneNode = clonehead ;
        while (orignalNode!= NULL && cloneNode != NULL){
            OldToNew[orignalNode] = cloneNode;
            cloneNode = cloneNode->next;
            orignalNode = orignalNode->next;
        }

    // Step 3: assign random pointers
    orignalNode = head;       
    cloneNode = clonehead; 
        while(orignalNode != NULL){
            cloneNode ->random = OldToNew[orignalNode ->random];
            cloneNode = cloneNode->next;
            orignalNode = orignalNode->next;
        }
        return clonehead;
    }
};
