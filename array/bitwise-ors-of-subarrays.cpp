class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        unordered_set<int> ans;

        unordered_set<int> prevSet;
        for(const int n : arr){

            unordered_set<int> currSet;

            for(const int prev : prevSet ){
                currSet.insert(prev | n);
            }

            currSet.insert(n);
            ans.insert(currSet.begin(), currSet.end());

            prevSet = move(currSet);

        }

        return ans.size();

    }
};