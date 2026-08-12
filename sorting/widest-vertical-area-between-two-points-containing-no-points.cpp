class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        vector<int> x;

        for(auto& point : points){
            x.push_back(point[0]);
        }

        ranges::sort(x);
        int ans = 0;
        for(int i = 1; i<points.size(); i++){
            ans = max(ans, x[i]- x[i-1]);
        }

    return ans;

    }
};