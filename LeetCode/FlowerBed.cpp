#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;
        int size = flowerbed.size();

        if (size == 0)
            return false;
        for (int i = 0; i < size && n > 0; i++)
        {
            if (flowerbed[i] == 0)
            {
                if (i == 0)
                {
                    if (size >1 && flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                    else if (size == 1){
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else if (i == size - 1)
                {
                    if (flowerbed[i - 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else
                {
                    if (flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
        }
        return (n == 0);
    }
};

int main(int argc, char const *argv[])
{
    auto sol = new Solution();
    auto flowerbed = vector<int>{0,1,0};
    auto n = 1;
    auto result = sol->canPlaceFlowers(flowerbed, n);

    return 0;
}
