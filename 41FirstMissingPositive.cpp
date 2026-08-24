/*

this is question for which i take help from ai 
question is to find first missing positive index from array we have this question 
first thing come in my mind is to sort the array but we have limit is o(n) 
so we dont want to do unnessary thing we have to be at minimum 
so we go to each number and if if its positive and less than n and nums[i] != i+1 
and at the position where we are swapping not contain exact same number we will swap it 
with swap(nums[i] , nums[nums[i] -1];

now we will start a loop if(nums[j] != j+1) return j+1;
and if not is there found so answer is nums.size() +1 

you can apprach this question without reading it one time 


for each i:

    while current number belongs somewhere else
          and isn't a duplicate:

        put current number into its correct position

then scan:

    if nums[j] != j + 1:
        answer = j + 1

if everything is correct:
    answer = n + 1
*/

/*
LeetCode 41 - First Missing Positive

Idea:
Use the array itself to place each positive number at its correct index.

For a number x:
    x should be at index x - 1

Example:
    1 → index 0
    2 → index 1
    3 → index 2

Steps:
1. Let n = nums.size().
2. For every index i, keep swapping while:
       nums[i] >= 1
       nums[i] <= n
       nums[i] != i + 1
       nums[i] != nums[nums[i] - 1]

   The last condition prevents infinite swapping with duplicates.

3. After rearranging, scan the array:
       if nums[i] != i + 1
           return i + 1;

   Because index i should contain value i + 1.

4. If every position contains its correct value,
   then the first missing positive is n + 1.

Important:
    Use a WHILE for the swapping step.
    One swap can bring another misplaced number
    into the current index.

Example:
    nums = [3, 4, -1, 1]

    Rearrange useful values:
    [1, -1, 3, 4]

    Index 1 should contain 2, but doesn't.
    Answer = 2.

Complexity:
    Time: O(n)
    Space: O(1)

Key formula:
    value x → correct index = x - 1
*/
