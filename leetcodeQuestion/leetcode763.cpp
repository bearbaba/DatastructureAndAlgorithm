/* 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

 

示例：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
      int ss[26];
      for (int i = 0; i < S.length(); i++)
      {
        ss[S[i]-'a'] = i;
      }

      vector<int> ans;
      int start = 0;
      int end = 0;
      for (int i = 0; i < S.length();i++){
        end = max(end, ss[S[i]-'a']);
        if(end==i){
          ans.push_back(end - start + 1);
          start = end + 1;
        }

        
      }
      return ans;
    }
};

/*
* 这题需要将每个字母能够达到的最远距离首先记录下来，
* 遍历时下标抵达最远距离时并且在这个字母之前并没有其它字母的最远距离能够超过该距离，那么就会将 最远距离 end - 起始位置 start 后 +1记录， 同时新的起点为 end 的后一个位置。
*/
