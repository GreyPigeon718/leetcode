// 寻找两个正序数组的中位数
//时间复杂度O(log(m+n)),空间复杂度O(1)
// class Solution {
// public:
//     int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
//         /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
//          * 这里的 "/" 表示整除
//          * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
//          * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
//          * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
//          * 这样 pivot 本身最大也只能是第 k-1 小的元素
//          * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
//          * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
//          * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
//          */

//         int m = nums1.size();
//         int n = nums2.size();
//         int index1 = 0, index2 = 0;

//         while (true) {
//             // 边界情况
//             if (index1 == m) {
//                 return nums2[index2 + k - 1];
//             }
//             if (index2 == n) {
//                 return nums1[index1 + k - 1];
//             }
//             if (k == 1) {
//                 return min(nums1[index1], nums2[index2]);
//             }

//             // 正常情况
//             int newIndex1 = min(index1 + k / 2 - 1, m - 1);
//             int newIndex2 = min(index2 + k / 2 - 1, n - 1);
//             int pivot1 = nums1[newIndex1];
//             int pivot2 = nums2[newIndex2];
//             if (pivot1 <= pivot2) {
//                 k -= newIndex1 - index1 + 1;
//                 index1 = newIndex1 + 1;
//             }
//             else {
//                 k -= newIndex2 - index2 + 1;
//                 index2 = newIndex2 + 1;
//             }
//         }
//     }

//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int totalLength = nums1.size() + nums2.size();
//         if (totalLength % 2 == 1) {
//             return getKthElement(nums1, nums2, (totalLength + 1) / 2);
//         }
//         else {
//             return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
//         }
//     }
// };
// //时间复杂度O(n+m),空间复杂度O(1);
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         nums1.insert(nums1.end(), nums2.begin(), nums2.end());
//         sort(nums1.begin(), nums1.end());
//         int symbol = nums1.size() % 2 == 0 ? 1 : 0;
//         if (symbol)
//             return (nums1[nums1.size()/2] + nums1[nums1.size()/2-1])/2.0;
//         else
//             return nums1[nums1.size()/2];
//         return 0;
//     }
// };
//最长回文字串 --- 动态规划
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
//盛最多的水
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int res = 0;
        while (start < end)
        {
            int sum =  min(height[start] , height[end]) * (end - start);
            res = max(res,sum);
            if (height[start] <= height[end])
                ++start;
            else
                --end;
        }
        return res;
    }
};
const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        for (const auto &[value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};