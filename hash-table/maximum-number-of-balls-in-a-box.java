import java.util.HashMap;

class Solution {
    public int countBalls(int lowLimit, int highLimit) {

        HashMap<Integer, Integer> map = new HashMap<>();

        int n = highLimit - lowLimit + 1;

        for (int i = lowLimit; i <= highLimit; i++) {
            int num = i;
            int sum = 0;
            while (num > 0) {
                sum = sum + (num % 10);
                num = num / 10;
            }

            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }

        int max = Integer.MIN_VALUE;

        for (int i : map.values()) {
            if (max < i) {
                max = i;
            }
        }

        return max;
    }
}