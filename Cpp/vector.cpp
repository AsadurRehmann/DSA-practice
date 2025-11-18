#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sum(vector<int> &nums)
{
    int jama = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        jama += nums[i];
    }
    cout << "sum: " << jama;
}

bool duplicate(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}

void reverse(vector<int> &nums)
{
    int temp = 0, start = 0, end = nums.size() - 1;
    while (end > start)
    {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

bool isPrime(vector<int> &nums)
{
    int n = nums[1];
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return true;
        }
    }
    return false;
}

vector<string> pairs(vector<int> &nums, vector<char> &vec2)
{
    vector<string> pairedVector;
    int minSize = min(nums.size(), vec2.size());

    for (int i = 0; i < minSize; i++)
    {
        string temp = to_string(nums[i]);
        temp += vec2[i];
        pairedVector.push_back(temp);
    }
    return pairedVector;
}

vector<int> commonElements(vector<int> &nums, vector<int> &nums2)
{
    vector<int> commons;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums[i] == nums2[j])
            {
                commons.push_back(nums[i]);
            }
        }
    }
    return commons;
}


int main()
{
    vector<int> nums = {10, 20, 30, 0, 50};
    vector<int> nums2 = {1, 2, 3, 0, 50};

    vector<char> vec2 = {'A', 'B', 'C', 'D', 'E'};
    cout << "sum" << endl;
    sum(nums);
    cout << endl;
    cout << "dupliate" << endl;

    cout << duplicate(nums) << endl;
    cout << "reverse" << endl;

    reverse(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << "\nisPrime" << endl;
    cout << isPrime(nums) << endl;

    cout << "PAIRS" << endl;
    vector<string> pairedVector = pairs(nums, vec2);
    for (const string &p : pairedVector)
    {
        cout << p << " ";
    }

    cout << "\nCommon" << endl;
    vector<int> commons = commonElements(nums, nums2);
    for (int i : commons)
    {
        cout << i << " ";
    }
    return 0;
}