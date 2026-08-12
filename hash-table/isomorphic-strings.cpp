class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_map<char, bool> n;   
        for (int i = 0; i < s.length(); ++i) {
            auto it = m.find(s[i]);
            if  (it == m.end()) {
                m[s[i]] = t[i];
                if(n[t[i]]==true)
                    return false;
                n[t[i]] = true;
            } else {
                if (it->second != t[i])
                    return false;
            }
        }

        return true;
    }
};