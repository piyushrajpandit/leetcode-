
# Parallel Courses III (LeetCode 2050)

## Approach

This problem is solved using **Topological Sort (Kahn's Algorithm)** along with **Dynamic Programming**.

### Idea

- Each course is a node.
- Each prerequisite relation is a directed edge.
- A course can only start after all its prerequisite courses are completed.
- Since multiple courses can run simultaneously, we keep track of the **earliest completion time** for every course.

---

## Algorithm

1. Build an adjacency list from the `relations` array.
2. Compute the indegree of every course.
3. Push all courses with indegree `0` into a queue.
4. Initialize `finish[i]` as the duration of course `i`.
5. Perform Topological Sort:
   - Pop a course from the queue.
   - Traverse all its neighbors.
   - Update the neighbor's completion time:

   ```
   finish[neighbor] =
   max(finish[neighbor],
       finish[current] + time[neighbor - 1])
   ```

   - Decrease indegree.
   - If indegree becomes `0`, push it into the queue.
6. The answer is the maximum value in the `finish` array.

---

## Why Dynamic Programming?

A course may have multiple prerequisites.

Example:

1 --> 3
2 --> 3

Time:

Course 1 = 3

Course 2 = 5

Course 3 = 4

Course 3 can only begin after both prerequisites are finished.

```
finish[3] = max(finish[1], finish[2]) + 4
          = max(3,5) + 4
          = 9
```

Hence, we use

```
finish[neighbor] =
max(finish[neighbor],
    finish[current] + time[neighbor - 1])
```

---

## Time Complexity

- Building graph: **O(E)**
- Computing indegree: **O(E)**
- Topological Sort: **O(V + E)**

Overall:

```
O(V + E)
```

where

- `V` = Number of courses
- `E` = Number of relations

---

## Space Complexity

- Adjacency List: **O(E)**
- Indegree Array: **O(V)**
- Finish Array: **O(V)**
- Queue: **O(V)**

Overall:

```
O(V + E)
```

---

## Key Learning

- Topological Sort processes courses in prerequisite order.
- `finish[i]` stores the earliest time to complete course `i`.
- Since courses run in parallel, we take the **maximum** completion time among prerequisites instead of summing all course durations.




#self explaination 
here we are given different realtion and we will have time for each task ans now i want 
for find minimum time to calculate it 

first make adjacent list unordered_map<int , list<int>> adj;
create indegree for (n+1) things and mark them 0 initially 
create a queue 
now put every node in n which has indegree 0 
now create a finish vector of size n+1 
and finish[i] = time [i] 
start bfs while queue not empty 
get the first element 
pop it 
for( auto neighbour : adj[front])
finish[neighbour] = max ( finish([neighbour], finish[front] + time[neighbour-1];
resuce indegreee of that 
and if indegree reduced to zero then push it queue 

at last we have to create answer = ans , finish[i];
