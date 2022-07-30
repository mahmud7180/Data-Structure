#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int num(char a)
{
	if(a == '^')
	return 3;
	else if(a == '*' || a == '/')
	return 2;
	else if(a == '+' || a == '-')
	return 1;
	else
	return -1;
}


void infixToPostfix(string s)
{
	std::stack<char> st;
	st.push('N');
	int l = s.length();
	string ns;
	for(int i = 0; i < l; i++)
	{

		if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
		ns+=s[i];


		else if(s[i] == '(')

		st.push('(');


		else if(s[i] == ')')
		{
			while(st.top() != 'N' && st.top() != '(')
			{
				char a = st.top();
				st.pop();
			ns += a;
			}
			if(st.top() == '(')
			{
				char a = st.top();
				st.pop();
			}
		}


		else{
			while(st.top() != 'N' && num(s[i]) <= num(st.top()))
			{
				char a = st.top();
				st.pop();
				ns += a;
			}
			st.push(s[i]);
		}

	}

	while(st.top() != 'N')
	{
		char a = st.top();
		st.pop();
		ns += a;
	}

	cout << ns << endl;

}

int main()
{ string exp = "a+b*(c+d/4)*e/f";
	infixToPostfix(exp);
	return 0;
}

