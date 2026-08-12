class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ans = 1;
        const int size = arr.size();

        if(size<=2){
            return arr[0];
        }

        const int target = size / 4;

        for(int i=1; i<size;i++){
            
            if(arr[i]==arr[i-1]){
                ans++;
            }else{
                ans=1;
            }
            if(ans>target){
                return arr[i];
            }

        }
        return -1;
    }
};