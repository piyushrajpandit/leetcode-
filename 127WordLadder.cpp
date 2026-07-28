/* this question is done by help of ai 
still my last question are likke same but i cant write it 
lets understand it 


Insert all words into set

If endWord not in set
    return 0

Push beginWord into queue

Erase beginWord from set

while queue not empty

    Pop front

    If current == endWord
        return length

    For every position

        Copy current word

        Try 'a' to 'z'

            If word exists

                Push

                Erase from set

return 0

above here is alogritm let me explain things which are new to me 

 unordered_set<string> element; to create this and put all words in this 

 element.erase(beginWord); each time erase that element which is used 

if(element.find(newWord) != element.end() find some thing in unordered set 

    whole idea we change one character of word and match if it exist in element if it exist we push in query and remove form element 
    and do it untill queue is empty 



Whole idea of the algorithm
Put all words from wordList into an unordered_set.
This lets us check whether a word exists in O(1) average time.
Start BFS from beginWord.
Push (beginWord, 1) into the queue.
While the queue is not empty:
Pop the current word.
If it is endWord, return its current length.
For every position in the current word:
Change that character to every letter from 'a' to 'z'.
This generates all possible words that differ by exactly one character.
If the generated word exists in the unordered_set:
Push it into the queue with length + 1.
Remove it from the set so it is never visited again.
Repeat until:
You reach endWord (return the answer), or
The queue becomes empty (return 0 because no transformation exists).
*/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> element;
        for (string word : wordList)
             element.insert(word);

        if (element.find(endWord) == element.end())
             return 0;
        queue<pair<string,int>> q;
       
        q.push({beginWord,1});
        element.erase(beginWord);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            string state = curr.first;
            int length = curr.second;
            if(state == endWord)
                return length;
            for(int i = 0; i < state.length(); i++){
                    string newWord= state;
                    char original = newWord[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if (newWord[i] == ch)
                        continue;
                    newWord[i] = ch;
                    if(element.find(newWord) != element.end()){
                        q.push({newWord, length+1});
                        element.erase(newWord);
                    }
                }
                newWord[i] = original;
        }
        }

        return 0;
    }
};

           
