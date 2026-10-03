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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
  
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr){
           
            ans.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> answer(ans.size(), 0);
        for(int i =0 ; i < ans.size() ; i++){

            for(int j =i+1 ; j< ans.size() ; j++){
                if(ans[j] > ans[i]){
                    answer[i] = ans[j];
                    break;
                }
            }
        }
        return answer;
    }
};
