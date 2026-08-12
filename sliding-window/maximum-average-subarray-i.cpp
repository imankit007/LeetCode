class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = k;

        int sum = 0;

        for(int n = i; n<j; n++){
            sum+=nums[n];
        }
        double ans = (double)sum/k; 


        for(int n = j ; n<nums.size();n++){
            sum-=nums[i++];
            sum+=nums[n];
             double avg = (double)sum/(double)k;
             if(avg>ans)
              ans = avg;
            
        }

        return ans;
    }
};