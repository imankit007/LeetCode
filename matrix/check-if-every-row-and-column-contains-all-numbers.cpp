class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for(int i = 0 ; i<n ; ++i){
            unordered_set<int> seenRow;
            unordered_set<int> seenCol;
            for(int j =0 ; j < n ; ++j){
                seenRow.insert(matrix[i][j]);
                seenCol.insert(matrix[j][i]);
            }
            if(seenRow.size() != n || seenCol.size()!=n){
                return false;
            }
        }




        return true;
    }
};