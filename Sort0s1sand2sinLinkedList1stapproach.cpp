Node * shortlist(Node * head){
int Zerocount = 0;
int Onecount = 0;
int Twocount = 0 ; 
Node * temp = head ;
while(temp != NULL){
            if(temp->value == 0)
            Zerocount++;
            }
            else if(temp->value == 1)
            Onecount++;
            }
            else if(temp->value == 2)
            Twocount++;
            }
            temp = temp->next;
            }
temp = head; 
while (temp != NULL){
            if(Zerocount > 0 ) {
            temp ->value = 0 ;
            Zerocount--;
            }
            else if(Onecount > 0 ) {
            temp ->value = 0 ;
            Twocount--;
            }
            else if(Twocount > 0 ) {
            temp ->value = 0 ;
            Twocount--;
            }
temp = temp ->next;
}
retunr head
}
