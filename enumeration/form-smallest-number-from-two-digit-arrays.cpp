class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {

        set<int> numSet1(nums1.begin(), nums1.end());
        set<int> numSet2(nums2.begin(), nums2.end());

        int i  = 1; 
        while(i<=9){
            if(numSet1.count(i) !=0 && numSet2.count(i)){
                return i;
            }
            ++i;
        }

        int num1 = *numSet1.begin();
        int num2 = *numSet2.begin();

        return min(num1, num2)*10 + max(num1, num2);



       
    }
};