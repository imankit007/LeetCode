class Solution {
public:
    int minSteps(string s, string t) {
        
        unordered_map<char, int> freq;
        for(const char c: s){
            freq[c]++;
        }
        for(const char c: t){
            freq[c]--;
        }
        int ans = 0;
        for(auto it = freq.begin(); it!=freq.end(); it++){
            ans += abs(it->second );
        }
            return ans/2;
    }
};