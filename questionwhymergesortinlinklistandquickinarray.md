Why Merge Sort is preferred for Linked Lists
1. Merging is extremely easy

In a linked list you already have pointers. During merge you just change next pointers.

Example idea:

A -> 1 -> 5 -> 7
B -> 2 -> 3 -> 8

Result:
1 -> 2 -> 3 -> 5 -> 7 -> 8

You simply move pointers around. No element shifting. No extra copying.

Time stays:

O(n log n)

2. No random access needed

Linked lists cannot access elements by index.

Getting the 500th element means walking through 499 nodes first.

Merge sort works perfectly because it processes sequentially.

3. Splitting the list is easy

You can find the middle using the slow/fast pointer technique.

Example:

slow = slow->next
fast = fast->next->next

When fast reaches end, slow is at middle.

Clean and efficient.

4. Quick Sort becomes inefficient

Quick sort requires:

Frequent random access

Lots of swapping elements

But in linked lists:

swapping values is awkward

swapping nodes is complex

finding partition boundaries costs time

So quick sort loses its advantage.

Why Quick Sort is preferred for Arrays
1. Arrays support random access

Accessing element arr[i] is O(1).

Quick sort depends heavily on this.

2. Swapping is trivial
swap(arr[i], arr[j])

Just exchange two values. Done.

In linked lists you'd have to rewire pointers.

3. Cache efficiency

Arrays are stored contiguously in memory.

Quick sort benefits from CPU cache and becomes very fast in practice.

Linked lists are scattered in memory. Cache hates that.

4. No extra memory

Merge sort on arrays requires O(n) extra space for merging.

Quick sort works in-place:

Space complexity:

O(log n) (recursion stack)
