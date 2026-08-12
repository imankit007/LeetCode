class Solution {
public:
    double average(vector<int>& salary) {

     double sum;
     int len = salary.size();

    int maxSal=INT_MIN;
    int minSal=INT_MAX;

     for(int i=0; i<len;i++){
        maxSal=max(maxSal,salary[i]);
        minSal=min(minSal,salary[i]);
        sum+=salary[i];
     }
     sum-=(maxSal+minSal);
      return sum/(len-2);
    }
};