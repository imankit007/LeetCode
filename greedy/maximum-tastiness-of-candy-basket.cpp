class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());

        int l=0, r=1e9,ans=0;
        
        while(l<=r){
          int mid = (l+r)/2, count=1,last=price[0];
          
          for(int i =0; i<price.size();++i){
            if(price[i]-last>=mid){
              last=price[i];
              count++;
            }
          }

          if(count>=k){
            ans = mid;
            l=mid+1;
          }else{
            r=mid-1;
          }
        }
return ans;
        

    }
};