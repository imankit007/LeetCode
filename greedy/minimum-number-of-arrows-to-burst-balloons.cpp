class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int ans = 1;

        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        } );
        
        int curr = points[0][1];

        for(int i = 0; i<points.size(); ++i){
            if(curr < points[i][0]){
                ++ans;
                curr = points[i][1];
            }
        }

        return ans;

    }   
};