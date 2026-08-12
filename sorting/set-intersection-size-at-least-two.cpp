class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        set<int> unique;
        stack<vector<int>> st;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] == b[1])
                return a[0] > b[0];
            return a[1] < b[1];
        });
        int a = -1, b = -1;
        int ans = 0;

        for (auto& v : intervals) {
            int start = v[0], end = v[1];
            bool a_in = (a >= start && a <= end);
            bool b_in = (b >= start && b <= end);

            if (a_in && b_in)
                continue;
            else if (b_in) {
                ans++;
                a = b;
                b = end;
            } else { 
                ans += 2;
                a = end - 1;
                b = end;
            }
        }
        return ans;
    }

};