#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void shiftLeft(vector<int> &nums, int startIndex)
    {
        for (int i = startIndex; i < nums.size() - 1; i++)
        {
            nums[i] = nums[i + 1];
        }
        nums[nums.size() - 1] = -101;
    }

    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
    
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -101)
                break;
            if (i == nums.size() - 1 || nums[i] != nums[i + 1])
            {
                ans++;
            }
            else
            {
                shiftLeft(nums, i + 1);
                i--;
            }
        }
        return ans;
    }

    int removeDuplicates1(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
    
        int ans = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[ans] = nums[i];
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    vector<int> nums = {1, 2};
    int ans = s->removeDuplicates(nums);
}

//    I = 8
//    K = 5 
/// 1|2|3|4|5|3|4|4|5