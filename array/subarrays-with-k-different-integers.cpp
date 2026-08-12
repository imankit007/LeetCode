class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums,k-1);
    }

    private: 
        int solve(const vector<int>& nums, int k){
            const int n =nums.size();
            vector<int>count(n+1);
            int ans = 0;

            for(int l =0, r = 0; r<n; ++r){
                if(++count[nums[r]]==1)
                    --k;
                while(k==-1){
                    if(--count[nums[l++]]==0)
                        ++k;
                }
                ans += r -l +1;
            }
    return ans;
        }
};