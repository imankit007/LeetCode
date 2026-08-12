class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> s1;
        for (int i = 0; i < arr1.size(); ++i) {
            int n = arr1[i];
            while (n > 0) {
                s1.insert(n);
                n /= 10;
            }
        }

        int ans = 0;

        for (int i = 0; i < arr2.size(); ++i) {
            int n = arr2[i];
            while (n > 0) {

                if (s1.contains(n)) {
                    ans = max(ans, digits(n));
                }

                n /= 10;
            }
        }
        return ans;
    }

private:
    int digits(int n) {
        int d = 0;
        while (n > 0) {
            ++d;
            n /= 10;
        }

        return d;
    }
};