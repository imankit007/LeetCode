
class Solution {
public:
    int dp[101][101];
    int getLengthOfOptimalCompression(string s, int k) {

        const int N = s.size();
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
 
        for(int i =1; i<=N; i++){

            for(int j =0; j<=k; j++){
                if(j) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                int count=0, del = 0;

                for(int t = i ; t>0; t--){
                    if(s[i-1]==s[t-1]) count++;
                    else del++;
                    if(j-del<0) break;
                    dp[i][j]= min(dp[i][j], dp[t-1][j-del] + 1 + (count >= 100 ? 3 : count >= 10 ? 2 : count >= 2 ? 1 : 0));
                }
            }
        }
        return dp[N][k];
    }
};