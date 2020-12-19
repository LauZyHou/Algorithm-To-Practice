class Solution {
public:
    string ans;

    string interpret(string command) {
        int i = 0;
        ans = "";
        while (i < command.size()) {
            if (command[i] == 'G') parseG(command, i);
            else if (command[i] == '(' && command[i + 1] == ')') parseLR(command, i);
            else parseLALR(command, i);
        }
        return ans;
    }

    void parseG(string& s, int& u) {
        ans += 'G';
        u ++ ;
    }

    void parseLR(string& s, int& u) {
        ans += 'o';
        u += 2;
    }

    void parseLALR(string& s, int& u) {
        ans += "al";
        u += 4;
    }
};