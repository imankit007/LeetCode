class Solution {
    public int[] searchRange(int[] nums, int target) {

        int[] result = { -1, -1 };

        int left = 0, right = nums.length-1;


        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                int i = mid;
                while (i >=left && nums[i] == target  ) {
                    result[0] = i;
                    i--;
                }
                i = mid;
                while (i <=right && nums[i] == target ) {
                    result[1] = i;
                    i++;
                }
                
                break;
            } else if (nums[mid]< target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return result;

    }
}