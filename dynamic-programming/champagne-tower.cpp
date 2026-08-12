class Solution {
public:
    double solve(int poured, int query_row, int query_glass){
      double glass[(query_row+1)*(query_row+2)/2];
      memset(glass,0,sizeof(glass));
      double champagne = poured;
      int index =0;
      glass[index] = champagne;

      for(int i = 1; i<=query_row ;i++){
        for(int j = 1; j<=i; j++, index++){
            champagne = glass[index];
            glass[index]= (champagne>=1.0)? 1.0: champagne;
            champagne = (champagne>=1.0)?(champagne-1):0.0;
            glass[index+ i] += champagne/2;
            glass[index+i+1] += champagne/2;
        }
      }
      if(glass[query_row * (query_row+1)/2 + query_glass]>1)
        return 1.0;
      return glass[query_row * (query_row+1)/2 + query_glass];
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        

          return solve(poured, query_row, query_glass);

    }
};