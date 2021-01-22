class RandomizedCollection {
public:
    // 哈希表套哈希表，存在数组中出现的下标
    unordered_map<int, unordered_set<int>> hash;
    // 数组，里面存元素的值
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int x) {
        // 看一下x有没有出现过
        bool res = hash[x].empty();
        // 先将x加入到数组里面
        nums.push_back(x);
        // 记录一下x出现的位置
        hash[x].insert(nums.size() - 1);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int x) {
        // 删除前要判断x是不是存在的，如果不存在直接返回
        if (hash[x].empty()) return false;
        // 随便找一个x出现的位置，这里直接取第一个
        int px = *hash[x].begin();
        // 数组末尾的位置
        int py = nums.size() - 1;
        // 数组最后一个树
        int y = nums.back();
        // 将px位置的x交换到末尾
        swap(nums[px], nums[py]);
        // 注意哈希表里也要交换
        hash[x].erase(px); hash[x].insert(py);
        hash[y].erase(py); hash[y].insert(px);
        // 然后将末尾的元素删除掉
        nums.pop_back();
        hash[x].erase(py);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */