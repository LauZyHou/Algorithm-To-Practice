class Solution {
private:
    enum D {up,down,left,right}; // 方向(上0 下1 左2 右3)
    int m,n;
    int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 这个方向坐标操作
public:
    bool check(vector<vector<int>>& g,D dir,int x,int y) {
        while(0<=x && x<m && 0<=y && y<n) {
            // 这里最后判断一下走过来的这一步有没有问题就行
            if(x==m-1 && y==n-1) {
                switch (g[x][y])
                {
                case 1:
                    return dir==left || dir==right;
                case 2:
                    return dir==up || dir==down;
                case 3:
                    return dir==right || dir==up;
                case 4:
                    return dir==left || dir==up;
                case 5:
                    return dir==down || dir==right;
                case 6:
                    return dir==down || dir==left;
                default:
                    return false;
                }
            }
            switch (g[x][y])
            {
            case 1:
                switch (dir)
                {
                case right:
                case left:
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                default:
                    return false;
                    break;
                }
                break;
            case 2:
                switch (dir)
                {
                case up:
                case down:
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                default:
                    return false;
                    break;
                }
                break;
            case 3:
                switch (dir)
                {
                case right:
                    dir= down;
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                case up:
                    dir = left;
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                default:
                    return false;
                    break;
                }
                break;
            case 4:
                switch (dir)
                {
                case left:
                    dir= down;
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                case up:
                    dir = right;
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                default:
                    return false;
                    break;
                }
                break;
            case 5:
                switch (dir)
                {
                case down:
                    dir= left;
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                case right:
                    dir = up;
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                default:
                    return false;
                    break;
                }
                break;
            case 6:
                switch (dir)
                {
                case down:
                    dir= right;
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                case left:
                    dir = up;
                    x += to[dir][0];
                    y += to[dir][1];
                    break;
                default:
                    return false;
                    break;
                }
                break;
            default:
                break;
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& g) {
        m = g.size();
        if(!m)
            return false;
        n = g[0].size();
        if(!n)
            return false;
        if(m==1 && n==1)
            return true;
        
        int x=0, y=0;
        D dir; // 记录这一步的方向，让下一步知道

        switch (g[0][0])
        {
        case 1:
        case 6:
            dir = right;
            x += to[dir][0];
            y += to[dir][1];
            break;
        case 2:
        case 3:
            dir = down;
            x += to[dir][0];
            y += to[dir][1];
            break;
        case 4: // 4可以有两个方向的check
            return check(g,right,0,1) || check(g,down,1,0);
        default: // 5在左上角是封死的
            return false;
        }
        return check(g,dir,x,y);
    }
};