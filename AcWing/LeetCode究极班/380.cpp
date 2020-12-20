class RandomizedSet {
public:
    unordered_map<int, unordered_set<int>> hash;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedSet() {
        hash.clear();
        nums.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int x) {
        // 先看一下x里面有没有数
        if (!hash[x].empty()) return false;
        nums.push_back(x);
        hash[x].insert(nums.size() - 1);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int x) {
        if (hash[x].size()) {
            // 把x所在的位置和数组最后一个位置交换一下
            int px = *hash[x].begin(), py = nums.size() - 1;
            // y是数组最后一个数
            int y = nums.back();
            // 先在数组里交换一下
            swap(nums[px], nums[py]);
            // 在x的哈希表中删除px，加入py
            hash[x].erase(px), hash[x].insert(py);
            // 在y的哈希表中删除py，加入px
            hash[y].erase(py), hash[y].insert(px);
            // 至此，x已经在数组最后面了，而且系统处于一致的状态，现在把他删除
            nums.pop_back();
            hash[x].erase(py);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // rand()在win里面返回的范围比较小，当数组长度太长的时候后面的数是随机不到的
        // 这个时候可以看一下rand()能随机多少位，然后把自己要的位数按这个拼一下
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */