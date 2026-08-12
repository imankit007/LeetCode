class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        const int n = fruits.size();
        return getTopLeft(fruits) + getTopRight(fruits) + getBottomLeft(fruits) - 2 *fruits[n-1][n-1];
    }


private:
    int getTopLeft(vector<vector<int>>& fruits){
        int ans = 0;
        for(int i = 0 ; i< fruits.size(); ++i){
            ans += fruits[i][i];
        }
        std::cout << "topleft" << ans;
        return ans;
    }
    int getTopRight(vector<vector<int>>& fruits){
       const int n = fruits.size();
        vector<pair<int,int>> movements({{1,-1}, {1,0},{1,1}});
        vector<vector<int>> dp(n, vector<int>(n,0)) ;
        dp[0][n-1] = fruits[0][n-1];
        for(int x = 0; x<n; ++x ){
            for(int y = 0;y <n; ++y){
                if( x >= y  && !(x == n-1 && y == n-1)){
                    continue;
                }
                for(const auto& [dx, dy] : movements){
                    int i = x - dx;
                    int j = y - dy;
                    if( i < 0 || j < 0 || i == n || j == n ){
                        continue;
                    }
                    if(i < j && j < n - 1 - i){
                        continue;
                    }
                    dp[x][y] = max(dp[x][y],dp[i][j] + fruits[x][y]);
                }
            }
        }
        std::cout << "topright" << dp[n-1][n-1] ;
        return dp[n-1][n-1];
    }

    int getBottomLeft(vector<vector<int>>& fruits){
        const int n = fruits.size();
        vector<pair<int,int>> movements({{-1,1}, {0,1},{1,1}});
        vector<vector<int>> dp(n, vector<int>(n,0)) ;
        dp[n-1][0] = fruits[n-1][0];
        for(int y =0; y<n; ++y ){
            for(int x =0;x <n; ++x){
                if( x <= y && !(x == n-1 && y == n-1 )){
                    continue;
                }
                for(const auto& [dx, dy] : movements){
                    int i = x - dx;
                    int j = y - dy;
                    if( i < 0 || j < 0 || i == n || j == n ){
                        continue;
                    }
                    if( j < i && i < n - 1 - j){
                        continue;
                    }
                    dp[x][y] = max(dp[x][y],dp[i][j] + fruits[x][y]);
                }
            }
        }
         std::cout << "bottomleft" << dp[n-1][n-1] ;
        return dp[n-1][n-1];
    }
};