class Solution {
public: 
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

        int ans = -1;
        int minDis = INT_MAX;
        int j = 0;
        for(const auto point: points){
          if(x==point[0]||y==point[1]){
              if((abs(x-point[0])+ abs(y-point[1]))<minDis){
                minDis=(abs(x-point[0])+ abs(y-point[1]));
                ans=j;
              }
          }
          j++;
        }


        return ans;
    }
};