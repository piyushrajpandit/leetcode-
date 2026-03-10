void insertAttail(Node * &tail, Node *curr){
  tail->next = curr; 
  tail = curr;
}

Node* shotlist (Node *head){
  Node * zerohead = new node(-1);
  Node * zerotail = zerohead;
  Node * onehead = new node(-1);
  Node * onetail = onehead;
  Node * twohead = new node(-1);
  Node * twotail = twohead;


  Node *curr = head ; 
  while (curr!= head){
  int value = curr->value;
    if( value == 0){
      insertAt(zerotail,curr);
    }
    else if( value == 1){
      insertAt(zerotail,curr);
    }
    else if( value == 2){
      insertAt(zerotail,curr);
    }
    curr = curr->next;
  }

  //merge list 
if(inehead->next !=  NULL){}
else(){zerotail->next = twohead->next; }
  
 onetail->next = twohead->next;
  twotail->next = NULL;

//setup head 
head  = zerohead->next;

//delete dummy head 
delete zerohead; 
delete onehead ;
delete twohead;
      
      return head;

}
