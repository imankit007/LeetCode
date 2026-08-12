class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;

        for(int i = 0; i<rating.size()-1; ++i){
            int leftSmaller = 0;
            int leftGreater = 0;

            for(int j = i -1; j>=0; --j){
                    if(rating[j] < rating[i])
                        ++leftSmaller;
                    else if(rating[j] > rating[i])
                        ++leftGreater;
            }   
            int rightSmaller = 0;
            int rightGreater = 0;

            for(int j = i+1; j<rating.size();++j){
                if(rating[j]<rating[i])
                    ++rightSmaller;
                else if(rating[j]>rating[i])
                    ++rightGreater;
            }

            ans+= leftSmaller * rightGreater + leftGreater * rightSmaller;

        }

        return ans;
    }
};