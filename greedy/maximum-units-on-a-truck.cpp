class Solution {
public:
   static bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
    return v1[1] > v2[1];
}

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), sortcol);

        for(vector<int> a: boxTypes){
            cout<<"Number"<<a[0]<<"items";
            cout<<a[1]<<endl;
        }


        int boxCount=0;
        int i=0;
        while(truckSize>0&&i<boxTypes.size()){
                if(boxTypes[i][0]>0){
                    boxCount+=boxTypes[i][1];
                    boxTypes[i][0]--;
                    truckSize--;
                }else{
                    i++;
                }
            }
    return boxCount;
    }
};