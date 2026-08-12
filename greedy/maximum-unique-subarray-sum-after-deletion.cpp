class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        set<int> s;

        for(const int& num : nums){
            if(!s.contains(num)){
                s.insert(num);
                maxi = max(maxi, num);
                sum+= max(0, num);
            }

        }

        return maxi<0 ? maxi : sum;
        

    }
};