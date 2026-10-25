#include <iostream>
#include <stack>
#include <string>
#include <cassert>

bool isBalanced(const std::string& s)
{
    std::stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (st.empty())
            {
                return false;
            }

            if ((c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[') ||
                (c == '}' && st.top() != '{'))
                {
                return false;
                }

            st.pop();
    }
    }

    return st.empty();
}
void test_isBalanced() {
    assert(isBalanced("({[]})"));
    assert(!isBalanced("([)]"));
    assert(!isBalanced("{[}]"));
    assert(isBalanced(""));
    assert(isBalanced("()"));
    assert(!isBalanced("("));
    assert(!isBalanced("]"));

    std::cout << "isBalanced passed" << std::endl;
}
int main()
{
    test_isBalanced();
    return 0;
}