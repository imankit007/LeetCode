class Solution {
public:
    bool isPathCrossing(string path) { 
        
        set<pair<int, int>> visited;

        pair<int,int> curr = {0,0};

        visited.insert(curr);

        for(const char c: path){
            if(c=='N'){
                curr.second++;
            }else if(c=='E'){
                curr.first++;
            }else if(c=='S'){
                curr.second--;
            }else{
                curr.first--;
            }
            if(!visited.insert(curr).second){
                return true;
            }
        }
        return false;
    }
};