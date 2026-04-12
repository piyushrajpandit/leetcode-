# Decode Ways — LC #91

## Problem
A string of digits maps to letters: `'A'=1, 'B'=2, ..., 'Z'=26`.  
Count how many ways you can decode the string.

**Example:** `"226"` → `["BZ", "VF", "BBF"]` → **3 ways**

---

## Approach: Bottom-Up DP (Space Optimized)

At each position `i`, you have two choices:
- Decode `s[i]` **alone** (single digit) → valid if `d1 >= 1` (not `'0'`)
- Decode `s[i-1..i]` **together** (two digits) → valid if `10 <= d2 <= 26`

### Recurrence
```
dp[i] = (ways using 1 digit) + (ways using 2 digits)
      =      dp[i-1]         +        dp[i-2]
```

Instead of an array, two rolling variables track the last two states:
```
val2 = dp[i-1]   → one step back
val1 = dp[i-2]   → two steps back
```

---

## Code

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s.length() < 1) return 0;
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;

        int val1 = 1;
        int val2 = 1;

        for (int i = 1; i < s.length(); i++) {
            int d1 = s[i] - '0';                        // single digit
            int d2 = (s[i-1] - '0') * 10 + (s[i] - '0'); // two digits
            int val = 0;

            if (d1 >= 1)              val += val2; // s[i] alone is valid
            if (d2 >= 10 && d2 <= 26) val += val1; // s[i-1..i] together is valid

            val1 = val2;
            val2 = val;
        }
        return val2;
    }
};
```

---

## Dry Run

### Case 1: `s = "226"`

**Init:** `val1 = 1, val2 = 1`

| i | d1 | d2 | Condition           | val     | val1 | val2 |
|---|----|----|---------------------|---------|------|------|
| 1 | 2  | 22 | d1≥1 ✅, 10≤22≤26 ✅ | 1+1=**2** | 1  | 2    |
| 2 | 6  | 26 | d1≥1 ✅, 10≤26≤26 ✅ | 2+1=**3** | 2  | 3    |

**Return:** `3` ✅ → `"BZ"`, `"VF"`, `"BBF"`

---

### Case 2: `s = "206"` (tricky zero)

**Init:** `val1 = 1, val2 = 1`

| i | d1 | d2 | Condition              | val   | val1 | val2 |
|---|----|----|------------------------|-------|------|------|
| 1 | 0  | 20 | d1<1 ❌, 10≤20≤26 ✅    | 0+1=**1** | 1 | 1 |
| 2 | 6  | 06 | d1≥1 ✅, d2=6<10 ❌     | 1+0=**1** | 1 | 1 |

**Return:** `1` ✅ → only `"T F"` via `20, 6`

---

### Case 3: `s = "06"` (leading zero)

- `s[0] == '0'` → early return `0` ✅

---

## Edge Cases

| Input  | Output | Reason                          |
|--------|--------|---------------------------------|
| `"0"`  | 0      | Leading zero, no valid decoding |
| `"10"` | 1      | Only `"J"` via `10`             |
| `"27"` | 1      | Only `"BG"`, `27 > 26`          |
| `"11"` | 2      | `"AA"` or `"K"`                 |
| `"100"`| 0      | `"10"` + `"0"` — `0` alone invalid |

---

## The Rolling Variable Trick

```
Before:  val1  val2
After:         val1  val2 (= val)
```

Each position only depends on the **previous two values** — same pattern as Fibonacci.  
No need for a full dp array.

---

## Complexity

| | |
|---|---|
| **Time**  | O(n) — single pass through string |
| **Space** | O(1) — only two integer variables |

---

## Key Takeaways

1. **`d1 >= 1`** guards against standalone `'0'` which has no mapping.
2. **`d2 >= 10`** guards against invalid pairs like `"06"` (leading zero in pair).
3. **`d2 <= 26`** ensures the pair maps to a valid letter (max is `'Z' = 26`).
4. The problem reduces to **Fibonacci-style DP** once you see the two-choice structure.
