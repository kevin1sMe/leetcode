#include <vector>
#include <assert.h>
#include <algorithm>
#include <iostream>

//DP

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int* dp_max = new int[nums.size()];
        int* dp_min = new int[nums.size()];

        for(size_t i=0; i < nums.size(); ++i) {
            cout<<"nums["<<i<<"] ==> " <<nums[i]<<endl;
            if(0 == i) {
                dp_max[i] = nums[i];
                dp_min[i] = nums[i];
            } else {
                if(nums[i] >= 0) {
                    dp_max[i] = std::max(dp_max[i-1] * nums[i], nums[i]);
                    dp_min[i] = std::min(dp_min[i-1] * nums[i], nums[i]);
                    cout<<">=0, dp_max["<<i<<"] = " <<dp_max[i]<<endl;
                    cout<<">=0, dp_min["<<i<<"] = " <<dp_min[i]<<endl;
                } else {
                    dp_max[i] = std::max(dp_min[i - 1] * nums[i], nums[i]);
                    dp_min[i] = std::min(dp_max[i - 1] * nums[i], nums[i]);
                    cout<<"<0, dp_max["<<i<<"] = " <<dp_max[i]<<endl;
                    cout<<"<0, dp_min["<<i<<"] = " <<dp_min[i]<<endl;
                }
            }
            cout<<"----------"<<endl;
        }
        return *std::max_element(dp_max, dp_max + nums.size());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    assert(sol.maxProduct(nums) == 6);

    vector<int> case2 = {-2, 0,  -1};
    cout<<sol.maxProduct(case2)<<endl;

    vector<int> case3 = {-2, -5, 1, -6};
    cout<<sol.maxProduct(case3)<<endl;
    return 0;
}
