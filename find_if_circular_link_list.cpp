// 141 question ka hai lekin wo loop ka hai aur ye code sirf circular ka hai /

public:

    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return true;
        }
        ListNode* temp = head->next;
        while(temp != NULL && temp != head){
            temp = temp->next;
        }
        if(temp == head){
            return true;
        }
        return false;
        
    }
};
