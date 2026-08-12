class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end() ,[](const int &a, const int &b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        string ans = "";

        for (const int &num: nums) {
            ans += to_string(num);
        }

        if(ans[0] == '0')
            return "0";

        return ans;
    }
};