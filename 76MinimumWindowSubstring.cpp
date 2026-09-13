/*
=================================================================
MINIMUM WINDOW SUBSTRING - LESSONS LEARNED (Sliding Window Pattern)
=================================================================

PROBLEM: Find the smallest substring in `s` that contains all
characters of `t` (with correct frequency/multiplicity).

-----------------------------------------------------------------
KEY BUGS I FIXED ALONG THE WAY:
-----------------------------------------------------------------

1. ARRAY SIZE / INDEXING
   - Started with vector<int>(26,0) and indexed with `c - 'A'`.
   - Problem: only works for uppercase A-Z. Breaks for lowercase,
     digits, symbols.
   - Fix: use vector<int>(128,0) and index directly with the
     character `c` (its ASCII value IS the index). No `-'A'` needed.

2. SEPARATE ARRAYS FOR "REQUIREMENT" VS "CURRENT WINDOW"
   - `need[]`  = fixed counts required by t. Built ONCE, never
     touched again after initialization.
   - `dq1[]` (window counts) = counts of chars currently inside
     the sliding window [left, right]. This one changes constantly
     as the window expands/shrinks.
   - Mixing these into one array was my original bug — I was
     overwriting the requirement counts with window data.

3. VARIABLE SHADOWING: DECLARING `right` TWICE
   - I had `int right = 0;` outside AND `for(int right=0...)`
     inside — the inner one shadows/hides the outer one.
   - Also had a manual `right++` INSIDE the for-loop body, on top
     of the automatic `right++` in the for-loop header. This made
     right jump by 2 each iteration, skipping characters of s.
   - Fix: only ONE `right`, only ONE place incrementing it (the
     for-loop header handles it automatically).

4. TRACKING "IS WINDOW VALID" WITH `formed` / `required`
   - `required` = number of DISTINCT characters t needs (not total
     count, just how many unique chars must be satisfied).
   - `formed` = how many of those distinct chars are CURRENTLY
     satisfied in the window (dq1[c] == need[c] exactly).
   - When `formed == required`, the window is valid (contains
     everything t needs) → time to try shrinking from the left.

5. EXPAND THEN SHRINK PATTERN
   - Outer for-loop: expand `right` one step at a time, add
     s[right] into dq1, update `formed` if that char just became
     satisfied.
   - Inner while-loop: as LONG as window is valid, try shrinking
     from `left` to find a smaller valid window. Remove s[left]
     from dq1, update `formed` if that char becomes unsatisfied,
     then move left forward.
   - This is a reusable template for many "shrink while valid"
     sliding window problems (longest substring with K distinct,
     smallest subarray with sum >= target, etc).

6. TRACKING THE BEST (MINIMUM) WINDOW — MY REMAINING BUG
   - bestLen starts at INT_MAX (meaning "no valid window found yet").
   - Every time the window is valid, I should check: is THIS
     window's length SMALLER than the best one found so far?
   - I currently wrote: `if (right - left + 1 > bestLen)`
     -> THINK: if bestLen starts at INT_MAX, can any real window
        length ever be BIGGER than INT_MAX? What does that mean
        for whether bestLen ever updates?
   - The comparison operator here needs to check for
     ___________ (smaller? bigger?) than bestLen, since we want
     the MINIMUM window, not the maximum.
   - TODO: fix this comparison before testing.

-----------------------------------------------------------------
NEXT STEP: Fix the comparison in the shrinking loop, then trace
through a small example by hand (e.g. s="ADOBECODEBANC", t="ABC")
to confirm bestStart and bestLen end up correct.
---------------------------------

--------------------------------
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || t.size()  > s.size() ) return "";
        vector<int> need(128,0);
        string ans;
        int left = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;
        for(char c : t){
            need[c]++;
        }

        int required = 0;
        for(int i =0 ; i< 128; i++) if(need[i] > 0) required++;

        int formed = 0; // how many distinct chat currently satify requirement
        vector<int > dq1(128,0);
        for( int right = 0 ; right < s.size() ; right++){
            char c = s[right];
            dq1[c]++;
            if(need[c] > 0 && dq1[c] == need[c]) formed++;

            while(formed == required){
                if(right - left + 1 < bestLen){
                    bestLen = right - left + 1;
                    bestStart = left ;
                }
            
            char lc = s[left];
            dq1[lc]--;
            if(need[lc] > 0 && dq1[lc] < need[lc]) formed--;
            left++;
            }

        }
        return bestLen == INT_MAX ? "": s.substr(bestStart ,bestLen);
    }
};
