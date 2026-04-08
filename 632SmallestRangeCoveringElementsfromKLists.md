# Smallest Range Covering Elements from K Lists

## Problem Statement

Given **K sorted lists**, find the **smallest range [start, end]** such that there is **at least one element from each list** within that range.

---

## Core Insight

> To minimize the range, we need to **track the minimum and maximum** of our current "window" across all K lists simultaneously.

Think of it like this — you're picking **one number from each list**, and you want the gap between the smallest and largest pick to be as tiny as possible.

---

## Why a Min-Heap?

At any point you're holding **K elements** (one from each list). The range is:

```
range = max_element - min_element
```

- **Max** is easy — just track it as a variable
- **Min** is expensive to find repeatedly → use a **min-heap** to get it in O(log K)

---

## Step-by-Step Walkthrough

Say you have:

```
List 0: [4, 7, 30]
List 1: [1, 5, 8]
List 2: [2, 6, 50]
```

### Step 1 — Initialize heap with first elements

Push one element from each list:

| Heap contains       | mini | maxi | Range          |
|---------------------|------|------|----------------|
| (4,r0), (1,r1), (2,r2) | 1    | 4    | [1, 4] → size 3 |

```
start=1, end=4  ✅ best so far
```

---

### Step 2 — Pop minimum, push next from same list

Pop `1` (from List 1, col 0) → push next from List 1 → `5`

| Heap contains           | mini | maxi | Range           |
|-------------------------|------|------|-----------------|
| (4,r0), (5,r1), (2,r2) | 2    | 5    | [2, 5] → size 3 |

```
2-5 vs 1-4 → same size, keep [1,4]
```

---

Pop `2` (from List 2, col 0) → push next from List 2 → `6`

| Heap contains           | mini | maxi | Range           |
|-------------------------|------|------|-----------------|
| (4,r0), (5,r1), (6,r2) | 4    | 6    | [4, 6] → size 2 ✅ |

```
Better! start=4, end=6
```

---

Pop `4` (from List 0, col 0) → push next from List 0 → `7`

| Heap contains           | mini | maxi | Range           |
|-------------------------|------|------|-----------------|
| (7,r0), (5,r1), (6,r2) | 5    | 7    | [5, 7] → size 2 |

```
Same size, keep [4,6]
```

...and so on until one list is **exhausted** → break.

**Final Answer: [4, 6]**

---

## Visual Flow of the Algorithm

```
Initialize
──────────
Push nums[i][0] for all i
Track mini and maxi

       ┌─────────────────────────┐
       │     Min Heap            │
       │  (smallest on top)      │
       └────────────┬────────────┘
                    │ pop min
                    ▼
          Update range if better
                    │
                    ▼
         Push next element from
         same row into heap
                    │
              ┌─────┴──────┐
         Yes  │ Next exists?│  No
              └─────┬──────┘
                    │              └──► BREAK (one list exhausted)
                    ▼
            Update maxi if needed
                    │
                    └──► repeat
```

---

## Why Break When a List is Exhausted?

Once any list runs out of elements, you **cannot cover all K lists** anymore — so no valid range is possible beyond that point.

---

## Complexity

| | Value |
|---|---|
| **Time** | O(N · log K) where N = total elements across all lists |
| **Space** | O(K) for the heap |

---

## Key Takeaways

| Concept | Role |
|---|---|
| Min-heap | Efficiently finds the current minimum |
| `maxi` variable | Tracks current maximum without extra cost |
| Column tracking | Knows which element to push next from each list |
| Break condition | Stops when full coverage is impossible |

The elegance of this algorithm is that by always **replacing the minimum**, you're greedily trying to shrink the range from the bottom — while `maxi` naturally adjusts upward only when needed.

---

## Corrected Code

```cpp
class node {
public:
    int data, row, col;
    node(int d, int r, int c) : data(d), row(r), col(c) {}
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        int k = nums.size();

        priority_queue<node*, vector<node*>, compare> minHeap;

        // Step 1: Push first element of each list
        for (int i = 0; i < k; i++) {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new node(element, i, 0));
        }

        int start = mini, end = maxi;

        // Step 2: Process ranges
        while (!minHeap.empty()) {
            node* temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;

            // Update answer if better range found
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // Check next element exists in same row
            if (temp->col + 1 < (int)nums[temp->row].size()) {
                int nextVal = nums[temp->row][temp->col + 1];
                maxi = max(maxi, nextVal);
                minHeap.push(new node(nextVal, temp->row, temp->col + 1));
            } else {
                // One list exhausted — can't cover all lists anymore
                break;
            }

            delete temp;
        }

        return {start, end};
    }
};
```
