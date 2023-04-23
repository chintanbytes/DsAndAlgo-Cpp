#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>

class BuiltIns
{
private:
    std::vector<std::string> vector = {"chintan", "Narendra", "Joshi"};
    std::map<std::string, int> pair = {
        {"Chintan", 1},
        {"Krupa", 2}};
    std::queue<int> q;
    std::stack<int> s;
    std::vector<int> v;

    /* data */
public:
    BuiltIns(/* args */);
    ~BuiltIns();
};

BuiltIns::BuiltIns(/* args */)
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

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::for_each(v.begin(), v.end(), [](int &v)
                  { std::cout << v << std::endl; });

    for (int &ele : v)
    {
        std::cout << ele << std::endl;
    }

    std::cout << "Vector size: " << v.size() << std::endl;
    std::cout << "Vector capacity: " << v.capacity() << std::endl;

    v.push_back(40);

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v.at(i) << std::endl;
    }

    v.push_back(50);

    std::cout << "Vector size: " << v.size() << std::endl;
    std::cout << "Vector capacity: " << v.capacity() << std::endl;
}

BuiltIns::~BuiltIns()
{
}

// int main(int argc, char const *argv[])
// {
//     /* code */
//     BuiltIns bds;
//     return 0;
// }
