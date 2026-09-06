// Greedy + Min Heap approach
// 1. Sort events by their starting day.
// 2. For each day, add all events that have started to the min heap.
// 3. Min heap stores the end dates, so the earliest ending event is always on top.
// 4. Remove all events whose end date is before the current day.
// 5. Attend the event with the earliest end date and increase count.
// 6. Move to the next day and repeat.
// 7. j ensures every event is added to the heap only once.
// Time: O(n log n + D log n)
// Space: O(n)

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end() , [](const vector<int> & a, const vector<int> & b){
            return a[0] < b[0];
        });
        int endDate = -1;
        for(int i =0 ; i< events.size() ; i++){
            endDate = max( events[i][1] , endDate);
        }
        int j =0 ;
        int count = 0 ;
        for(int day =1; day<= endDate; day++) {
            while(j< events.size() && events[j][0] <= day){
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop(); 
                count++;
            }
        }
       
        return count ;
    }
};
