class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
    
        vector<int> ans;
        for(int start = 1 ; start<= 8 ; start++){
            int num = start;
              for (int next = start + 1; next <= 9; next++) {
                num = num * 10 + next;

                if (num > high)
                    break;

                if (num >= low)
                    ans.push_back(num);
            }
        }

        ranges::sort(ans);

        return ans;


    }
};