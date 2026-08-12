class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        const int N = encodedText.size();
        const int cols = N / rows;

        string ans;

        for (int i = 0; i < cols; i++) {
            int row = 0;
            int col = i;

            while (row < rows && col < cols) { 
                ans += encodedText[row * cols + col];  
                row++;
                col++;
            }
        }

        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }

        return ans;
    }
};