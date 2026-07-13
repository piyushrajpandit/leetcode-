/*
========================== Huffman Encoding ==========================

Problem:
Given N characters and their frequencies, generate Huffman Codes
(minimum length prefix-free binary codes).

Greedy Idea:
1. Insert every character frequency into a Min Heap.
2. Repeatedly remove the two nodes with the smallest frequencies.
3. Merge them into a new node whose frequency is the sum.
4. Push the merged node back into the Min Heap.
5. Continue until only one node (the root) remains.
6. Traverse the tree:
      Left  -> append '0'
      Right -> append '1'
   The path from root to every leaf is its Huffman Code.

Why Greedy?
Combining the two least frequent characters first minimizes the
overall encoding cost.

Data Structure:
Min Heap (Priority Queue)

Time Complexity : O(N log N)
Space Complexity: O(N)

Pattern:
Greedy + Min Heap + Binary Tree + DFS

======================================================================
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Comparator for Min Heap
class cmp {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:

    // DFS Traversal to generate Huffman Codes
    void traverse(Node* root, vector<string>& ans, string temp) {

        // Base Case
        if (root == NULL)
            return;

        // Leaf Node -> Huffman Code completed
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }

        // Left Edge -> 0
        traverse(root->left, ans, temp + '0');

        // Right Edge -> 1
        traverse(root->right, ans, temp + '1');
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {

        // Min Heap
        priority_queue<Node*, vector<Node*>, cmp> pq;

        // Insert all frequencies into Min Heap
        for (int i = 0; i < N; i++) {
            Node* temp = new Node(f[i]);
            pq.push(temp);
        }

        // Build Huffman Tree
        while (pq.size() > 1) {

            // Two minimum frequency nodes
            Node* left = pq.top();
            pq.pop();

            Node* right = pq.top();
            pq.pop();

            // Merge them
            Node* newNode = new Node(left->data + right->data);

            newNode->left = left;
            newNode->right = right;

            // Push merged node back
            pq.push(newNode);
        }

        // Root of Huffman Tree
        Node* root = pq.top();

        vector<string> ans;
        string temp = "";

        // Generate Huffman Codes
        traverse(root, ans, temp);

        return ans;
    }
};
