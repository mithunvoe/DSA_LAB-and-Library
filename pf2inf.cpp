#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define tata return 0
#define all(v) v.begin(), v.end()
#define endl '\n'
#define gap ' '

const int M = 1e9 + 7;
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToInfix(string postfix)
{
    stack<string> s;

    for (char c : postfix)
    {
        if (isOperator(c))
        {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            string expression = "(" + operand1 + c + operand2 + ")";
            s.push(expression);
        }
        else
        {
            s.push(string(1, c));
        }
    }

    return s.top();
}
void kire()
{
    string s;
    cin >> s;
    cout << postfixToInfix(s) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin>>t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        kire();
    }

    tata;
}
