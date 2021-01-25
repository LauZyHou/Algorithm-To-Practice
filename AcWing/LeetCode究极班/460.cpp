class LFUCache {
public:
    // 内部结点
    struct Node {
        Node *left, *right;
        int key, val;
        Node(int _key, int _val) {
            key = _key, val = _val;
            left = right = nullptr;
        }
    };

    // 外部结点
    struct Block {
        Block *left, *right;
        Node *head, *tail; // 内部双链表的两个哨兵结点
        int cnt; // 访问次数

        ~Block() {
            delete head;
            delete tail;
        }

        Block(int _cnt) {
            cnt = _cnt;
            left = right = nullptr;
            // 初始化内层双链表
            head = new Node(-1, -1), tail = new Node(-1, -1);
            head->right = tail, tail->left = head;
        }

        // 插入一个不存在的node，也就是插入到内层双链表的最左侧
        void insert(Node* p) {
            p->right = head->right, p->left = head;
            head->right->left = p, head->right = p;
        }

        // 删除一个已经存在的node
        void remove(Node* p) {
            p->right->left = p->left;
            p->left->right = p->right;
            // 注意删除掉之后不要把这个node释放，因为是要插入到右边的block里
        }

        // 判断内层双链表是不是空的
        bool empty() {
            return head->right == tail;
        }

    }*head, *tail; // 外部双链表的两个哨兵结点

    int n; // 容量
    unordered_map<int, Block*> hash_block; // 每个数存在哪个block里
    unordered_map<int, Node*> hash_node; // 每个数存在哪个node里

    // 在p的右边插入一个新块，新块的cnt是p的cnt再加1
    void insert_to_right(Block* p) {
        auto t = new Block(p->cnt + 1);
        t->right = p->right, t->left = p;
        p->right->left = t, p->right = t;
    }

    // 在外层双链表里删除一个块
    void remove(Block* p) {
        p->left->right = p->right;
        p->right->left = p->left;
        delete p;
    }

    LFUCache(int capacity) {
        n = capacity;
        //初始化外层双链表
        head = new Block(0), tail = new Block(INT_MAX);
        head->right = tail, tail->left = head;
    }
    
    int get(int key) {
        // 如果key不存在，那么直接返回-1
        if (!hash_block.count(key)) return -1;
        // 找到它对应的block和node
        auto block = hash_block[key];
        auto node = hash_node[key];
        
        // 现在要做的是把访问次数加1
        // 从这个block里把内层node删掉
        block->remove(node);
        // 判断一下block的右侧是不是cnt+1，如果不是，那么要插入一个新块
        if (block->right->cnt != block->cnt + 1)
            insert_to_right(block);
        // 在block右侧的块里加入这个node
        block->right->insert(node);
        // 更新哈希表，由于node没变，只需要改向block的映射
        hash_block[key] = block->right;
        // 由于移出去了一个node，要检查一下当前block是不是空了，空了就删掉
        if (block->empty()) remove(block);

        return node->val;
    }
    
    void put(int key, int value) {
        // 如果n等于0，那么一个都不能存，所以put的操作永远不能执行
        if (n == 0) return ;
        // 如果已经存过了
        if (hash_block.count(key)) {
            // 那么在node里更新一下value
            hash_node[key]->val = value;
            // 更新完之后要让访问次数+1，这里直接调用一下get来实现
            get(key);
        }
        // 至此，没存过这个key
        else {
            // 如果现在已经满了，那么要删掉一个
            if (hash_block.size() == n) {
                // 删掉外层链表最左，的，内层链表的，最右的结点
                auto p = head->right->tail->left;
                head->right->remove(p);
                // 如果删完之后已经空了，那么要把这个外层结点删掉
                if (head->right->empty()) remove(head->right);
                // 同时在哈希表里做删除
                hash_block.erase(p->key);
                hash_node.erase(p->key);
                // 都删干净了在删除p
                delete p;
            }
            // 将这个新的key组成结点插入到1的位置
            auto p = new Node(key, value);
            // 判断一下第一个是不是1，如果不是就创建一个
            if (head->right->cnt != 1) {
                insert_to_right(head); // 由于head就是0，这里插的就是1的块
            }
            // 在这个访问次数为1的block里加入这个node
            head->right->insert(p);
            // 新插入的，要更新一下哈希表
            hash_block[key] = head->right;
            hash_node[key] = p;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */