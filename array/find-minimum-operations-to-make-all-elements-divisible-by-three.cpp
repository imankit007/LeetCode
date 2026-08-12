class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int ans = 0 ;

        for(const int &n : nums ){
            ans += min( n % 3 , 3 - (n % 3)   );
        }

        return ans;

    }
};