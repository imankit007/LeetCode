class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        
        ranges::sort(position);

        int l = 1;
        int r = position.back() - position.front();

        while(l<r){
            int mid =r - (r - l) /2;
            if(check(position, mid) >= m){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return l;   
    }
    int check(vector<int>& position, int value){
        int prevPos = -value; 
        int ans = 0;
        const int n = position.size();
        for(const int pos: position){
            if((pos - prevPos )>= value){
                prevPos = pos;
                ++ans;
            }
        }   
        return ans;
    }   
};