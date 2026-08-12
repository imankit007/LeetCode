class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if(bloomDay.size() < static_cast<long>(m) * k)
            return -1;

        int l = ranges::min(bloomDay);
        int r = ranges::max(bloomDay);

        while(l<r){
            int mid = (l + r) /2 ; 
            if(solve(bloomDay, k, mid) >= m){
                r = mid;
            }else{
                l = mid+1;
            }
        }
    return l;
    }

    private:
        int solve(vector<int>& bloomDay, int k, int daysPassed){

            int noOfbouquets = 0;

            int flowersRequired = k;

            for(const int day: bloomDay){
                    
                if(daysPassed < day){
                    flowersRequired = k;
                }else if(--flowersRequired == 0){
                    ++noOfbouquets;
                    flowersRequired=k;
                }
            }
        return noOfbouquets;

        }
};