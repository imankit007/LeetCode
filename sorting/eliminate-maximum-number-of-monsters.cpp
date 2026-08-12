class Solution {
public:

    int solve(vector<int>& dist, vector<int>& speed){

      int size = dist.size(); 
      
      vector<int> timeRemaining(size);
      
      for(int i =0; i<size; i++){
        timeRemaining[i]= (dist[i]-1)/speed[i];
      }

      sort(timeRemaining.begin(), timeRemaining.end());

      for(int i=0; i<size; i++){
        if(i> timeRemaining[i])
          return i;
      }
      
        
      return size;
    } 


    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
      return solve(dist, speed);

    }
};