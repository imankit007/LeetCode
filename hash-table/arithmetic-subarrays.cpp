class Solution {
public:
    bool arithmetic(vector<int> arr){
        if(arr.size()==1 || arr.size()==2) return true;
        int d = arr[1] - arr[0];
        for(int i =2; i<arr.size();i++){
            if(arr[i]-arr[i-1]!=d){
                return false;
            }
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        vector<bool> ans(l.size());
        for(int i =0; i<l.size();i++){
            vector<int> temp;
            for(int j = l[i]; j<=r[i];j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            bool val = arithmetic(temp);
            ans[i]=val;
            temp.clear();
        }

        return ans;
    }
};