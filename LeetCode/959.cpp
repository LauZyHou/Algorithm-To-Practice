class US
{
public:
    vector<int> vv; //parent

    US(int n)
    {
        vv = vector<int>(n);
        for (int i = 0; i < n; i++)
            vv[i] = i;
    }

    int find(int num)
    {
        while (vv[num] != num)
        {
            num = vv[num];
        }
        return num;
    }

    void merge(int a, int b)
    {
        int x = find(a);
        int y = find(b);
        vv[x] = y; //a祖先挂到b祖先上
    }

    int count()
    { //统计集合数目
        int ret = 0;
        for (int i = 0; i < vv.size(); i++)
        {
            if (i == vv[i])
                ret++;
        }
        return ret;
    }
};

class Solution
{
public:
    int regionsBySlashes(vector<string> &v)
    {
        int rlen = v.size();
        if (!rlen)
            return 0;
        int clen = v[0].size();
        if (!clen)
            return 0;
        US us(4 * rlen * clen);
        for (int i = 0; i < rlen; i++)
        {
            for (int j = 0; j < clen; j++)
            {
                int loc = 4 * (i * clen + j);
                //单元格内部合并
                switch (v[i][j])
                {
                case '\\':
                    us.merge(loc, loc + 1);
                    us.merge(loc + 2, loc + 3);
                    break;
                case '/':
                    us.merge(loc, loc + 3);
                    us.merge(loc + 1, loc + 2);
                    break;
                default:
                    us.merge(loc, loc + 1);
                    us.merge(loc + 1, loc + 2);
                    us.merge(loc + 2, loc + 3);
                    break;
                }
                //单元格向上侧单元格合并
                if (i > 0)
                    us.merge(loc, loc - 4 * clen + 2);
                //单元格向左合并
                if (j > 0)
                    us.merge(loc + 3, loc - 3);
            }
        }
        return us.count();
    }
};