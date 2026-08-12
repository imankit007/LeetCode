class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int maxNeeded = neededTime[0];
        for (int i = 1; i < n; i++) {
           if(colors[i] == colors[i-1]){
            ans+= min(maxNeeded, neededTime[i]);

            maxNeeded = max(maxNeeded, neededTime[i]);
           }else{
            maxNeeded = neededTime[i];
           }
        }

        return ans;
    }
};