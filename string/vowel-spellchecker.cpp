class Solution {
public:
         unordered_set<string> wordSet;
         unordered_map<string, string> wordMap;
         unordered_map<string,string> vowelMap;

    string toLower(string &word){
        string result = word;

        for(char &ch : result){
            ch = tolower(ch);
        }

        return result;
    }

    string covertVowel(string &word){
        string result  = word;

        for(char &ch : result){
            if(ch =='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u'){
                ch = '*';
            }
        }

        return result;
    }

    string solve(string &query){
        string result = query;
        if(wordSet.count(result)){
            return result;
        }

        string lowerCase= toLower(result);

        if(wordMap.count(lowerCase)){
            return wordMap[lowerCase];
        }
        string vowelCase = covertVowel(lowerCase);
        if(vowelMap.count(vowelCase)){
            return vowelMap[vowelCase];
        }

        return "";
    }
 
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

         for(string word : wordlist){
            if(wordSet.find(word) == wordSet.end()){
                wordSet.insert(word);
            }

            string lowerCase = toLower(word);

            if(wordMap.find(lowerCase) == wordMap.end()){
                wordMap[lowerCase] = word;
            }

            string vowelCase = covertVowel(lowerCase);
             if(vowelMap.find(vowelCase) == vowelMap.end()){
                vowelMap[vowelCase] = word;
             }
         }


        vector<string>result;;

         for(string query : queries){
            result.push_back(solve(query));
         }

         return result;

    }
};