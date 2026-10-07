/*
APPROACH:
We use BFS (level-order traversal) with a queue for both
serialize() and deserialize().

```
---------------------------------------------------------
SERIALIZE: TREE -> STRING
---------------------------------------------------------

Example tree:

        1
       / \
      2   3
         / \
        4   5

We process nodes level by level.

Queue:
[1]
 ↓
process 1 -> put 2 and 3 in queue
[2, 3]
 ↓
process 2 -> both children are NULL
process 3 -> put 4 and 5 in queue
[4, 5]
 ↓
process 4 and 5 -> all children are NULL

Important:
We also push NULL nodes into the queue.

Why?
Because NULL positions must be stored in the same BFS order.
When a NULL node comes out of the queue, we store "#".

Example serialized string:

1,2,3,#,#,4,5,#,#,#,#,

For a normal node:
    store its value
    push its left child
    push its right child

For a NULL node:
    store "#"
    do not push anything further


---------------------------------------------------------
DESERIALIZE: STRING -> TREE
---------------------------------------------------------

First value is always the root.

Example:
    "1,2,3,#,#,4,5,#,#,#,#,"

Read "1":
    create root node 1
    push root into queue

Then take nodes from the queue one by one.

For every node:
    1. Read the next value -> left child
    2. If it is "#", left child is NULL
    3. Otherwise create the left node and push it into queue

    4. Read the next value -> right child
    5. If it is "#", right child is NULL
    6. Otherwise create the right node and push it into queue

The queue tells us which node's children we need
to construct next.

---------------------------------------------------------
KEY IDEA
---------------------------------------------------------

serialize():
    Tree -> BFS -> String

deserialize():
    String -> BFS -> Tree

"#" represents a NULL child.

stringstream is used in deserialize() so that we can
read the serialized string one value at a time using
getline() with ',' as the separator.

stoi() converts the string value into an integer.
```

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();

            if(temp == NULL){
                s += "#,";
                continue;
            }
            s += to_string(temp->val) + ',';
            
                q.push(temp->left);
            
                q.push(temp->right);
           
          
            
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() ==0 ) return NULL;
        stringstream s(data);
        string str;
        getline(s, str,',');
        TreeNode * root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();

            getline(s, str,',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode * leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
