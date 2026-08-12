class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        unordered_map<string, string> graph;
        
        for(int i = 0; i<paths.size() ; i++){
            graph[paths[i][0]] = paths[i][1];
        }


        string curr = paths[0][0];


        while(graph.find(curr)!=graph.end()){
            curr = graph[curr];
        }
        return curr;
    }
};