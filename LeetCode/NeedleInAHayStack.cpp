#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() <= 0 || needle.size() <= 0)
            return -1;

        auto index = -1;
        for (int i = 0; i < haystack.size();)
        {
            for (int j = 0; j < needle.size(); i++, j++)
            {
                if (haystack[i] == needle[j])
                {
                    if (index == -1)
                        index = i;
                }
                else{
                    index = -1;
                    break;
                }
            }
            
            if (index != -1)
                return index;
        }
    }
};
