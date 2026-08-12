class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());

        unordered_map<int, int> posToColor;
        unordered_map<int, int> colorToBall;
        for(int i = 0; i< queries.size(); ++i){
            int color = queries[i][1];
            int pos = queries[i][0]; 
            if(posToColor[pos] == 0){
                colorToBall[color]++;
            }else{
                int currColor = posToColor[pos];
                if(--colorToBall[currColor] ==0)
                    colorToBall.erase(currColor);
                ++colorToBall[color];
                
            }
            posToColor[pos] = color;
            ans[i]=colorToBall.size();
        
        }

        return ans;
    }
};