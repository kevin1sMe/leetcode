//
//  leetcode_4.cpp
//  Leetcode
//
//  Created by kevinlin on 2018/11/2.
//  Copyright © 2018年 kevinlin. All rights reserved.
#include <vector>

using std::vector;

class Solution {
public:
    double static findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        while(nums1.size() + nums2.size() > 2){
            //移除最小数
            if(nums1.empty()){
                //min = nums2[0];
                nums2.erase(nums2.begin());
                
            } else if(nums2.empty()){
                //min = nums1[0];
                nums1.erase(nums1.begin());
            }else {
                if(nums1[0] > nums2[0]){
                    nums2.erase(nums2.begin());
                } else{
                    nums1.erase(nums1.begin());
                }
            }
            
            
            //移除最大数
            if(nums1.empty()){
                nums2.pop_back();
            } else if(nums2.empty()){
                nums1.pop_back();
            }else {
                if(nums1.back() > nums2.back()){
                    nums1.pop_back();
                } else{
                    nums2.pop_back();
                }
            }
        }
        //计算中位数
        double sum = 0;
        for(int a: nums1){
            sum += a;
        }
        for(int a: nums2){
            sum += a;
        }
        return sum / (nums1.size() + nums2.size());
    }
};

int main()
{
    vector<int> num1 = {1, 3};
    vector<int> num2 = {2};
    
    Solution::findMedianSortedArrays(num1, num2);
    return 0;
}

