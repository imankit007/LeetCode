class Solution {
public:
    char findTheDifference(string s, string t) {
      char c=t[t.length()-1];
    for(int i = 0 ;i<s.length();++i)
      c^=s[i]^t[i];
      return c;
    }
};