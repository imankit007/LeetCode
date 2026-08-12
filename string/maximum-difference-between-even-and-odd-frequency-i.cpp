class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);

        int odd = 0;
        int even = INT_MAX;
        for(const char c : s){
            ++freq[c - 'a'];
        }
        for(const int n : freq ){
            if(n&1){
                odd = max(odd, n);
            }else if(n!=0){
                even = min(even, n);
            }
        }

        return odd - even;
    }
};