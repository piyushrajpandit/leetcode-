/*
this is the question most important thing we have to make 
this is swallow copy we dont have to do this 
clone ----\
           \
            Original Node
           /
node ------/
we have to create a seprate node like this 
Node* clone = new Node(node->val);
make map to things that you have done   unordered_map<Node*, Node*> mp; 
and at last you have to do bfs or dfs for all the other items 
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
        unordered_map<Node*, Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;


        Node* sourceNode = node;

        if (mp.find(sourceNode) != mp.end()) 
            // sourceNode is mapped
            return  mp[sourceNode];
        
       Node* clone= new Node(node->val);
       mp[node] = clone;

       for(Node* neigh : node->neighbors){
        
        Node* clonedNeighbor = cloneGraph(neigh);
        clone->neighbors.push_back(clonedNeighbor);
       }
       return clone;
    }
};





