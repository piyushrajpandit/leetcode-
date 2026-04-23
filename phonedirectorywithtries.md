# 📱 Phone Directory Using Trie — Algorithm

## 🔹 Objective

Given a list of contacts and a query string, return suggestions for every prefix of the query using a Trie.

---

## 🔹 Data Structure

Each Trie node contains:

* `children[26]` → pointers to next characters (a–z)
* `isTerminal` → marks end of a valid word

---

## 🔹 Algorithm

### Step 1: Create Trie

1. Initialize root node with null character.
2. For each contact in the list:

   * Insert the word into the Trie.

---

### Step 2: Insert Word into Trie

For each character in the word:

1. Compute index = `character - 'a'`
2. If child node does not exist:

   * Create a new node
3. Move to the child node
4. Repeat for next character
5. Mark last node as `isTerminal = true`

---

### Step 3: Generate Suggestions (DFS)

1. Start from current node
2. If node is terminal:

   * Add current prefix to result
3. For each character from `'a'` to `'z'`:

   * If child exists:

     * Append character to prefix
     * Recursively call DFS
     * Backtrack (remove last character)

---

### Step 4: Process Query String

1. Initialize:

   * `prefix = ""`
   * `prev = root`
2. For each character in query:

   * Add character to prefix
   * Move to corresponding child node
   * If node does not exist:

     * Stop further processing
   * Else:

     * Call DFS to get suggestions
     * Store result
     * Update `prev`

---

## 🔹 Output

Return a list of suggestions for each prefix of the query string.

---

## 🔹 Complexity

* **Insertion:** O(N × L)
* **Search:** O(L + suggestions)
* **Space:** O(N × L)

Where:

* `N` = number of contacts
* `L` = average length of contacts

---

## 🔹 Notes

* Works for lowercase letters only
* DFS may be expensive for large datasets
* Can be optimized by storing top suggestions at each node
