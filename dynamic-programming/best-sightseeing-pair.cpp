class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        /* we can divide the given formula in two parts:
            left: values[i]+i
            right: values[i]-i

            to find the solution we need to maximize the left part of the formula
        */
        int res=0;  //
        int maxleft=0;  //in this we are storing the max of the values of values[i]+i we obtained in previous iterations

        for(int i=0; i<values.size();i++){
            res=max(res, maxleft+values[i]-i);
            maxleft=max(maxleft,values[i]+i);
        }
        return res;

    }
};