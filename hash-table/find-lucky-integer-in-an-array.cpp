class Solution {
public:
    int findLucky(vector<int>& arr) {
    
        vector<int> count(arr.size() + 1);

        for(const int &n : arr){
            if(n <= arr.size()){
                count[n]++;
            }
        }


        for(int i = count.size() - 1; i >=1; --i){
            if( i == count[i])
                return  i;
        }

        return -1;

      
    }
};