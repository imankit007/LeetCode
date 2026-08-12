class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        int n = s.length();
        int one = 0;
        for (const char& c : s) {
            if (c == '1')
                ++one;
        }
        string ans = "";
        int i = 0;
        while(i<n){
            if(one>1){
                ans+="1";
                --one;
            }else if(one==1 & i<n-1){
                ans+="0";
            }else{
                ans+="1";
            }

            i++;
        }

        return ans;
    }
};