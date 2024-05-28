#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char ch)
{
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

string postfixToinfix(string s)
{
	stack<string> st;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (isOperand(s[i]))
		{
			string op(1, s[i]);
			st.push(op);
		}
		else
		{
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();
			st.push("(" + op2 + s[i] + op1 + ")");
		}
	}
	return st.top();
}

void main()
{
	string s;
	cout << "enter post fix exp: ";
	cin >> s;
	cout << "infix exp: " << postfixToinfix(s) << endl;
}