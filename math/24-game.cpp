class Solution {
public:
    bool judgePoint24(vector<int>& cards) {

        vector<double> numList(cards.begin(), cards.end());
        return dfs(numList);
    }

private:
    bool dfs(vector<double>& nums) {
        if (nums.size() == 0) {
            return false;
        }

        if (nums.size() == 1) {
            return abs(nums[0] - 24) < 1e-6;
        }

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                for (const double num : generate(nums[i], nums[j])) {
                    vector<double> nextRound{num};
                    for (int k = 0; k < nums.size(); ++k) {
                        if (k == i || k == j)
                            continue;
                        nextRound.push_back(nums[k]);
                    }

                    if (dfs(nextRound)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    vector<double> generate( double a,  double b){
        return {a+b, a - b, b - a, a * b , a / b , b / a};
    }
};