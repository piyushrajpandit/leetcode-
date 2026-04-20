#approach 
first thing we have to do is hashing of number 
like 

ye tatika ka node banane ka 
starting me ek root ke pass 26 chldren honge aur uska children [i] kare null honge aur terminal false hoga 
class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    bool isTerminal;
      TrieNode(char ch) {
        data = ch;
        for(int i=0; i< 26; i++){
            children[i] = NULL;
        }
        isTerminal= false;
        
    }
    
};


insert karne ke liye
root bano
agar word lenght equal to zero hai to terminal ko true kar do means terminal aa gaya 
else agar word lenght hai to index nikalo uper case me change kar ke -"A" minus kar lo 
ek child node crate karo agar root ka koi children wo index pe null nahi hai to to child = root->children[index];
else new node bano aur word[0] usme rakh do 
aur agge recursion call kar do  insertUtil(child , word.substr(1));

search  
search karne ke base case wood length zero ho terminil bhi aa gaya to true nahi to false return karo
 index nikalo aur child bano agar same root->children[index]!= null hua to child me root->chilren rakh do nahi ti false return kar do and recurssion call kar do 
        int index = toupper(word[0])-'A';
        TrieNode* child;

    
 startwith karna ho to 
 same base case wordlenght == 0 return true 
 else index nikalo aur root->children[index] = NULL hai to return false karo else recurssion call karo 
     bool startsWithUtil(TrieNode* root, string word) {
        if (word.length() == 0) return true;
