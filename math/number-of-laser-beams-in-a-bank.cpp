class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        const int rows = bank.size();
        int ans = 0;
        vector<int> count;
        for(const string s : bank){
            int temp = 0;
            for(const char c: s ){
                if(c=='1'){
                temp++;
                }   
            }
            if(temp>0)
            count.push_back(temp);
        }
        
        for(int i =1; i<count.size(); i++){
            ans = ans + (count[i]* count[i-1]);
        }
        return ans;
    }
};