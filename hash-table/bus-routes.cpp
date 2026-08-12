class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

      if(source==target)return 0;


      int count=0;
      unordered_map<int,vector<int>> graph;
      unordered_set<int> visited;
      for(int i=0; i<routes.size();i++){
        for(int j=0; j<routes[i].size();j++){
          graph[routes[i][j]].push_back(i);
        }
      }
      
      queue<int> q;

      q.push(source);

      while(!q.empty()){
        count++;
        for(int i=q.size(); i>0;--i){
          int route = q.front();
          q.pop();
          for(int it : graph[route]){
            if(visited.insert(it).second){
              for(int it2: routes[it]){
                if(it2==target){
                  return count;
                }
                q.push(it2);
              }
            }
          }
        }

      }

    return -1;
    }
};