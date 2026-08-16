/*
Grid
 ↓
Count islands using BFS
 ↓
Already disconnected?
 ├── Yes → 0
 └── No
      ↓
   One land cell?
   ├── Yes → 1
   └── No
        ↓
   Convert grid → graph
        ↓
   Tarjan DFS
        ↓
   Articulation point exists?
   ├── Yes → 1
   └── No  → 2


# LeetCode 1568 - Minimum Number of Days to Disconnect Island

## Approach

The problem can be solved using **BFS + Graph + Tarjan's Articulation Point Algorithm**.

### Step 1: Count Islands using BFS

First, count how many separate islands are present.

* If there are already more than one island, answer is `0`.
* If there are no land cells, answer is `0`.
* If there is only one land cell, answer is `1`.
* Otherwise, continue.

### Step 2: Convert Grid into Graph

Treat every land cell (`1`) as a graph node.

Convert `(row, col)` into a unique node:

```cpp
node = row * cols + col;
```

Two land cells are connected if they are directly adjacent in one of four directions:

```text
Right
Down
Left
Up
```

### Step 3: Find Articulation Points using Tarjan

Use DFS with two arrays:

```cpp
disc[node]
low[node]
```

`disc[node]` = time when the node was first visited.

`low[node]` = earliest discovery time reachable from that node or its subtree.

For every DFS child:

```cpp
low[node] = min(low[node], low[child]);
```

For a back edge:

```cpp
low[node] = min(low[node], disc[neighbor]);
```

A non-root node is an articulation point when:

```cpp
low[child] >= disc[node]
```

For the DFS root, it is an articulation point when it has more than one DFS child:

```cpp
parent == -1 && child > 1
```

### Step 4: Determine the Answer

```text
Already disconnected → 0

Only one land cell → 1

At least one articulation point → 1

No articulation point → 2
```

## Important Formulas

```cpp
disc[node] = low[node] = timer++;
```

```cpp
low[node] = min(low[node], low[child]);
```

```cpp
low[node] = min(low[node], disc[neighbor]);
```

```cpp
if(low[child] >= disc[node])
    node is an articulation point;
```

```cpp
if(parent == -1 && child > 1)
    node is an articulation point;
```

## Complexity

Let `R` = number of rows and `C` = number of columns.

* BFS: `O(R * C)`
* Graph construction: `O(R * C)`
* Tarjan: `O(V + E)` = `O(R * C)`
* Overall Time: **O(R * C)**
* Space: **O(R * C)**

*/
