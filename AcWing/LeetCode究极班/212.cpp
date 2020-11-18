// 在格子里枚举起点然后枚举四个方向
// 所有单词放到Trie里，保证一定在Trie树里走
// 开一个哈希表，把所有遍历到的单词存下来

class Solution {
public:
    // Trie结点
    struct Node {
        int id; // 单词在words中的下标，-1表示不存在以这个结点结尾的单词
        Node* son[26];
        Node() {
            id = -1;
            memset(son, 0, sizeof son);
        }
    }*root;

    // 在Trie树中插入单词
    void insert(string w, int id) {
        auto p = root;
        for (char c: w) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->id = id; // 记录单词的id
    }

    vector<vector<char>> g; // board
    unordered_set<int> ids; // 答案的单词的id集合

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        // 插入单词
        for (int i = 0; i < words.size(); i ++ )
            insert(words[i], i);

        // 遍历所有可能的起点做dfs
        g = board;
        for (int i = 0; i < g.size(); i ++ ) {
            for (int j = 0; j < g[0].size(); j ++ ) {
                char c = g[i][j];
                int u = c - 'a';
                if (root->son[u]) { // 检查是否可以作为起点
                    dfs(root->son[u], i, j);
                }
            }
        }

        vector<string> res;
        for (auto id: ids)
            res.emplace_back(words[id]);
        return res;
    }

    // 四个方向
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    // 从图的x,y位置，Trie树的p位置深搜
    void dfs(Node* p, int x, int y) {
        // 记录这个地方搜索过了
        char c = g[x][y];
        g[x][y] = '.';
        // 就算找到一个也要继续往下搜索其他的可能，所以这里不break
        if (p->id != -1) {
            ids.insert(p->id);
        }
        // 向四个方向搜索
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < g.size() && b >= 0 && b < g[0].size() && g[a][b] != '.') {
                int u = g[a][b] - 'a';
                if (p->son[u])
                    dfs(p->son[u], a, b);
            }
        }
        // 恢复现场
        g[x][y] = c;
    }
};