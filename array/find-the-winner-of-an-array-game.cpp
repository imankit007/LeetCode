class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        const int n = arr.size();
        int count = 0;

        for(int i =1 ; i<n ; i++){
            if(arr[0] > arr[i])
                count++;
            else{
                swap(arr, 0, i);
                count=1;
            }

            if(count ==k) return arr[0];
        }

        return arr[0];

    }

    private:

    void swap(vector<int>& arr, int i, int j){
        int temp = arr[i];
        arr[i]  = arr[j];
        arr[j] = temp;
    }
};