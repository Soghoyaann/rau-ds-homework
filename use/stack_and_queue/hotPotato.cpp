#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cassert>
std::string hotPotato(const std::vector<std::string>& players, int k)
{
    std::queue<std::string> q;
    for (const std::string& player : players)
    {
        q.push(player);
    }
    while (q.size() > 1)
    {
        for (int i = 0; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}
void test_hotPotato()
{
    std::vector<std::string> players = { "Alice", "Bob", "Charlie", "David" };
    assert(hotPotato(players, 7) == "Charlie");
    std::vector<std::string> players2 =
    {
        "Anna", "Tom"
    };
    assert(hotPotato(players2, 1) == "Anna");
    std::vector<std::string> players3 =
    {
        "Alex"
    };
    assert(hotPotato(players3, 5) == "Alex");
    std::cout << "hotPotato passed" << std::endl;
}
int main()
{
    test_hotPotato();
    return 0;
}