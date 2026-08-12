class Solution {
public:
    int numDecodings(string s) {
        const int n = s.length();
        
        vector<int> dp(n+1);
        dp[n]=1;
        dp[n-1] = check(s[n-1]);

        for(int i = n-2; i>=0; i--){
            if(check(s[i])){
                dp[i]+=dp[i+1];
            }
            if(check(s[i],s[i+1])){
                dp[i]+=dp[i+2];
            }
        }

        return dp[0];

    }

    private: 

        bool check(char c){
            return c!='0';
        }

        bool check(char c1, char c2){
            return c1=='1' || c1=='2' && c2< '7';
        }
};