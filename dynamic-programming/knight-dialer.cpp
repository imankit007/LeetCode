class Solution {
public:
    int knightDialer(int n) {
      constexpr int kmod = 1e9+7;
      const vector<pair<int,int>> dirs = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
      vector<vector<int>> dp(4, vector<int>(3,1));
      dp[3][0]=dp[3][2]=0;
      for(int i=0; i<n-1; i++){
        vector<vector<int>> temp(4, vector<int>(3));
         for(int row = 0; row<=3; row++){
           for(int col=0; col<=2; col++){
             if(invalid(row, col))
               continue;
             for(const auto& [dx, dy]: dirs){
               const int x = row + dx;
               const int y = col + dy;
               if(x<0 || x>3 ||y<0 || y>2)
                 continue;
               if(invalid(x,y))
                 continue;
               temp[row][col] =(temp[row][col] + dp[x][y])%kmod;
              }
            }
          }
          dp = move(temp);
        } 

        long ans =0;
        for(int i =0 ; i<4; i++){
          for(int j =0; j<3;j++){
            ans=(ans+dp[i][j]) % kmod;
          }
        }
    return ans % kmod;
    }//end of function

    bool invalid(int i, int j){
      return i==3 && (j==0 || j==2);
    }
};