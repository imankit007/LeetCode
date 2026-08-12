class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        ranges::sort(arr);

        vector<vector<int>> ans;

        int diff = INT_MAX;

        for (int i = 1; i < arr.size(); ++i) {
            int curr = abs(arr[i] - arr[i - 1]);
            if (curr < diff) {
                ans.clear();
                diff = curr;
            }
            if (diff == curr){
                ans.push_back({arr[i-1], arr[i]});
            }
            
        }

        return ans;
    }
};