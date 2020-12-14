class Solution {
public:
    string num1_19[20] = {
        "One", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
        "Nineteen"
    };

    string num20_90[8] = {
        "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
        "Eighty", "Ninety"
    };

    string num_1000[4] = {
        "Billion ", "Million ", "Thousand ", ""
    };

    // 返回1到999的英文表示
    string get(int x) {
        string res;
        // 几百
        if (x >= 100) {
            res += num1_19[x / 100 - 1] + " Hundred ";
            x %= 100;
        }
        // 超过20的读法
        if (x >= 20) {
            res += num20_90[x / 10 - 2] + " ";
            x %= 10;
        }
        // 说完超过20之后说的个位，或者干脆是说的0~19
        if (x)
            res += num1_19[x - 1] + " ";
        // cout << res << endl;
        return res;
    }

    string numberToWords(int num) {
        if (!num) return "Zero";
        string res;
        // 从Billion开始读，每三位一个循环
        for (int i = 1e9, j = 0; i >= 1; i /= 1000, j ++ ) {
            if (num >= i) {
                res += get(num / i) + num_1000[j];
                num %= i;
            }
        }
        // 由于每次读都在后面加了空格，所以这里要把空格去掉
        res.pop_back();
        return res;
    }
};