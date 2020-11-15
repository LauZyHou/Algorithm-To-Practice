class OrderedStream {
private:
    unordered_map<int, string> hash;
    int ptr;
public:
    OrderedStream(int _n) {
        hash = unordered_map<int, string>();
        ptr = 1;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> res;
        hash[id] = value;
        if (id == ptr) {
            while (hash.count(id)) {
                res.emplace_back(hash[id ++]);
            }
            ptr = id;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */