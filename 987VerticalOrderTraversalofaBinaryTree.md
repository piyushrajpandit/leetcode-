so we have to mapping this can help 
like first root map to 0 
left to -1 and roght to 1 
and so on 


this is hard question now step step by do it slowly 


you have to map them how to do mapping 
map< int , map<int , vector<int>>> nodes;
first int is  horozontal diatancec and second map int is level and vector int is node 
int query push first element root with level and hd 0
and start a loop till query ! empty 
  now crete a temp store first element query
  remove the fornt of query 
  query ka structure  node (hd, lvl)
  now  create treenode from temp . first 
  similary do for hd and lvl
  now in nodes push the front node value at nodes[hd][lvl].push_back(frontNode->val);
  now if left of front node exist call recurssion by hd-1 and lvl +1
  now if right of front node exost call recurssion by hd+1 and lvl+1

now when one iteration is complete and new query is ready now its time to push data in result vector vector form 
so first create a ans vector and put it in 
we have nodes that is in . (int  , pair(int, vector<int>))
we have to find nodes .second.second that is the vector we will push in answer 
and after that push answer in result 




      
