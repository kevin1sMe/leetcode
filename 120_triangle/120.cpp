#include <iostream>
#include <vector>

//三角形寻找最短路径 
//动态规划问题

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        //使用递推，从底向上找最小路径 
        //最底那行最小路径即自身
        //...
        //从倒数第二行开始
        for(int i=triangle.size() - 2; i >=0; i--) {
            for(int j=0; j < triangle[i].size(); ++j) {
                //对于每个元素，查找下面相临两个的最小值
                triangle[i][j] += std::min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }

        return triangle[0][0];
    }
};


int main()
{
    return 0;
}
