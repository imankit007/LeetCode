class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> ans;

      const int size = nums.size();

        if(size < 4){
          return ans;
        }
        sort(nums.begin(), nums.end());
        int m,n,i,j;
        long target2;
        for(i=0; i<size-3;++i ){
          if(i>0 && nums[i]==nums[i-1])
              continue;
          for(j = i+1; j<size-2;j++){
              if(j>i+1 && nums[j]==nums[j-1])
                continue;
            m = j+1;
            n = nums.size() -1 ;
            while(m<n){    
              target2 =(long) nums[i]+nums[j]+nums[m]+nums[n];
                if(target2==target){
                  ans.push_back({nums[i], nums[j],nums[m], nums[n]});
                  while(m<n && nums[m]==nums[m+1])
                    m++;
                  while(m<n && nums[n]==nums[n-1])
                    n--;
                  m++;
                  n--;
                }else if(target>target2){
                  m++;
                }else{
                  n--;
                }
            }
          }
        }
        
    return ans;
    }
};