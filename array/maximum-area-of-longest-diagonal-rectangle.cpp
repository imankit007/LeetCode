class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int ans = 0;

        double maxDiag = 0;

        for (const vector<int>& rect : dimensions) {
            const int l = rect[0];
            const int b = rect[1];

            double diag = sqrt((l * l) + (b * b));

            if ( diag > maxDiag || (diag == maxDiag && l *b > ans)) {
                ans = l * b;
                maxDiag = diag;
            }
        }

        return ans;
    }
};