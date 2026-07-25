/*
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> last(256,-1);
    int left=0;
    int answer=0;
    for(int right=0;right<static_cast<int>(s.length());right++)
    {
        unsigned char ch=static_cast<unsigned char>(s[right]);
        // 如果上一次出现的位置在当前窗口内，就移动 left；如果已经在窗口外，就保持 left 不动
        left=max(left,last[ch]+1);
        last[ch]=right;//记录当前的位置；
        answer=max(answer,right-left+1);
    }
    return answer;
}
int main()
{
    string s;
    cout<<"Please enter a string:"<<endl;
    getline(cin,s);
    int res=lengthOfLongestSubstring(s);
    cout<<res<<endl;
    return 0;
}