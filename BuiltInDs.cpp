#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>

class BuiltInDs
{
private:
    std::vector<std::string> vector = {"chintan", "Narendra", "Joshi"};
    std::map<std::string, int> pair = {
        {"Chintan", 1},
        {"Krupa", 2}};
    std::queue<int> q;
    std::stack<int> s;

    /* data */
public:
    BuiltInDs(/* args */);
    ~BuiltInDs();
};

BuiltInDs::BuiltInDs(/* args */)
{
    std::for_each(vector.begin(), vector.end(), [](std::string &ele)
                  { std::cout << ele << std::endl; });

    for (std::string &ele : vector)
    {
        std::cout << ele << std::endl;
    };

    for (auto x : pair)
    {
        std::cout << x.second << " -- " << x.first << std::endl;
    }

    for (auto &x : pair)
    {
        std::cout << x.second << " -- " << x.first << std::endl;
    }

    std::for_each(pair.begin(), pair.end(), [](auto &x)
                  { std::cout << x.second << " -- " << x.first << std::endl; });
}

BuiltInDs::~BuiltInDs()
{
}

int main(int argc, char const *argv[])
{
    /* code */
    BuiltInDs bds;
    return 0;
}
