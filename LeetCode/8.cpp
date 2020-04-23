enum State
{
    start = 0,
    symb = 1,
    num = 2,
    fnl = 3
};

const State trans[4][4] = {
    {start, symb, num, fnl},
    {fnl, fnl, num, fnl},
    {fnl, fnl, num, fnl},
    {fnl, fnl, fnl, fnl}
};

class FSM {
public:
    State state = start;
    bool sign = true; // true:pos, false:neg
    long long val = 0;
    bool die = false; // 越界检查

    static int transId(char c)
    {
        if (c == ' ')
            return 0;
        if (c == '+' || c == '-')
            return 1;
        if ('0' <= c && c <= '9')
            return 2;
        return 3;
    }

    void move(char c)
    {
        if(die)
            return;
        int tid = transId(c);      // 判断字符类型
        state = trans[state][tid]; // 状态转移
        if (state == symb)
        {
            sign = c == '+';
        }
        else if (state == num)
        {
            val = val * 10 + c - '0';
            // 越界判断
            if (sign && INT_MAX < val || !sign && INT_MIN > -val)
                die = true;
        }
        // 对转移到start和fnl的情况什么都不用做
    }
};

class Solution {
public:
    int myAtoi(string str)
    {
        FSM fsm;
        for (char c : str)
        {
            fsm.move(c);
        }
        if(fsm.die)
            return fsm.sign ? INT_MAX : INT_MIN;
        return fsm.sign ? fsm.val : -1 * fsm.val;
    }
};