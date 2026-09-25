class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string answer;
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }

            string word;
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            if (!word.empty()) {
                words.push_back(word);
            }
        }

        for (int i = words.size() - 1; i >= 0; i--) {

            answer += words[i];
            if (i != 0) {
                answer += ' ';
            }
        }
        return answer;
    }
};
