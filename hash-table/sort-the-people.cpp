
struct Person {
    int height;
    string name;
};

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<Person> people;

        for (int i = 0; i < names.size(); ++i) {
            people.push_back(Person(heights[i], names[i]));
        }

        sort(people.begin(), people.end(), [](const Person &a, const Person &b){
            return a.height > b.height;
        });

            vector<string>
                ans;

        for (const Person& person : people) {
            ans.push_back(person.name);
        }

        return ans;
    }
};