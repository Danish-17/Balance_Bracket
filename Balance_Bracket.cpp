#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_balanced(string expr)
{
    stack<char> s;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            s.push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (s.empty())
            {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((top == '(' && expr[i] != ')') ||
                (top == '{' && expr[i] != '}') ||
                (top == '[' && expr[i] != ']'))
            {
                return false;
            }
        }
    }
    return s.empty();
}

int main()
{
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;
    if (is_balanced(expr))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}