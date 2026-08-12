class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int, vector<int>> adj;
        

        for(auto& it: adjacentPairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        auto it = adj.begin();

        for( ; it!=adj.end(); it++){
          if(it->second.size()==1)
            break;
        }

        int curr = it->first;
        ans.push_back(curr);
        int prev = INT_MAX;

        while(ans.size()<adj.size()){
            for(auto& elements:adj[curr]){
              if(elements!=prev){
                ans.push_back(elements);
                prev=curr;
                curr=elements;
                break;
              }
            }

        }
      return ans;
    }
};