class Solution {
public:
  int solve(int num){
     int sum = 0;
      int digit;
      while(num>=10){
        while(num>0){
          digit = num%10;
          sum=sum+digit;
          num=num/10;
        }
        num=sum;
        sum=0;
      }
  return num;
  }

    int solve2(int num){

      if(num<9)return num;

      if (num%9==0){
        return 9;
      }else{
        return num%9;
      }


    }

    int addDigits(int num) {

     return solve2(num);

    }
};