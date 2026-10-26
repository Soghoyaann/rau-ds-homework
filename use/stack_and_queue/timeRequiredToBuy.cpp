#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
int timeRequiredToBuy(std::vector<int> tickets, int k)
{
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < tickets.size(); i++)
    {
        q.push({i, tickets[i]});
    }
    int time = 0;
    while (!q.empty())
    {
        std::pair<int, int> current = q.front();
        q.pop();
        int index = current.first;
        int remaining = current.second;
        remaining--;
        time++;
        if (index ==k && remaining ==0)
        {
            return time;
        }

        if (remaining> 0)
        {
            q.push({index, remaining});
        }
    }

    return time;
}
void test_timeRequiredToBuy()
{
    std::vector<int> tickets1 = {2, 3, 2};
    assert(timeRequiredToBuy(tickets1, 2) ==6);
    std::vector<int> tickets2 = {5, 1, 1, 1};
    assert(timeRequiredToBuy(tickets2, 0) ==8);
    std::cout << "timeRequiredToBuy passed" << std::endl;
}
int main()
{
    test_timeRequiredToBuy();
    return 0;
}