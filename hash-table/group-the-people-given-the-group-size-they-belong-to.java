import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {

        List<List<Integer>> answer = new ArrayList<>();
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < groupSizes.length; i++) {
            int current = groupSizes[i];

            List<Integer> list = new ArrayList<>();

            if (map.containsKey(current)) {
                list = map.get(current);
            }

            list.add(i);
            map.put(current, list);

            if (list.size() == current) {
                answer.add(list);
                map.remove(current);
            }

        }
        
        return answer;
    }
}