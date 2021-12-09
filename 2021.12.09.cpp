//逆波兰表达式求值[https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/submissions/]
/*
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (int i = 0; i < tokens.size(); ++i) {
			if (!(tokens[i] == "+" || tokens[i] == "-" ||
				tokens[i] == "*" || tokens[i] == "/"))
				st.push(atoi(tokens[i].c_str()));
			else {
				int result = 0;
				int right_value = st.top();
				st.pop();
				int left_value = st.top();
				st.pop();
				if (tokens[i] == "+")
					result = left_value + right_value;
				else if (tokens[i] == "-")
					result = left_value - right_value;
				else if (tokens[i] == "*")
					result = left_value * right_value;
				else if (tokens[i] == "/")
					result = left_value / right_value;
				st.push(result);
			}
		}
		return st.top();
	}
};*/