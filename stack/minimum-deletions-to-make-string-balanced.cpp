class Solution {
public:
    int minimumDeletions(string s) {

        const int n = s.size();

        vector<int> left(n);
        int countB = 0;;
        vector<int> right(n);
        int countA =0;
        for (int i = 0; i < n; ++i) {  
            left[i] = countB;
            if (s[i] == 'b')
                countB++;
            
            
        }

        for (int i = n - 1; i >= 0; --i) {    
            right[i] = countA; 
            if (s[i] == 'a')
                countA++;
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            ans = min(ans, left[i] + right[i]);
        }

        return ans;
    }
};