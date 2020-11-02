    class LRUCache {
    public:
        class Node {
            public:
                int key, val;
                Node* left, *right;
                Node(int _key, int _val) : key(_key), val(_val), left(nullptr), right(nullptr) {}
        } *L, *R; // 两个哨兵结点

        // 从双链表里删除一个元素
        void remove(Node* p) {
            p->left->right = p->right;
            p->right->left = p->left;
        }
        
        // 在双链表的最左侧插入一个元素
        void insert(Node* p) {
            p->right = L->right;
            p->left = L;
            p->right->left = p;
            p->left->right = p;
        }

        int n;
        unordered_map<int, Node*> hash;

        LRUCache(int capacity) {
            n = capacity;
            L = new Node(-1, -1), R = new Node(-1, -1);
            L -> right = R, R -> left = L;
        }
        
        int get(int key) {
            if (!hash.count(key))
                return -1;
            auto p = hash[key];
            // 因为访问了，所以要把它移动到最左边
            remove(p);
            insert(p);
            return p->val;
        }
        
        void put(int key, int value) {
            if (hash.count(key)) { // 表里有这个元素
                auto p = hash[key];
                p->val = value;
                remove(p);
                insert(p);
            }
            else { // 表里没有这个元素
                if (hash.size() == n) { // 表满了，要删除一个最右边的
                    auto p = R->left;
                    hash.erase(p->key);
                    remove(p);
                    delete p;
                }
                // 插入元素
                auto p = new Node(key, value);
                insert(p);
                hash[key] = p;
            }
        }
    };

    /**
    * Your LRUCache object will be instantiated and called as such:
    * LRUCache* obj = new LRUCache(capacity);
    * int param_1 = obj->get(key);
    * obj->put(key,value);
    */