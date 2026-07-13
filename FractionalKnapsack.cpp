/*
================ Fractional Knapsack =================

Problem:
Maximize the total value that can be carried in a knapsack
of capacity W. Fractions of items are allowed.

Greedy Idea:
Always pick the item with the highest value/weight ratio first.

Algorithm:
1. Compute value/weight ratio for every item.
2. Sort items in descending order of ratio.
3. Take the whole item if it fits.
4. Otherwise, take only the required fraction and stop.

Greedy Choice:
Choose the maximum value per unit weight first.

Time Complexity : O(n log n)
Space Complexity: O(n)

Pattern:
Greedy + Sorting

Formula:
Ratio = value / weight
*/

class Solution {
public:

    static bool cmp(pair<double, Item> a, pair<double, Item> b) {
        return a.first > b.first;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {

        vector<pair<double, Item>> v;

        for (int i = 0; i < n; i++) {

            double perUnitValue =
                (1.0 * arr[i].value) / arr[i].weight;

            v.push_back(make_pair(perUnitValue, arr[i]));
        }

        sort(v.begin(), v.end(), cmp);

        double totalValue = 0;

        for (int i = 0; i < n; i++) {

            if (v[i].second.weight > W) {

                totalValue += W * v[i].first;
                W = 0;
                break;
            }
            else {

                totalValue += v[i].second.value;
                W -= v[i].second.weight;
            }
        }

        return totalValue;
    }
};
