class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {

        double ans = 0.0;

        for (const vector<int>& A : points) {
            for (const vector<int>& B : points) {
                for (const vector<int>& C : points) {

                    ans = max(ans, 0.5 * abs(((A[0] - C[0]) * (B[1] - C[1])) -
                                             ((B[0] - C[0]) * (A[1] - C[1]))));
                }
            }
        }

        return ans;
    }
};