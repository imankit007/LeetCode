class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ranges::sort(g);
        ranges::sort(s);
        int ans = 0;
        for(int i =0 , j=0; i<g.size() && j<s.size(); ){
            if(g[i]<=s[j]){
                ans++;
                j++;
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};