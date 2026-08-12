class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int> unique(arr.begin(), arr.end());
        
        unordered_map<int, int> rank;


        int r = 1;

        for(int n : unique){
            rank[n] = r++;
        }
        vector<int> ans;

        for(int n : arr){
            ans.push_back(rank[n]);
        }

        return ans;
    }
};