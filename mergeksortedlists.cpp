/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class compare{
public: 
bool operator()(ListNode* a,ListNode* b){
    return a->val > b->val;
}
};
class Solution {
    
public:


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> , compare>minHeap;
        //step1 : saare arrays k first element insert h
        for(int i =0; i < lists.size() ; i++){
            if(lists[i] != NULL){
            minHeap.push(lists[i]);
        }
        }
        ListNode * head = NULL;
        ListNode * tail = NULL;
        
        //step 2 : process heap 
        while ( !minHeap.empty()){
            ListNode* tmp = minHeap.top();
            
            minHeap.pop();

            if(head == NULL){
                head = tmp;
                tail= tmp;
            }
            else{
                tail->next = tmp;
                tail= tmp;
            }

            if(tmp->next != NULL){
                minHeap.push(tmp->next);
            }
            }
        
        return head;
    }
};
