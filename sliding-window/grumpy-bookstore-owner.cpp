class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0 ;
        const int n = customers.size();
        int currMax = 0;
        int curr = 0;
        for(int i = 0; i< n ; ++i ){
            if(grumpy[i] == 0)
                ans+=customers[i];
            if(grumpy[i] == 1)
                curr+= customers[i];
            if(i >= minutes && grumpy[i-minutes] == 1){
                curr -= customers[i -minutes];
            }
            currMax = max(currMax, curr);
        }
        return ans + currMax;
    }
};