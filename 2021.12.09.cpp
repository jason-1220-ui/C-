
//最小值[https://leetcode-cn.com/problems/min-stack/]
class MinStack {
private:
	stack<int> st;
	stack<int> min_st;
public:
	MinStack() {
	}

	void push(int val) {
		st.push(val);
		if (min_st.empty() || val <= min_st.top())
			min_st.push(val);
	}

	void pop() {
		int val = st.top();
		st.pop();
		if (val == min_st.top())
			min_st.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return min_st.top();
	}
};

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