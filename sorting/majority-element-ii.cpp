class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        int minCount = size /3;

        int num1 = 0;
        int num2 = 1;
        int countNum1 = 0;
        int countNum2 =0;

        for(int n: nums){
          if(n == num1){
            countNum1++;
          }else if(n ==num2){
            countNum2++;
          }else if(countNum1==0){
            num1=n;
            countNum1++;
          }else if(countNum2==0){
            num2=n;
            countNum2++;
          }else{
            countNum1--;
            countNum2--;
          }
        }

      int count1 = count(nums.begin(),nums.end(),num1);
      int count2 = count(nums.begin(),nums.end(),num2);

      if(count1>minCount){
        ans.push_back(num1);
      }
      if(count2>minCount){
        ans.push_back(num2);
      }

        return ans;

    }
};