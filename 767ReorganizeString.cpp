/*

Count Frequency
        ↓
Build Max Heap
        ↓
Pick Most Frequent Character
        ↓
Append to Answer
        ↓
Decrease Frequency
        ↓
Reinsert Previous Blocked Character
        ↓
Block Current Character
        ↓
Repeat



first understand the blocked character if you place one character in string you dont have to put that recursive after one so to skip that to 
come again we do this 
block store 
blocked.first  → remaining frequency

blocked.second → character

whole idea is pick top element with highest frequency and the and put it in answer 
the decrese frequency 
now insert the prevous block character if its frequency is greater than 0 
 we have few more lines 
if(answer.size() != s.size())
            return "";  to final check 
like we go for aaaba 
it will return aba only so lenght not match so we will return empty string 
Maximum allowed frequency = (n+1)/2  if any element has more frequecy than this we can put it any how 

*/

class Solution {
public:
    string reorganizeString(string s) {
        string answer;
        //step 1 ; count character frequency using a map 
        unordered_map<char , int> counts;
        for( char c : s){
            counts[c]++;
        
        }
        
      
        priority_queue<pair<int , char>> heap_array;

       
        //step 3: populate the heap with the data  
        for(const auto& pair: counts){
            heap_array.push({pair.second, pair.first});
            
        }
        pair<int, char> blocked = { -1, '#'};
        if(heap_array.top().first > (s.size()+1)/2)
            return "";
        while(!heap_array.empty()){
            
            //get the character with the highest reamining freaquency 
            auto current = heap_array.top();
            heap_array.pop();
            // add the character to the answer string 
            answer += current.second ;
            //decrese its  frequecy 
            current.first--;
            if(blocked.first > 0){
                heap_array.push(blocked);
            }
            //blocked the current character so it isn't used in the next iteration 
            blocked = current;
        }
        

        if(answer.size() != s.size())
            return "";
        return answer;
    }
};
