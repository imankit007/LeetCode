class Solution {
public:
    int reachNumber(int target) {
        
        int count=0, sum=0;
        target = target>0?target:-1*target;
        while(sum<target){
            count++;
            sum+=count;
        }
        
        while((sum-target)%2!=0){
            count++;
            sum+=count;
        }
        
        return count;
    }
};