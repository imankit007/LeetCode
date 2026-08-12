class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";

        vector<int> count(26);
        for(const char c: s){
            ++count[c-'a'];
        }
        for(const char c: order){
            while(count[c-'a']-- > 0)
                ans+=c;
        }
        for(char c ='a'; c<='z'; c++)
            while(count[c-'a']-->0)
                ans+=c;

        return ans;
    }
};