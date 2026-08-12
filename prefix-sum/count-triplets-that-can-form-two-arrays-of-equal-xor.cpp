class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        const int n = arr.size();
        vector<int> prefix(n+1);
        prefix[0] = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        for( int j = 1; j< n; ++j){
            for( int i =0 ; i< j ; ++i){
                int a = prefix[j ] ^ prefix[i ];
                for( int k = j; k < n; ++k){
                    int b = prefix[j ] ^ prefix[ k + 1 ];
                    if(a == b)
                        ++ans;
                }
            }
        }
        return ans;
    }
};