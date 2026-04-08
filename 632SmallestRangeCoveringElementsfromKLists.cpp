class node{
    public: 
    int data;
    int row;
    int col;
    node(int d, int r, int c){
        data= d;
        row= r;
        col = c;
    }
};
class compare { 
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};
class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX, maxi= INT_MIN;
        int k = nums.size();
        //step 1 : crete a min heap for starting element of each list and tracking mini/maxi value
        priority_queue<node*, vector<node*> , compare> minHeap;
        for(int i=0; i<k; i++){
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new node(element,i,0));

        }
        int start = mini, end = maxi;

        //process rangfes
        while(!minHeap.empty()){
            //mini fetch
            node * temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;

            //update answer if better range exists
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            //check next elment exists in same row 
            if(temp->col +1 < (int)nums[temp->row].size()){
                int nextVal = nums[temp->row][temp->col +1];
                maxi = max(maxi ,nextVal);
                minHeap.push(new node(nextVal,temp->row, temp->col +1));
            }

            else{
                //one list exhausted - cant't cover all lists anymore
                // next element does not exist 
                  break;
            }
              
            delete temp;
    }
            return {start, end}; // return vector , not an integer expression

        
    }
};
