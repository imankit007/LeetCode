class Solution {
    public long countExcellentPairs(int[] nums, int k) {
        long ans = 0;
        int[] count = new int[32];

        Set<Integer> map = new HashSet<>();

        for (int num : nums) {
            if (map.contains(num))
                continue;
            count[countNoOfBits(num)]++;
            map.add(num);
        }

        for (int i = 1; i < 32; i++) {
            count[i] += count[i - 1];
        }

        for (int num : map) {
            int target = Math.max(1, k - countNoOfBits(num));
            if (target > 32) {
                continue;
            }
            ans += count[31] - count[target - 1];
        }

        return ans;
    }

    private int countNoOfBits(int n) {
        int c = 0;

        while (n > 0) {
            n = n & n - 1;
            c++;
        }
        return c;

    }
}