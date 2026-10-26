#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cassert>
std::vector<std::string> generateBinaryNumbers(int n)
{
    std::vector<std::string> result;
    std::queue<std::string> q;
    q.push("1");
    for (int i = 0;i < n; i++)
    {
        std::string current = q.front();
        q.pop();
        result.push_back(current);
        q.push(current +"0");
        q.push(current + "1");
    }

    return result;
}
void test_generateBinaryNumbers()
{
    std::vector<std::string> result = generateBinaryNumbers(5);
    assert(result.size()== 5);
    assert(result[0]== "1");
    assert(result[1]=="10");
    assert(result[2]== "11");
    assert(result[3]== "100");
    assert(result[4]== "101");
    std::cout << "generateBinaryNumbers passed" << std::endl;
}
int main()
{
    test_generateBinaryNumbers();
    return 0;
}