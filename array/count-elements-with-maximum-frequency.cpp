class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int curr = 0;
        int ans = 0;
        for(const int& n: nums ){
            ++freq[n];
            int frequency = freq[n];

            if(frequency > curr){
                curr = frequency;
                ans = frequency;
            }else if(frequency == curr){
                ans += frequency;
            }

        }

       return ans;
    }
};