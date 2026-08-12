// LeetCode 2115 - Find All Possible Recipes from Given Supplies
//
// Approach: Topological Sort (BFS)
//
// 1. Build a graph where:
//      ingredient -> recipes that need that ingredient.
//
// 2. indegree[recipe] stores how many ingredients are still
//    required to make that recipe.
//
// 3. Put all initially available supplies into a queue.
//
// 4. Process each available item:
//      - Find all recipes that need this item.
//      - Decrease their indegree by 1.
//      - If a recipe's indegree becomes 0, all its ingredients
//        are available, so the recipe can be made.
//
// 5. Add the newly possible recipe to:
//      - ans, because it can be made.
//      - queue, because the recipe itself can now be used
//        as an ingredient for another recipe.
//
// 6. Continue until the queue is empty.
//
// Example:
//      flour + water -> bread
//      bread + cheese -> sandwich
//
// Once bread is created, bread is pushed into the queue so it
// can help create sandwich.
//
// Time Complexity: O(total number of ingredient relationships)
// Space Complexity: O(total number of ingredient relationships)


class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        unordered_map<string , vector<string>> adj;
        unordered_map<string, int> indegree;
        for(int i =0 ; i < recipes.size(); i++){
            indegree[recipes[i]] = 0;
        }
        queue<string> q;
        for(int i =0 ; i< recipes.size(); i++){
      
            for(int j =0 ; j< ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        for(int i =0 ;i < supplies.size(); i++){
            q.push(supplies[i]);
        }
        while(!q.empty()){
            string item = q.front();
            q.pop();
            for(auto next : adj[item]){
                string food = next;
                indegree[food]--;
                if(indegree[food] == 0 ){
                    ans.push_back(food);
                    q.push(food);
                }
            }
        }
      
        return ans;
    }
};
