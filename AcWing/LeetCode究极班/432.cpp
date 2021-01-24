class AllOne {
public:
    struct Node {
        Node *left, *right; // 双链表左右指针
        int val; // 值，表示字符串出现次数
        unordered_set<string> S; // 存结点里有哪些字符串

        Node (int _val) {
            val = _val;
            left = right = nullptr;
        }
    }*left, *right; // 双链表的左右边界哨兵，语义上可以表示负无穷和正无穷

    unordered_map<string, Node*> hash;

    /** Initialize your data structure here. */
    AllOne() {
        left = new Node(INT_MIN), right = new Node(INT_MAX);
        left->right = right, right->left = left;
    }

    // 在某个结点的右边插入一条数据，如果之前没有这个值则会创建新结点
    Node* add_to_right(Node* node, string key, int val) {
        // 如果当前点右边的value是预期的，那么就直接插入到右边去
        if (node->right->val == val) ;
        // 如果没有的话，要创建一个新的
        else {
            auto t = new Node(val);
            t->right = node->right;
            t->left = node;
            node->right->left = t;
            node->right = t;
        }
        node->right->S.insert(key);
        return node->right;
    }

    // 在某个结点的左边插入一条数据，如果之前没有这个值则会创建新结点
    Node* add_to_left(Node* node, string key, int val) {
        if (node->left->val == val) ;
        else {
            auto t = new Node(val);
            t->left = node->left;
            t->right = node;
            node->left->right = t;
            node->left = t;
        }
        node->left->S.insert(key);
        return node->left;
    }

    // 从双链表里删除结点
    void remove(Node* node) {
        node->left->right = node->right;
        node->right->left = node->left;
        delete node;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // 如果插入这个字符串不存在的话，就要加这个次数为1的字符串到链表里
        // 在左边界的有右边加入一条次数为1的数据
        if (hash.count(key) == 0) hash[key] = add_to_right(left, key, 1);
        // 如果插入这个字符串已经存在的话
        else {
            // 找到这个字符串所在的结点
            auto t = hash[key];
            // 把这个字符串从结点里删除掉
            t->S.erase(key);
            // 把当前这个字符串加到这个点的右边
            hash[key] = add_to_right(t, key, t->val + 1);
            // 如果移动前那个点t里已经没有字符串了，就要把它从双链表里删除掉
            if (t->S.empty()) remove(t);
        }
        // cout << left->right->val << endl;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        // 如果字符串不存在的话就没法删除
        if (hash.count(key) == 0) return;
        // 如果要删除的字符串已经存在，才能做删除操作
        else {
            // 找到当前字符串所在的结点
            auto t = hash[key];
            // 把它从结点里删除掉
            t->S.erase(key);
            // 如果出现次数是1，还要从哈希表里删除掉
            if (t->val == 1) hash.erase(key);
            // 如果出现次数大于1，那么要做移动结点的操作
            else {
                // 插入到t的左边
                hash[key] = add_to_left(t, key, t->val - 1);
            }
            // 判断结点t是否要删除掉
            if (t->S.empty()) remove(t);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        // 获取最大的一个，也就是从最右侧的有效结点里拿一个字符串出来
        if (right->left != left) return *right->left->S.begin();
        return "";
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        // 获取最小的一个，也就是从最左侧的有效结点里拿出一个字符串出来
        if (left->right != right) return *left->right->S.begin();
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */