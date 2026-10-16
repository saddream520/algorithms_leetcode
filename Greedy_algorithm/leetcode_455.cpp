#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 贪心算法
// 455. 分发饼干
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        int sleft = 0;  int gleft = 0;
        vector<int> gCopy = g; vector<int> sCopy = s;
        // 从小到大排序，策略是优先使得最小尺寸的满足胃口最小孩子
        // 这样使得后续孩子的满足，自动递归纳入计数
        sort(gCopy.begin(),gCopy.end());
        sort(sCopy.begin(),sCopy.end());
        while(sleft<s.size()&&gleft<g.size())
        {
            if(gCopy[gleft]<=sCopy[sleft])
            {
                // 这里的原理很显然，假设前两个孩子满足了，如果还剩下别的饼干其实也不用比较了
                // 因为已经从小到大排序了，后续饼干会更大，所以后面尽管还有饼干也不用多次比较
                count++;
                gleft++;
                sleft++;
            }
            // 不合适，换下一个满足
            else
            {
                sleft++;
            }
        }
        return count;
    }
};