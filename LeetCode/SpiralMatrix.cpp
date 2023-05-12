#include <iostream>
#include <vector>

using namespace std;
class SpiralMatrix
{
private:
    /* data */
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> v = vector<vector<int>>(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i][j] = -1;
            }
        }

        if (n == 0)
            return v;
        if (n == 1)
        {
            v[0][0] = 1;
            return v;
        }

        // 0: right, 1: down, 2: left, 3: up
        auto direction = 0;
        auto row = 0;
        auto col = 0;

        for (int i = 1; i <= n * n;)
        {
            switch (direction)
            {
            case 0: // going right
                while (col < n && v[row][col] == -1)
                {
                    v[row][col++] = i++;
                }
                direction = 1;
                row++;
                col--;
                break;
            case 1: // going down
                while (row < n && v[row][col] == -1)
                {
                    v[row++][col] = i++;
                }
                direction = 2;
                col--;
                row--;
                break;
            case 2: // going left
                while (col >= 0 && v[row][col] == -1)
                {
                    v[row][col--] = i++;
                }
                direction = 3;
                row--;
                col++;
                break;
            case 3: // going up
                while (row >= 0 && v[row][col] == -1)
                {
                    v[row--][col] = i++;
                }
                direction = 0;
                col++;
                row++;
                break;
            }
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    auto sol = new SpiralMatrix();
    auto v = sol->generateMatrix(3);
    return 0;
}
