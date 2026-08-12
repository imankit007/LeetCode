class Graph {
  private:
    vector<vector<pair<int,int>>> graph;
public:
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(auto edge: edges){
          addEdge(edge);
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].emplace_back(edge[1],edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> distance(graph.size(), INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<>> minHeap;

        distance[node1] = 0;
        minHeap.emplace(distance[node1], node1);

        while(!minHeap.empty()){
            const auto [d, u] = minHeap.top();
            minHeap.pop();

            if(u==node2){
              return d;
            }

            for(auto& [v, w]: graph[u] ){
              if(d+w<distance[v]){
                distance[v] = d+w;
                minHeap.emplace(distance[v],v);
              }
            }

        }
        return -1;
    }

  
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */