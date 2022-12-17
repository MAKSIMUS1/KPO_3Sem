#include <iostream>
#include <stack>

using namespace std;

bool PolishNotation(string s);
bool IsOperator(char c);
int OperatorPriority(char s);

string textOut;
stack<char> operators;

bool PolishNotation(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!IsOperator(s[i]))
        {
            textOut += s[i];
            continue;
        }
        if (IsOperator(s[i]))
        {
            if (s[i] == '(')
            {
                operators.push(s[i]);
                continue;
            }
            if (operators.empty())
            {
                operators.push(s[i]);
                continue;
            }
            else if (!operators.empty())
            {
                if (OperatorPriority(operators.top()) < OperatorPriority(s[i]))
                {
                    operators.push(s[i]);
                    continue;
                }
            }
            if (!operators.empty())
            {
                while (OperatorPriority(operators.top()) >= OperatorPriority(s[i]))
                {
                    if(operators.top() == '+' || operators.top() == '-' || operators.top() == '*' || operators.top() == '/')
                        textOut += operators.top();
                    operators.pop();
                    if (operators.empty())
                        break;
                }
                operators.push(s[i]);
                continue;
            }
        }
        if (s[i] == '(')
        {
            operators.push(s[i]);
            continue;
        }
        if (s[i] == ')')
        {
            while (operators.top() != '(')
            {
                if (operators.top() == '+' || operators.top() == '-' || operators.top() == '*' || operators.top() == '/')
                    textOut += operators.top();
                operators.pop();
                if (operators.empty())
                    break;
            }
            operators.pop();
            continue;
        }
    }
    while (!operators.empty())
    {
        if (operators.top() == '+' || operators.top() == '-' || operators.top() == '*' || operators.top() == '/')
            textOut += operators.top();
        operators.pop();
        if (operators.empty())
            break;
    }
    return true;
}

bool IsOperator(char c)
{
    if(c == '+' || c == '*' || c == '/' || c == '-' || c == '(' || c == ')')
        return true;
    else
        return false;
}

int OperatorPriority(char s)
{
    if (s == '(')
        return 1;
    if (s == ')')
        return 1;
    if (s == '+')
        return 2;
    if (s == '-')
        return 2;
    if (s == '*')
        return 3;
    if (s == '/')
        return 3;
}

int main()
{
    setlocale(LC_ALL, "ru");
    string strtext;

    cin >> strtext;
    PolishNotation(strtext);
    cout << textOut;
}