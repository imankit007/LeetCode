class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<pair<int,int>> temp;
        int n = score.size();
        
        for(int i=0; i<n; i++){
            temp.push_back(make_pair(score[i], i));
        }
        
        sort(temp.rbegin(),temp.rend());
        
        vector<string> ans(n);
        
        ans[temp[0].second] = "Gold Medal";
        
        if(n>=2){
            ans[temp[1].second] = "Silver Medal";
        }
        if(n >= 3){
            ans[temp[2].second] = "Bronze Medal";
        }
        for(int i = 3; i<n; i++){
            ans[temp[i].second] = to_string(i +1);
        }
        
        return ans;
        
    }
};