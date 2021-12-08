#include<iostream>
#include<vector>
using namespace std;

//杨辉三角[https://leetcode-cn.com/problems/pascals-triangle/submissions/]
/*
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ivv;
		ivv.resize(numRows);
		for (int i = 0; i < ivv.size(); ++i) {
			ivv[i].resize(i + 1, 0);
			ivv[i][0] = ivv[i][i] = 1;
		}
		for (int i = 2; i < numRows; ++i) {
			for (int j = 1; j < ivv[i].size() - 1; ++j) {
				ivv[i][j] = ivv[i - 1][j - 1] + ivv[i - 1][j];
			}
		}
		return ivv;
	}
};*/

//只出现一次的数字[https://leetcode-cn.com/problems/single-number/submissions/]
/*
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int i = 0; i < nums.size(); ++i) {
			ret = ret ^ nums[i];
		}
		return ret;
	}
};*/

//删除排序数组中的重复项
/*
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int j = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (nums[i] != nums[i + 1]) {
				nums[++j] = nums[i + 1];
			}
		}
		return j + 1;
	}
};*/
 
//只出现一次的数字[https://leetcode-cn.com/problems/single-number-ii/submissions/]
//哈希表
/*
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> hash;
		for (int num : nums) {
			hash[num]++;
		}
		int ans = 0;
		for (auto[num, occ] : hash) {
			if (occ == 1) {
				ans = num;
				break;
			}
		}
		return ans;
	}
};*/
/*
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < 32; ++i) {
			int total = 0;
			for (int num : nums) {
				total += ((num >> i) & 1);
			}
			if (total % 3) {
				ans |= (1 << i);
			}
		}
		return ans;
	}
};*/

//只出现一次的数[https://leetcode-cn.com/problems/single-number-iii/submissions/]
/*
//异或法
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int num=0;
		for(int i=0;i<nums.size();++i){
			num ^= nums[i];
		}
		for(int i=0;i<32;++i){
			if((num>>i)&1){
				num=i;
				break;
			}
		}
		int a=0,b=0;
		for(auto& e:nums){
			if((e>>num)&1){
				a^=e;
			}
			else{
				b^=e;
			}
		}
		return {a,b};
	}
};
//排序法
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> ans;
		sort(nums.begin(), nums.end());//1 1 2 2 3 5
		if (nums[0] != nums[1])
			ans.push_back(nums[0]);
		if (nums[nums.size() - 1] != nums[nums.size() - 2])
			ans.push_back(nums[nums.size() - 1]);
		for (int i = 1; i < nums.size() - 1; ++i) {
			if ((nums[i] != nums[i + 1]) && (nums[i - 1] != nums[i]))
				ans.push_back(nums[i]);
		}
		return ans;
	}
};*/

//数组中出现次数超过一半的数子[https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&&tqId=11181&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking]
/*
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int hash[10000] = { 0 };
		for (int i = 0; i < numbers.size(); ++i) {
			hash[numbers[i]]++;
		}
		for (int i = 0; i < numbers.size(); ++i) {
			if (hash[numbers[i]] > numbers.size() / 2)
				return numbers[i];
		}
		return 0;
	}
};*/

//连续子数组的最大和[https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2]
/*
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int ans = INT_MIN;
		int len = array.size();
		vector<int> sum(len + 1, 0);
		for (int i = 0; i < len; ++i) {
			sum[i + 1] = sum[i] + array[i];
		}
		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j <= len; j++) {
				ans = max(ans, sum[j] - sum[i]);
			}
		}
		return ans;
	}
};*/

//最小栈[https://leetcode-cn.com/problems/min-stack/submissions/]
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