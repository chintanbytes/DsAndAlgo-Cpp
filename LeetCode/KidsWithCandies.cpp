#include <iostream>
#include <vector>
using namespace std;

class KidsWithCandies
{
public:
    vector<bool> kidsWithCandiesSol(vector<int> &candies, int extraCandies)
    {
        int n = candies.size();
        vector<bool> result = vector<bool>(n, false);
        int max = *max_element(candies.begin(), candies.end());
        for (int i = 0; i <= n - 1; i++)
        {
            if (candies[i] + extraCandies >= max)
            {
                result[i] = true;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    auto candies = vector<int>{2, 3, 5, 1, 3};
    auto cl = new KidsWithCandies();
    cl->kidsWithCandiesSol(candies, 3);
    return 0;
}
