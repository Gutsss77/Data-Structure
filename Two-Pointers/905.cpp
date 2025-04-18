// Sort Array By Parity

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;

        while (i < j)
        {
            if (nums[i] % 2 > nums[j] % 2)
            {
                swap(nums[i], nums[j]);
            }
            if (nums[i] % 2 == 0)
                i++;
            if (nums[j] % 2 != 0)
                j--;
        }

        return nums;
    }
};

int main()
{
    vector<int> arr = {3,1,2,4};

    Solution s;
    vector<int> ans;
    ans = s.sortArrayByParity(arr);
    for (int &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}