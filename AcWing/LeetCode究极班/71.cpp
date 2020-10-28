class Solution {
public:
    string simplifyPath(string path) {
        // 处理的时候读到'/'截止，所以没有'/'就加上一个比较方便
        if (path.back() != '/')
            path = path + '/';
        string res, name; // 总答案、读的过程中的文件名
        for (auto c : path) {
            // 读到非/
            if (c != '/')
                name += c;
            // 读到/
            else {
                // 上一级目录
                if (name == "..") {
                    while (res.size() && res.back() != '/')
                        res.pop_back();
                    // 去掉'/'，只有一个'/'时也先在这去掉，最后再特判
                    if (res.size())
                        res.pop_back();
                }
                // 当前目录或者连续斜杠
                else if (name == "." || name.empty()) {
                    ; // 就不用处理
                }
                // 都不是前面的特殊情况，即一般情况，就把文件名插入到目录后
                else {
                    res += '/' + name;
                }
                name.clear();
            }
        }

        if (res.empty())
            return "/";
        return res;
    }
};