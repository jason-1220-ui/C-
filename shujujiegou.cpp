#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define ElemType char

typedef struct BTNode {
	ElemType data;
	struct BTNode* left_child;//����
	struct BTNode* right_child;//�Һ���
}BTNode, *BTree;

void InitBTree(BTree* T) {//�������ĳ�ʼ��
	*T = NULL;
}
void CreateBTree(BTree* T){//����������
	char c;
	scanf("%c", &c);
	if (c == '#')
		*T = NULL;
	else{
		*T = (BTree)malloc(sizeof(BTNode));//��̬�ڴ�����
		if (*T == NULL){
			printf("�ڴ�����ʧ��");
		}
		(*T)->data = c; //���ɸ����
		CreateBTree(&(*T)->left_child);//����������
		CreateBTree(&(*T)->right_child);//����������
	}
}
int NodeCount(BTree T) {//ͳ�ƶ������Ľڵ���
	if (T == NULL) {
		return 0;
	}
	else {
		return NodeCount(T->left_child) + NodeCount(T->right_child) + 1;
	}
}
int leafCount(BTree T) {//ͳ�ƶ�����������Ҷ�ӽ����
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
//������
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*PNode;
//��������
LNode* creat(){
	LNode* p, *s, *head, *item;
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	p = head;
	printf("��������ֵ:\n");
	while (1) {
		s = new LNode;//�����½ڵ�
		scanf("%d", &s->data);//����������
		if (s->data = -1) 
			break; //����-1��ʾ�������
		p->next = s;
		p = s;
	}
	p->next = NULL;//���һ���ڵ�����ָ��Ϊ��
	return head;
}
//ͳ�Ƴ����������н��ֵ���ڸ���ֵ�Ľ����
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
//�ҳ������е���Сֵ
int getMin(LNode* L) {
	LNode *s, *p;
	s = L->next;//�ٶ���һ������е�������С
	p = s->next;//��pָ��s����һ���ڵ�
	while (p != NULL) {
		if (p->data < s->data) {
			//���s�ڵ��ֵ��p�ڵ��ֵ��,��p�ڵ�ֵ����s����ʱ��СֵΪs
			s= p;
		}
		p = p->next;//����p
	}
	return s->data;
}
int main(){
	LNode* head;//��ͷ
	head = creat();//��������
	int ret = Count(head, 1);//�ҳ�����ֵΪ1�Ľڵ���
	printf("%d\n", ret);
	int min = getMin(head);
	printf("��С�Ľ����:%d\n", min);
	return 0;
}
*/