// Insert the current person at index k.
// people[i][1] represents k, the required number of taller/equal people
// that should be in front of this person.
answer.insert(answer.begin() + people[i][1], people[i]);


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> answer;
        sort(people.begin(), people.end() ,
        [](const vector<int>& a , const vector<int>& b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        for(int i =0 ; i< people.size() ; i++){
            int temp = people[i][1];
            answer.insert(answer.begin() + temp , people[i]);
        }
        return answer;
    }
};
