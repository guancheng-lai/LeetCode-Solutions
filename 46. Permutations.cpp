//
//  main.cpp
//  46. Permutations
//
//  Created by Guancheng Lai on 8/4/18.
//  Copyright © 2018 Guancheng Lai. All rights reserved.
//

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

bool equalVector(vector< vector<int> > v)
{
    return false;
}

void printAllVector(vector< vector<int> > ints)
{
    for (int i = 0; i < ints.size(); i++)
    {
        for (int j = 0; j < ints[0].size(); j++)
        {
            cout << ints[i][j];
        }
        
        cout << endl;
    }
}

bool compareVector(vector<int> numsA, vector<int> numsB)
{
    for (int i = 0; i < numsA.size(); i++)
    {
        if (numsA[i] != numsB[i])
        {
            return numsA[i] < numsB[i];
        }
    }
    return false;
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> numsCopy = nums;
    vector<vector<int>> result;
    
    if (nums.size() == 0)
    {
        return result;
    }
    else if (nums.size() == 1)
    {
        result.push_back(nums);
        return result;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        for (int others = 0; others < nums.size(); others++)
        {
            
                for (int others2 = 0; others2 < nums.size(); others2++)
                {
                    if (i != others2)
                    {
                        std::swap(numsCopy[i], numsCopy[others2]);
                        std::swap(numsCopy[i], numsCopy[others]);
                        result.push_back(numsCopy);
                        numsCopy = nums;
                    }
            }

        }
    }
    
    cout << result.size() << endl;
    printAllVector(result);
    
    std::sort(result.begin(), result.end(), compareVector);
    result.erase(std::unique( result.begin(), result.end() ), result.end());
    
    cout << result.size() << endl;
    printAllVector(result);
    return result;
}

void perm(vector<int> num, int k, unsigned long n, vector<vector<int> > &res){
    if (k == n)
    {
        res.push_back(num);
    }
    else
    {
        for (int i = k; i <= n; i++)
        {
            int tmp = num[k];
            num[k] = num[i];
            num[i] = tmp;
            
            perm(num, k+1, n, res);
            
            tmp = num[k];
            num[k] = num[i];
            num[i] = tmp;
        }
    }
}

vector<vector<int> > permute2(vector<int> &num)
{
    
    vector<vector<int> > res;
    perm(num, 0, (num.size() - 1), res);
    return res;
}


int main(int argc, const char * argv[])
{
    vector<int> ints = {1, 2, 3, 4};
    
    vector<vector<int>> v;
    // permute(ints);
    v = permute2(ints);
    printAllVector(v);
}
