// LeetCode 881 - Boats to Save People
//
// 1. Sort people by weight.
// 2. Use two pointers:
//      left  = lightest person
//      right = heaviest person
//
// 3. Check whether the lightest and heaviest can share a boat:
//      people[left] + people[right] <= limit
//
// 4. If they can share:
//      move both left++ and right--.
//
// 5. If they cannot share:
//      the heaviest person must go alone,
//      so only right--.
//
// 6. Every iteration uses one boat, so count++.
//
// Time Complexity: O(n log n) because of sorting.
// Space Complexity: O(1) extra space apart from sorting.


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        
        int left = 0;
        int right = people.size() -1;
        int count = 0 ;
       
        while(left <= right){
            int sum = people[left] + people[right];
            if(sum <= limit){
                count++;
                left++;
                right--;
            }
            else{
                right--;
                count++;
            }
        }
        return count;
    }
};
