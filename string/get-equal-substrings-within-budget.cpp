class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;

        int left = 0;
        int right = 0;
        int currCost = 0;

        for(; right< s.size(); right++){
                currCost+=abs(s[right] - t[right]);
                while(left <= right &&currCost > maxCost){
                    currCost-=abs(s[left]- t[left]);
                    left++;
                }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};