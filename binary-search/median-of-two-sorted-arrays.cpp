class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        long m = nums1.size() , n  = nums2.size(), t = (n + m +1)/2;
        
        if(m>n) return findMedianSortedArrays(nums2, nums1);
        
        if(m==0) return n%2==0?(double)(nums2[n/2 -1] + nums2[n/2])/2 : nums2[n/2];
        if(n==0) return m%2==0 ? (double) (nums1[m/2 - 1] + nums1[m/2]) / 2 : nums1[m/2];
        
        long left = 0, right = m;
        while(left <= right){
            long partitionA = left + (right - left)/2;
            long partitionB = t - double(partitionA);
            
            double maxLeftA = INT_MIN;
            
            if(partitionA > 0){
                maxLeftA = nums1[partitionA - 1];
            }
            
            double minRightA = INT_MAX;
            if(partitionA < m){
                minRightA =  nums1[partitionA];
            }
            
            double maxLeftB = INT_MIN;
            if(partitionB > 0){
                maxLeftB = nums2[partitionB-1];
            }
            
            double minRightB = INT_MAX;
            if(partitionB < n){
                minRightB = nums2[partitionB];
            }
            
            if(maxLeftA <= minRightB && maxLeftB <= minRightA){
                if((n+m)%2==0){
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB))/ 2.0;
                }else{
                    return max(maxLeftA, maxLeftB);
                }
            }
            else if (maxLeftA > minRightB){
                right = partitionA -1;
            }else{
                left = partitionA + 1;
            }
        }  
        
        return 0.0;
    }
};