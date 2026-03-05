//LeetCode1758
//https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2026-03-05

/*
给你一个仅由字符 '0' 和 '1' 组成的字符串 s 。一步操作中，你可以将任一 '0' 变成 '1' ，或者将 '1' 变成 '0' 。

交替字符串 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 "010" 是交替字符串，而字符串 "0100" 不是。

返回使 s 变成 交替字符串 所需的 最少 操作数。



示例 1：

输入：s = "0100"
输出：1
解释：如果将最后一个字符变为 '1' ，s 就变成 "0101" ，即符合交替字符串定义。
*/
#include <iostream>

using namespace std;


int minOperations(string s) {
    int count0 = 0, count1 = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && s[i] != '0') count0++;
        if (i % 2 != 0 && s[i] != '1') count0++;
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0 && s[i] != '0') count1++;
        if (i % 2 == 0 && s[i] != '1') count1++;
    }
    int ans = min(count0, count1);
    return ans;
}
int main() {
    string s;
    cin >> s;
    int ans = minOperations(s);
    cout << ans;
}