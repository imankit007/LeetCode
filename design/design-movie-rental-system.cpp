struct PointHash {
    std::size_t operator()(const pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second));
    }
};

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) : stores(n) {
        for (const vector<int>& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            movieToPriceStore[movie].insert({price, shop});
            movieStoreToPrice[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        int i = 0;

        for (const pair<int, int>& p : movieToPriceStore[movie]) {
            ans.push_back(p.second);
            i++;
            if (i == 5) {
                break;
            }
        }
        return ans;
    }

    void rent(int shop, int movie) {
        const int price = movieStoreToPrice[{shop, movie}];
        movieToPriceStore[movie].erase({price, shop});
        rented.insert(make_pair(price, make_pair(shop, movie)));
    }

    void drop(int shop, int movie) {
        const int price = movieStoreToPrice[{shop, movie}];
        movieToPriceStore[movie].insert({price, shop});
        rented.erase(make_pair(price, make_pair(shop, movie)));
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i = 0;

        for (const auto& [_, sm] : rented) {

            ans.push_back({sm.first, sm.second});

            i++;
            if (i == 5) {
                break;
            }
        }
        return ans;
    }

private:
    const int stores;

    unordered_map<int, set<pair<int, int>>> movieToPriceStore;

    unordered_map<pair<int, int>, int, PointHash> movieStoreToPrice;

    set<pair<int, pair<int, int>>> rented;
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */