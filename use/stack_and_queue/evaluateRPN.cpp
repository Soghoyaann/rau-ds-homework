#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cassert>
int evaluateRPN(const std::vector<std::string>& expr)
{
    std::stack<int> st;
    for (const std::string& s : expr)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (s == "+")
            {
                st.push(a + b);
            }
            else if (s == "-")
            {
                st.push(a - b);
            }
            else if (s == "*")
            {
                st.push(a * b);
            }
            else
            {
                st.push(a / b);
            }
        }
        else
        {
            st.push(std::stoi(s));
        }
    }

    return st.top();
}
void test_evaluateRPN()
{
    assert(evaluateRPN({"2", "1", "+", "3", "*"}) == 9);
    assert(evaluateRPN({"4", "2", "/"}) == 2);
    assert(evaluateRPN({"5", "3", "-"}) == 2);
    assert(evaluateRPN({"2", "3", "*"}) == 6);
    assert(evaluateRPN({"10", "2", "/", "3", "+"}) == 8);
    std::cout << "evaluateRPN passed" << std::endl;
}
int main()
{
    test_evaluateRPN();
    return 0;
}