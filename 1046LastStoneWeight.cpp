// #what we can do here is first make is heap and then pop first element and pop back and then smae we do for second last element and if diff
// diff>0 we will can push the element in heap the diff and again do the heapify 


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin() , stones.end());

        while(stones.size() > 1){
            pop_heap(stones.begin() , stones.end());
            int x =stones.back();//largest stone
            stones.pop_back();

            pop_heap(stones.begin() , stones.end());
            int y=stones.back();//second largest stone
            stones.pop_back();

            int diff = abs(x-y);
            if(diff>0){
                stones.push_back(diff);
                push_heap(stones.begin() , stones.end());
            }
        }

        if(stones.size() == 1){
            return stones[0];

        
        }
        return 0 ;
    }
};
