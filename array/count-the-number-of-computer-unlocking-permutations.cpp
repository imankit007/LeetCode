class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        constexpr int kMod = 1e9 + 7;

        long long ans = 1;

        for (int i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }

            ans = (ans * i) % kMod;
        }

        return static_cast<int>(ans);
    }
};