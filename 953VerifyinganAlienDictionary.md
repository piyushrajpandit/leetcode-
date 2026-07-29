# 953. Verifying an Alien Dictionary

## Approach

This problem is solved by assigning every character in the alien language a **rank** based on the given `order` string and then comparing every pair of adjacent words.

### Idea

- Store the position (rank) of every character in a hash map.
- Compare every adjacent pair of words.
- Find the first position where the two words differ.
- If the first word's character has a greater rank than the second word's character, the words are not sorted.
- If all compared characters are the same, then the shorter word must come first.

---

## Algorithm

1. Create a hash map that stores the rank of every character in `order`.
2. Traverse every adjacent pair of words.
3. Compare the two words character by character.
4. At the first different character:
   - If `rank[first] > rank[second]`, return `false`.
   - Otherwise, stop comparing this pair and move to the next pair.
5. If no different character is found:
   - If the first word is longer than the second word, return `false`.
6. If every adjacent pair is valid, return `true`.

---

## Example

### Input

```text
words = ["hello","leetcode"]

order = "hlabcdefgijkmnopqrstuvwxyz"
```

### Rank Mapping

```text
h -> 0
l -> 1
a -> 2
b -> 3
...
z -> 25
```

### Comparison

```text
hello
leetcode
```

Compare the first characters:

```text
h vs l
```

```text
rank(h) = 0
rank(l) = 1
```

Since

```text
0 < 1
```

the order is correct.

---

## Prefix Case

Consider

```text
words = ["apple", "app"]
```

Comparison:

```text
apple
app
```

The first three characters are the same.

The second word ends first.

Since `"apple"` is longer than `"app"`, the order is invalid.

Return:

```text
false
```

---

## Dry Run

```text
words = ["word", "world", "row"]

order = "worldabcefghijkmnpqstuvxyz"
```

Compare:

```text
word
world
```

Characters:

```text
w == w
o == o
r == r

d vs l
```

Alien ranks:

```text
rank(d) > rank(l)
```

Therefore,

```text
return false
```

---

## Time Complexity

Let:

- `N` = Number of words
- `L` = Average length of a word

Each character is compared at most once.

```text
Time Complexity: O(N × L)
```

---

## Space Complexity

Hash map stores the order of 26 lowercase letters.

```text
Space Complexity: O(1)
```

---

## Key Learning

- Store the alien alphabet order using a hash map.
- Compare words **pair by pair**, not all at once.
- Compare characters from left to right.
- The **first different character** determines the order.
- If one word is a prefix of another, the **shorter word must come first**.
