class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
       
        stack<int> st;
        vector<int> result;
        
        int sz = heights.size();
        
        result.push_back(0);
        
        st.push(heights[sz-1]);
        
        for(int i =sz-2; i>=0;i--){
            int count=0;
            while(!st.empty()&& st.top() < heights[i]){
                count++;
                st.pop();
            }
            
            if(!st.empty()) count++;
            result.push_back(count);
            st.push(heights[i]);
        }
          
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};