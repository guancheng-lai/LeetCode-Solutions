//
//  main.cpp
//  347. Top K Frequent Elements
//
//  Created by Guancheng Lai on 8/10/18.
//  Copyright © 2018 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
using std::cout;
using std::endl;
using std::vector;

bool compareVector(std::pair<int, int> pair1, std::pair<int, int> pair2)
{
    return pair1.second > pair2.second;
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unsigned long size = nums.size();
    std::map<int, int> containNum;
    
    for (int i = 0; i < size; i++)
    {
        if (containNum.find(nums[i]) == containNum.end())
        {
            // Not found
            containNum.insert(std::pair<int, int>(nums[i], 1));
        }
        else
        {
            containNum[nums[i]]++;
        }
    }
    
    vector<std::pair<int, int>> pairs(containNum.begin(), containNum.end());
    
    std::sort(pairs.begin(), pairs.end(), compareVector);
    
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        result.push_back(pairs[i].first);
    }
    
    return result;
}

int main(int argc, const char * argv[])
{
    vector<int> myInts = {1};
    myInts = topKFrequent(myInts, 1);
    
    for (int i = 0; i < myInts.size(); i++)
    {
        cout << myInts[i];
    }
    cout << endl;
}
