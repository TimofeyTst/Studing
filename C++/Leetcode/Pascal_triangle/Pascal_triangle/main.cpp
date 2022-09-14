#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows > 0)
        {
            vector<int> var = { 1 };
            result.push_back(var);
            if (numRows > 1)
            {
                var = { 1,1 };
                result.push_back(var);
                for (int i = 2; i < numRows; i++)
                {
                    var = { 1 };
                    for (int j = 0; j < i - 1; j++)
                    {
                        var.push_back(result[i - 1][j] + result[i - 1][j+1]);
                    }
                    var.push_back(1);
                    result.push_back(var);
                }
            }
        }
        else {
            result = { {0} };
        }
        return result;
    }
};

void print(vector<vector<int>> var)
{
    std::cout << "[ ";
    for (int i = 0; i < var.size(); i++)
    {
        std::cout << '[';
        for (size_t j = 0; j < var[i].size(); j++)
        {
            if (j != 0) std::cout << ',';
            std::cout << var[i][j];
        }
        std::cout << "],";
    }
    std::cout << " ]\n";
}

int main()
{

    print(Solution::generate(6));

    return 0;
}