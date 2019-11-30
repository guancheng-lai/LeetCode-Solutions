//
//  main.cpp
//  238. Product of Array Except Self
//
//  Created by Guancheng Lai on 8/10/18.
//  Copyright © 2018 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;


int sum(vector<int>& nums)
{
    int result = 1;
    unsigned long size = nums.size();
    for (int i = 0; i < size; i++)
    {
        result *= nums[i];
    }
    return result;
}

vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> result;
    int previousElement = 1;
    int forwardElement = sum(nums);
    
    vector<int> reverseNums = nums;
    // std::reverse_copy(nums.begin() + 1, nums.end(), reverseNums);
    std::reverse(reverseNums.begin(), reverseNums.end());
    reverseNums.pop_back();
    
    for (int i = 0; i < nums.size(); i++)
    {
        int element = previousElement * sum(reverseNums);
        result.push_back(element);
        previousElement *= nums[i];
        
        if (reverseNums.size() > 0)
        {
            reverseNums.pop_back();
        }
        
        forwardElement = sum(reverseNums);
        
    }
    
    
    
    return result;
}

int main(int argc, const char * argv[])
{
    vector<int> myInts = {1, 2 ,3 ,4};
    myInts = productExceptSelf(myInts);
    
    for (auto ints: myInts)
    {
        cout << ints;
    }
    cout << endl;
}
