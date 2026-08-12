class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        const int n = matrix[0].size();
        vector<int> hist(n);

        for(const vector<int>& row: matrix){

            for(int i =0; i<n;++i)
              hist[i] = row[i]==0 ? 0 : hist[i]+1;
            
            vector<int> sorted(hist);
            ranges::sort(sorted);

            for(int i =0; i<n; i++)
              ans = max(ans, sorted[i]*(n-i));
        }
        
  return ans;
    }
};