\/*
================ Job Sequencing with Deadlines =================

Problem:
Each job has:
- id
- deadline
- profit

Each job takes 1 unit of time.
Schedule jobs before their deadlines to maximize total profit.

Greedy Idea:
1. Sort jobs in descending order of profit.
2. Schedule each job in the latest available slot before its deadline.
3. If a slot is found:
      - Schedule the job.
      - Increase job count.
      - Add its profit.

Time Complexity : O(n log n + n * maxDeadline)
Space Complexity: O(maxDeadline)

Pattern:
Greedy + Sorting
==============================================================
*/

class Solution {
public:

    // Sort jobs according to profit (highest first)
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {

        // Step 1: Sort jobs by profit
        sort(arr, arr + n, cmp);

        // Step 2: Find maximum deadline
        int maxiDeadline = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxiDeadline = max(maxiDeadline, arr[i].dead);
        }

        // Step 3: Create schedule array
        vector<int> schedule(maxiDeadline + 1, -1);

        int count = 0;
        int maxProfit = 0;

        // Step 4: Schedule jobs
        for (int i = 0; i < n; i++) {

            int currProfit = arr[i].profit;
            int currJobId = arr[i].id;
            int currDead = arr[i].dead;

            // Try to place the job in the latest possible slot
            for (int k = currDead; k > 0; k--) {

                if (schedule[k] == -1) {

                    schedule[k] = currJobId;
                    count++;
                    maxProfit += currProfit;

                    break;      // Job scheduled
                }
            }
        }

        vector<int> ans;

        ans.push_back(count);
        ans.push_back(maxProfit);

        return ans;
    }
};
