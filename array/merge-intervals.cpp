class Solution {
public:
//Time Complexity = O(n^2)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end(), [](vector<int> &a , vector<int> &b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans = vector<vector<int>>({intervals[0]});
        for(int i = 1; i<intervals.size(); ++i){
            vector<int> prev = ans.back();
            if(intervals[i][0] <= prev[1]){
                ans.pop_back();
                vector<int> curr = vector<int>({prev[0], max(intervals[i][1], prev[1])});
                ans.push_back(curr);  
            }else{
            ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};