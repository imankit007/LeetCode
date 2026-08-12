class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        const int n = potions.size();
        ranges::sort(potions);
        vector<int> ans;
        for (const int spell : spells) {
            ans.push_back(n - firstIndex(spell, potions, success));
        }
        return ans;
    }

private:
    int firstIndex(int spell, vector<int>& potions, long long target) {
        int l = 0;
        int r = potions.size();
        while (l < r) {
            int m = l + ((r - l) / 2);
            if (static_cast<long long>(spell) * potions[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};