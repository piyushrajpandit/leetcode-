// LeetCode 1203 - Sort Items by Groups Respecting Dependencies
//
// Approach: Topological Sort on TWO graphs
//
// 1. Handle items with group == -1:
//      Give every ungrouped item its own new group.
//
// 2. Build ITEM graph:
//      before item -> current item
//
//      itemAdj[v].push_back(u);
//      itemIndegree[u]++;
//
// 3. Build GROUP graph:
//      If group[u] != group[v]:
//
//      group[v] -> group[u]
//
//      IMPORTANT:
//      Avoid duplicate group edges.
//
//      vector<unordered_set<int>> groupAdj(m);
//
//      if(groupAdj[group[v]].insert(group[u]).second){
//          groupIndegree[group[u]]++;
//      }
//
//      ⭐ HIGHLIGHT:
//      `.insert(x).second` is true only when x is newly inserted.
//      This prevents duplicate group edges from increasing
//      groupIndegree multiple times.
//
// 4. Topologically sort the GROUP graph.
//      Store the result in ansgroup.
//
// 5. Topologically sort the ITEM graph.
//      Store the result in ansitem.
//
// 6. Put items into their corresponding groups:
//
//      groupItem[group[item]].push_back(item);
//
// 7. Traverse groups in topological order.
//      For each group, append all its items to the answer.
//
// 8. If all groups or items were not processed, there is a cycle:
//
//      if(ansgroup.size() != m || ansitem.size() != n)
//          return {};
//
// Final idea:
//
//      Item dependencies → correct item order
//      Group dependencies → correct group order
//      Grouping sorted items → keeps each group together
//
// Time Complexity: O(n + total dependencies)
// Space Complexity: O(n + m + total dependencies)


class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0 ; i< n; i++){
            if(group[i] == -1){
                group[i] = m;
                m++;
            }
        }

        vector<vector<int>> itemAdj(n);
        vector<int> itemIndegree(n);

        vector<unordered_set<int>> groupAdj(m);
        vector<int> groupIndegree(m);
        for(int i =0 ; i< n ; i++){
            int u = i ;
        for(int j =0; j< beforeItems[i].size(); j++){
            int v = beforeItems[i][j];
            
            itemAdj[v].push_back(u);
            itemIndegree[u]++;
            if(group[u] != group[v]){
                if(groupAdj[group[v]].insert(group[u]).second){
                groupIndegree[group[u]]++;
                }
            }
        }
        }
        queue<int> q;
        for(int i =0 ; i< groupIndegree.size(); i++){
            if(groupIndegree[i] == 0 )
                q.push(i);
        }
         queue<int> r;
        for(int i =0 ; i< itemIndegree.size(); i++){
            if(itemIndegree[i] == 0 )
                r.push(i);
        }
        vector<int> ansgroup;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ansgroup.push_back(temp);
            for(auto next : groupAdj[temp]){
            
                groupIndegree[next]--;
                
                if(groupIndegree[next] == 0)
                    q.push(next);
            }
        }
        vector<int> ansitem;
        while(!r.empty()){
            int temp = r.front();
            r.pop();
            ansitem.push_back(temp);
            for(auto next : itemAdj[temp]){
            
                itemIndegree[next]--;
                if(itemIndegree[next] == 0)
                    r.push(next);
            }
        }
        vector<vector<int>> groupItem(m);
        for(auto item: ansitem){
            groupItem[group[item]].push_back(item);
        }
        vector<int> ans;
        for(auto g : ansgroup){
            for(auto item : groupItem[g]){
                ans.push_back(item);
            }
        }
        if(ansgroup.size() != m || ansitem.size() != n)
            return {};
      return ans;
    }
};
