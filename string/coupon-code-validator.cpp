class Solution {
public:
    unordered_map<string, int> priorityMap = {
        {"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        const int n = code.size();

        vector<string> coupons[4];
        for (int i = 0; i < n; i++) {
            if (!isActive[i]) {
                continue;
            }
            if (!isValid(code[i])) {
                continue;
            }

            if (!priorityMap.contains(businessLine[i])) {
                continue;
            }
            coupons[priorityMap[businessLine[i]]].push_back(code[i]);
        }
        vector<string> ans;

        for (int i = 0; i < 4; i++) {
            ranges::sort(coupons[i]);
            ans.insert(ans.end(), coupons[i].begin(), coupons[i].end());
        }
        return ans;
    }

private:
    bool isValid(string code) {
        if (code.empty())
            return false;

        for (const char& c : code) {
            if (c == '_' || isalnum(c))
                continue;
            
            return false;
        }
        return true;
    }
};