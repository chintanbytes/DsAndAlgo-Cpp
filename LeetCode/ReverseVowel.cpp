#include <iostream>
#include <string>
using namespace std;

class Solution
{
private:
    bool isVowel(char ch)
    {
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    string reverseVowels(string s)
    {
        auto size = s.size();
        auto first = 0;
        auto last = size - 1;
        char temp = '\0';

        while (first < last)
        {
            while (first < last && !isVowel(s[first]))
            {
                first++;
            }

            while (first < last && !isVowel(s[last]))
            {
                last--;
            }

            if (first < last)
                swap(s[first++], s[last--]);
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    auto sol = Solution();
    auto res = sol.reverseVowels("a.");

    return 0;
}
