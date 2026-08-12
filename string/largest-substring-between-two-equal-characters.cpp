class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        int i = 0;
        int ans = 0;
        for(const char c : s ){
            if(first[c - 'a']==-1){
                first[c-'a'] = i;
            }else{
                int diff = i - first[c - 'a'];
                ans = max(ans, diff);
            }
            i++;
        }


  

    return ans - 1;
    }
};