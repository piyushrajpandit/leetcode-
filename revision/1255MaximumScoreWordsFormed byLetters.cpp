/*
question is find the maximum score you have letter words and score score 0 to 26 for each word 
letter availble words and and avalible letters make words from given letter thing one letter one tine 
and you cna chose 2 or more words if it presents in leetter


lets understand this code 


for we make freq storing each letter repetition 
then we call solve function 
we pass words, score , freq and index at starting index is 0 

base case if index reaches after last word stop if 

find ans = for next words 

make used vector condatining all the letter that are use 
  
  for given index word 
  pick first character put in used make and increse wordscore by adding its score 
  if used becam greater than that letter make it possible false and break this loop 

if it is possible minus all the used form freq
and ans  = max(ans , wordscore of this word + adter this owed 


solve(2) is processing C
          |
          v
  1. SKIP C
          |
          v
     call solve(3)
          |
          v
       return 0
          |
          v
  2. TRY TAKE C
          |
          v
     REMOVE C LETTERS
          |
          v
     call solve(3)
          |
          v
       return 0
          |
          v
     RESTORE C LETTERS  <-- THIS LOOP
          |
          v
     return from solve(2)
          |
          v
  BACK TO solve(1), processing B



WORDS = { A, B, C }

                 solve(0) : A
                 /           \
          SKIP A               TAKE A
             |                    |
         solve(1)             REMOVE A
             |                    |
          SKIP B              solve(1)
             |                    |
         solve(2)           /          \
             |          SKIP B        TAKE B
          SKIP C             |            |
             |           solve(2)      REMOVE B
         solve(3)             |            |
             |             ...        solve(2)
          RETURN 0                        /    \
             |                        SKIP C  TAKE C
             v                           |       |
         BACK TO C                    solve(3) REMOVE C
             |                           |       |
          TAKE C                      RETURN 0 solve(3)
             |                           |       |
          REMOVE C                      RETURN  BACK
             |                           TO C   TO C
         solve(3)                                |
             |                               RESTORE C
          RETURN 0                                |
             |                               RETURN TO B
         BACK TO C                                |
             |                               RESTORE B
         RESTORE C                                 |
             |                               RETURN TO A
         RETURN TO B                               |
             |                                RESTORE A
         TRY TAKE B
             |
         REMOVE B
             |
         solve(2)
             |
        EXPLORE C AGAIN
             |
         RESTORE C
             |
         RETURN TO B
             |
         RESTORE B
             |
         RETURN TO A
             |
         RESTORE A
             |
         RETURN FINAL ANSWER

*/
class Solution {
public:
    int solve(vector<string>& words, vector<int>& score, vector<int> freq, int index){
        if(index == words.size()){
            return 0;
        }
        int ans = solve(words, score, freq, index+1);

        vector<int> used(26, 0);
        int wordScore = 0;
        bool possible = true;

        for(char c: words[index]){
            int id = c - 'a';
            used[id]++;
            wordScore += score[id];

            if(used[id] > freq[id]){
                possible = false;
                break;
            }
        }
        if(possible){
            for(int i =0; i< 26; i++){
                freq[i] -= used[i];
            }
            ans = max(ans, wordScore + solve(words,score, freq, index+1));
            for(int i =0; i< 26 ;i++){
                freq[i] += used[i];
            }
        }
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for(char c :letters){
            freq[c - 'a']++;
        }
    return solve(words, score, freq, 0);
    }
};

