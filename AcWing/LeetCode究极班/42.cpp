class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk; // 单调栈，存柱子下标
        int res = 0;
        for (int i = 0; i < height.size(); i ++) {
            int last = 0; // 存栈顶的右侧一个元素的高度
            // 当栈里有元素，并且栈顶不超过当前柱子高度时
            // 每次枚举栈顶元素，是把栈顶元素右边的凹槽算一下
            while (stk.size() && height[stk.top()] <= height[i]) {
                // 答案要加上栈顶右边元素和当前元素形成的凹槽的面积
                // 这个凹槽的高度是栈顶元素高度减去右边一个元素的高度
                // 这个凹槽的宽度是当前位置-栈顶元素-1
                res += (height[stk.top()] - last) * (i - stk.top() - 1);
                // 更新，下一轮的last为即将弹出的栈顶元素的高度
                last = height[stk.top()];
                // 弹出
                stk.pop();
            }

            // 都弹完之后新的栈顶元素（如果有）比当前元素要高一些，这个部分的形成的凹槽也要算一下
            // 宽度是i-栈顶元素位置-1，高度是当前柱子的高度-栈顶右边一个元素的高度
            if (stk.size())
                res += (height[i] - last) * (i - stk.top() - 1);

            // 每轮结束将当前元素加到栈里去
            stk.push(i);
        }

        return res;
    }
};