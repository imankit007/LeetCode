class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        const int n = jobDifficulty.size();

        if(n < d){
                return -1;
            }

        vector<vector<int>> dp(n+1, vector<int>(d+1, INT_MAX/2));

        dp[0][0]=0 ;

        for(int i =1; i<=n; i++){
            for(int j = 1; j<=d; j++){
                int maxDif = 0;

                for(int k = i-1; k>=j-1; --k){
                    maxDif = max(maxDif, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[k][j-1] + maxDif);
                }
            }
        }
        
      
    return dp[n][d];
    }
};