class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size(); // 总数
        // 如果是偶数，要找的中位数就是第total / 2个数和total / 2 + 1个数的平均数
        if (total % 2 == 0) {
            int left = findKthNumber(nums1, 0, nums2, 0, total / 2); // 中位数偏左的数
            int right = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1); // 中位数偏右的数
            return (left + right) / 2.0;
        }
        // 如果是奇数，要找的中位数就是第total / 2 + 1个数
        else {
            return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }

    // 在两个数组中找第k小的数（k从1开始编号），i和j是数组实际逻辑上的开始位置
    int findKthNumber(vector<int>& nums1, int i, vector<int> nums2, int j, int k) {
        // 默认nums1是比nums2短或者一样的，如果不是就交换
        if (nums1.size() - i > nums2.size() - j) // 注意减去偏移量
            return findKthNumber(nums2, j, nums1, i, k);
        // 现在，nums1是较短的数组，如果nums1已经是空的了，那么直接在nums2里找第k个数就行了
        if (nums1.size() - i == 0)
            return nums2[j + k - 1];
        // 递归出口，如果k是1，即找第一个数，那么只要在nums1和和nums2的第一个数里比较一下就行了
        if (k == 1)
            return min(nums1[i], nums2[j]);
        // 下面要进行递归，要分别取第k/2个数进行比较
        // 因为nums1是比较短的，所以剩下的数不够也只有可能是在nums1里发生
        int si = min(i + k / 2, int(nums1.size())) - 1; // nums1里要比较的数所在的下标
        int sj = j + k / 2 - 1; // nums2里要比较的数所在的下标
        // 比较大小，小的部分删去，即从下一个位置开始是剩下的数组
        if (nums1[si] < nums2[sj])
            return findKthNumber(nums1, si + 1, nums2, j, k - (si - i + 1)); // 注意k表示找第几个数，是从1开始的
        else
            return findKthNumber(nums1, i, nums2, sj + 1, k - (sj - j + 1));
    }
};