#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define ElemType char

typedef struct BTNode {
	ElemType data;
	struct BTNode* left_child;//左孩子
	struct BTNode* right_child;//右孩子
}BTNode, *BTree;

void InitBTree(BTree* T) {//二叉树的初始化
	*T = NULL;
}
void CreateBTree(BTree* T){//创建二叉树
	char c;
	scanf("%c", &c);
	if (c == '#')
		*T = NULL;
	else{
		*T = (BTree)malloc(sizeof(BTNode));//动态内存申请
		if (*T == NULL){
			printf("内存申请失败");
		}
		(*T)->data = c; //生成根结点
		CreateBTree(&(*T)->left_child);//构造左子树
		CreateBTree(&(*T)->right_child);//构造右子树
	}
}
int NodeCount(BTree T) {//统计二叉树的节点数
	if (T == NULL) {
		return 0;
	}
	else {
		return NodeCount(T->left_child) + NodeCount(T->right_child) + 1;
	}
}
int leafCount(BTree T) {//统计二叉树的所有叶子结点数
	int Count;
	if (T == NULL) {
		return 0;
	}
	else if (T->left_child == NULL && T->right_child == NULL) {
		return 1;
	}
	return leafCount(T->left_child) + leafCount(T->right_child);
}
int main() {
	BTree bt;
	CreateBTree(&bt);
	printf("%d\n", NodeCount(bt));
	printf("%d\n", leafCount(bt));
	return 0;
}


/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#define ElemType int
//构造结点
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*PNode;
//创建链表
LNode* creat(){
	LNode* p, *s, *head, *item;
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	p = head;
	printf("请输入数值:\n");
	while (1) {
		s = new LNode;//创建新节点
		scanf("%d", &s->data);//输入结点数据
		if (s->data = -1) 
			break; //输入-1表示输入结束
		p->next = s;
		p = s;
	}
	p->next = NULL;//最后一个节点链域指向为空
	return head;
}
//统计出线性链表中结点值等于给定值的结点数
int Count(LNode* L, int e) {
	if (L == NULL)
		return 0;
	LNode *p = L;
	int count = 0;
	while (p->next != NULL) {
		if (p->data == e)
			count++;
		p = p->next;
	}
	return count;
}
//找出链表中的最小值
int getMin(LNode* L) {
	LNode *s, *p;
	s = L->next;//假定第一个结点中的数据最小
	p = s->next;//让p指向s的下一个节点
	while (p != NULL) {
		if (p->data < s->data) {
			//如果s节点的值比p节点的值大,则将p节点值赋给s，此时最小值为s
			s= p;
		}
		p = p->next;//更新p
	}
	return s->data;
}
int main(){
	LNode* head;//表头
	head = creat();//创建链表
	int ret = Count(head, 1);//找出链表值为1的节点数
	printf("%d\n", ret);
	int min = getMin(head);
	printf("最小的结点是:%d\n", min);
	return 0;
}
*/