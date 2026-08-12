class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const vector<pair<int,int>>adj = {{-1,-1},{0,-1} , {1,-1},{-1,0},{1,0}
           ,{-1,1},{0,1},{1,1}};

           const int rows = img.size();
           const int cols = img[0].size();

            vector<vector<int>> ans(rows, vector<int>(cols));

           for(int i =0; i<rows; i++){
               for(int j =0; j<cols; j++){
                   int sum = img[i][j];
                   int cellCount =1;
                    for(auto [dx , dy] : adj){
                        const int X =  j + dx;
                        const int Y  = i + dy;
                    if(isSafe(X, Y, rows, cols)){
                        sum+=img[Y][X];
                        cellCount++;
                    }
                    ans[i][j] = (sum/cellCount);
                    }
                   
               }
           }
           return ans;
    }

private:
    bool isSafe(int currX, int currY, int rows, int cols){
        return currX>=0 && currY>=0 && currY<rows && currX<cols;
    }
};