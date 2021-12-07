//ื๎ะกีป[https://leetcode-cn.com/problems/min-stack/submissions/]
/*
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
*/