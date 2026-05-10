#apprach 
we have to make unordered set name vowel 
and int vcount = 0 
and if we find vowel in s[i] we increase vcount++
now start a while loop we traverse through window 
and if we find no vowels there we vcount--
and if we vind vowerl we increase count 
and mvc = max (mvc, vcount)
and we return mvc 


we are using new  things here find and end 
find finds s[i] in vowel 
and end return iterator 
Meaning:

start from first character
keep moving
stop when iterator reaches position after last characte

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = { 'a','e','i','o','u'};
        int vcount = 0 ;
        for (int i =0 ; i < k ; ++ i ) {
            if(vowels.find(s[i]) != vowels.end())
                vcount++;

            
        }
        int l = 0 , r = k-1;
        int mvc = vcount ;
        while(r < s.length()-1){
             if(vowels.find(s[l]) != vowels.end()) vcount-- ;;
                l++;
                r++;
            if(vowels.find(s[r]) != vowels.end()) vcount++;
            mvc = max(mvc, vcount);
        }
        return mvc ;
    }
};
