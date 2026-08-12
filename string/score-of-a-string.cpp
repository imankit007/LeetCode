class Solution {
public:
    int scoreOfString(string s) {
        
        const int n = s.size();
        int ans = 0;
        for(int i = 1; i<n; ++i){
            ans+= abs(s[i-1] - s[i]);
        }

        return ans;

    }
};