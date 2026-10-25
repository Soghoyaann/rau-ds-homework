#include <iostream>
#include <string>
#include <stack>
#include <cassert>
void reverseString(std::string& s)
{
    std::stack<char> st;
    for (char c : s)
    {
        st.push(c);
    }
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = st.top();
        st.pop();
    }
}
void test_reverseString()
{
    std::string s1 = "Hello";
    reverseString(s1);
    assert(s1 == "olleH");

    std::string s2 = "12345";
    reverseString(s2);
    assert(s2 == "54321");

    std::string s3 = "";
    reverseString(s3);
    assert(s3 == "");

    std::string s4 = "a";
    reverseString(s4);
    assert(s4 == "a");

    std::cout << "reverseString passed" << std::endl;
}
int main()
{
    test_reverseString();
    return 0;
}