
#include<bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

int precedence(char m) {
	if (m == '^')
		return 3;
	else if (m == '*' || m == '/')
		return 2;
	else if (m == '+' || m == '-')
		return 1;
	return -1;
}

string infix_to_postfix(string t) {
	stack<char> s;
	string ans = "";
	int length = t.length();
	for (int i = 0; i < length; i++) {
		//if symbol or number, write to output expression
		if ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z')
				|| (t[i] >= '0' && t[i] <= '9'))
			ans += t[i];
		//if left parenthesis push it to stack
		else if (t[i] == '(')
			s.push('(');
		//if right parenthesis pop stack till left parenthesis
		else if (t[i] == ')') {

			while (!s.empty() && s.top() != '(') {
				ans += s.top();
				s.pop();
			}

			if (s.top() == '(') { //remove left parenthesis
				s.pop();
			}
			//
		} else {
			while (!s.empty() && precedence(t[i]) <= precedence(s.top())) {
				ans += s.top();
				s.pop();
			}
			s.push(t[i]);
		}
	}
	//pop all operators from stack
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}

	return ans;
}
int main() {
	string s = "a+b*c+5*(4+6)";
	string ans = infix_to_postfix(s);

	cout << "infix to postfix=" << ans << endl;
	return 0;
}
