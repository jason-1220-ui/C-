#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALLMAX 100 //�ܹ�ͳ�Ƶ�ְ��������

typedef struct Node{
	long int born_date, work_date, tele_num;
	char sex, name[ALLMAX], degree[ALLMAX], job[ALLMAX], address[ALLMAX];
	struct Node *next;
}SLNode;

typedef struct{
	long int born_date, work_date, tele_num;
	char name[ALLMAX], sex, degree[ALLMAX], job[ALLMAX], address[ALLMAX];
}DataType;


void ListInitiate(SLNode **head){//�����ʼ��
	if ((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL)
		exit(1);//��̬����洢�ռ�
	(*head)->next = NULL;
}

SLNode *ListInsert(SLNode *head, DataType x){//ְ����Ϣ�Ĳ���������������������
	SLNode *p, *q, *s;
	p = head->next;
	if ((q = (SLNode *)malloc(sizeof(SLNode))) == NULL)
		exit(1);//��̬����洢�ռ�
	q->born_date = x.born_date;
	q->work_date = x.work_date;
	q->tele_num = x.tele_num;
	strcpy(q->name, x.name);
	q->sex = x.sex;
	strcpy(q->degree, x.degree);
	strcpy(q->job, x.job);
	strcpy(q->address, x.address);
	if (head->next == NULL){//���ֻ�������ͷ��㣬û�������Ľ�㣬ֱ�Ӳ�����ͷ������
		head->next = q;
		head->next->next = NULL;
	}
	else{//����ǿ�
		for (; p; p = p->next){
			if (p->next != NULL){
				if (strcmp(p->name, x.name) < 0 && strcmp(p->next->name, x.name) > 0){//λ���������֮��
					s = p->next;
					p->next = q;
					q->next = s;
					break;
				}
				//else if(strcmp(p->name,x.name)==0)break;   //���������ͬ�򲻲�����Ϣ
			}
			else if (strcmp(p->name, x.name) < 0 && p->next == NULL){//����ǿգ������������������һ��
				p->next = q;
				q->next = NULL;
				break;
			}
			if (strcmp(p->name, x.name) > 0){//λ������ͷ���֮���λ��
				s = head->next;
				head->next = q;
				q->next = s;
				break;
			}
		}
	}
	return head;
}

void print(SLNode *head){//ְ����Ϣ����ʾ
	for (SLNode *p = head->next; p; p = p->next)//�������ְ������Ϣ
		printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
}

void printLink(SLNode *head){//ְ����Ϣ����ʾ
	printf("ְ��������\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
	print(head);
}


void put(SLNode *head, FILE *fp){//ְ����Ϣ�ı���
	SLNode *p;
	if ((fp = fopen("Employee.txt", "w")) == NULL){
		printf("�޷���'Employee.txt'!\n");
		exit(0);
	}
	for (p = head->next; p; p = p->next){
		fprintf(fp, "%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
	}
	if (fclose(fp))
		printf("�޷��ر�'Employee.txt'!\n"); exit(0);
}


void ListDelete(SLNode *head){//ְ����Ϣ��ɾ��
	SLNode *p, *s;
	char x[20];
	s = head;
	p = head->next;
	if (head->next == NULL){//����Ϊ�գ��������������ְ����Ϣ������ɾ����
		printf("�������޴�ְ����Ϣ������ɾ����\n");
		return;
	}
	printf("������Ҫɾ��ְ����������\n"); //����Ҫɾ�����˵�����
	scanf("%s", x);
	for (p; p; p = p->next){//�������д�ͷ��β����������˵�����
		if (strcmp(p->name, x) == 0){	//������ڣ���ɾ���������������������ְ����Ϣ������ɾ����
			s->next = p->next;
			free(p);
			printf("ɾ���ɹ��������������\n");
			printLink(head);
			break;
		}
		s = p;
	}
	if (p == NULL)
		printf("�������޴�ְ����Ϣ������ɾ����\n");
}

void ListModify(SLNode *head){//ְ����Ϣ���޸�
	DataType x;
	SLNode *p;
	p = head->next;
	if (p == NULL){
		printf("ְ��������ְ����Ϣ�������޸ģ�\n");
		return;
	}
	printf("������Ҫ�޸ĵ�ְ��������\n");
	scanf("%s", x.name);
	for (; p; p = p->next){
		if (strcmp(x.name, p->name) == 0){//���ҵ��˸�ְ������Ϣ
			printf("����д���ְ��������Ϣ��\n");
			printf("������ְ����Ϣ��\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
			scanf("%s %c %ld %ld %s %s %s %ld", p->name, &p->sex, &p->born_date, &p->work_date, p->degree, p->job, p->address, &p->tele_num);
			printf("�޸ĳɹ��������������\n");
			break;
		}
	}
	if (p == NULL)
		printf("��ְ�������ڣ��޷��޸�����Ϣ��\n");

}



void Listfind(SLNode head){//ְ����Ϣ�Ĳ���
	int i, j;
	SLNode *p;
	DataType x;
	if (head.next == NULL){//����Ϊ��
		printf("��������ְ����Ϣ����ѯʧ�ܣ�\n");
		return;
	}
	//�������˵�
	printf("\n");
	printf("\t******************************************************************\n");
	printf("\t*                        ְ����Ϣ��ѯ����                        *\n");
	printf("\t*                                                                *\n");
	printf("\t*  0.�˳���ѯϵͳ���ص����˵�\t\t     1.���������в�ѯ\t*\n\t*  2.�Գ������½��в�ѯ      \t\t     3.��ѧ�����в�ѯ\t*\n\t*  4.�Թ������½��в�ѯ      \t\t     5.��ְ����в�ѯ\t*\n\t*  6.��סַ���в�ѯ      \t\t     7.�Ե绰���в�ѯ\t*\n");
	printf("\t******************************************************************\n");
	while (1){
		printf("��������Ҫѡ��Ĳ�����");
		scanf("%d", &i);
		if (i == 0)//����0���˳���ѯϵͳ���ص����˵�
			break;
		else if (i == 1) {//����1�����������в�ѯ
			p = head.next;
			printf("������������");
			scanf("%s", x.name);
			j = 0;
			for (p; p; p = p->next) {
				if (strcmp(p->name, x.name) == 0) {//�����������ˣ���ôj�Լ�
					++j;
					printf("\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//��ʾû���ҵ��������Ϣ
				printf("ְ�������в����ڴ��ˣ�\n");
			else printf("��ѯ�ɹ�������������\n");
		}
		else if (i == 2) {//����2���Գ������½��в�ѯ
			p = head.next;
			printf("������������£�");
			scanf("%ld", &x.born_date);
			j = 0;
			for (p; p; p = p->next) {
				if (p->born_date == x.born_date) {//����ĳ��������������д���
					++j;//�����������ˣ���ôj�Լ�
					printf("\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//��ʾû���ҵ��������Ϣ
				printf("ְ��������û�����ʱ������ģ�\n");
			else printf("��ѯ�ɹ��������������\n");
		}
		else if (i == 4) {//����4���Թ������½��в�ѯ
			p = head.next;
			printf("�����빤�����£�");
			scanf("%ld", &x.work_date);
			j = 0;
			for (p; p; p = p->next) {
				if (p->work_date == x.work_date) {
					++j;//�����������ˣ���ôj�Լ�
					printf("\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//��ʾû���ҵ��������Ϣ
				printf("ְ��������û�����ʱ�乤���ģ�\n");
			else printf("��ѯ�ɹ��������������\n");
		}
		else if (i == 3) {//����3����ѧ�����в�ѯ
			p = head.next;
			printf("������ѧ����");
			scanf("%s", x.degree);
			j = 0;
			for (p; p; p = p->next) {
				if (strcmp(p->degree, x.degree) == 0) {
					++j;//�����������ˣ���ôj�Լ�
					printf("\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//��ʾû���ҵ��������Ϣ
				printf("ְ��������û������ѧ���ģ�\n");
			else printf("��ѯ�ɹ��������������\n");
		}
		else if (i == 5) {//����5����ְ����в�ѯ
			p = head.next;
			printf("������ְ��");
			scanf("%s", x.job);
			j = 0;
			for (p; p; p = p->next) {
				if (strcmp(p->job, x.job) == 0) {
					++j;//�����������ˣ���ôj�Լ�
					printf("\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//��ʾû���ҵ��������Ϣ
				printf("ְ��������û������ְ��ģ�\n");
			else printf("��ѯ�ɹ��������������\n");
		}
		else if (i == 6) {//����6����סַ���в�ѯ
			p = head.next;
			printf("������סַ��");
			scanf("%s", x.address);
			j = 0;
			for (p; p; p = p->next) {
				if (strcmp(p->address, x.address) == 0) {
					++j;//�����������ˣ���ôj�Լ�
					printf("\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//��ʾû���ҵ��������Ϣ
				printf("ְ��������û��ס��ģ�\n");
			else printf("��ѯ�ɹ��������������\n");
		}
		else if (i == 7) {//����7���Ե绰������в�ѯ
			p = head.next;
			printf("������绰��");
			scanf("%ld", &x.tele_num);
			j = 0;
			for (p; p; p = p->next) {
				if (p->tele_num == x.tele_num) {
					++j;//�����������ˣ���ôj�Լ�
					printf("\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
					printf("%s %c %ld %ld %s %s %s %ld\n", p->name, p->sex, p->born_date, p->work_date, p->degree, p->job, p->address, p->tele_num);
				}
			}
			if (j == 0)//��ʾû���ҵ��������Ϣ
				printf("ְ��������û����������룡\n");
			else printf("��ѯ�ɹ��������������\n");
		}
		else if (i != 0 && i != 1 && i != 2 && i != 3 && i != 4 && i != 5 && i != 6 && i != 7)//�������ⲻ���������ֵģ���ô����ʾ�������
			printf("����������ٴ����룡\n");
		printf("\n");
		printf("\t******************************************************************\n");
		printf("\t*                        ְ����Ϣ��ѯϵͳ                        *\n");
		printf("\t*                                                                *\n");
		printf("\t*  0.�˳���ѯϵͳ���ص����˵�\t\t     1.���������в�ѯ\t*\n\t*  2.�Գ������½��в�ѯ      \t\t     3.��ѧ�����в�ѯ\t*\n\t*  4.�Թ������½��в�ѯ      \t\t     5.��ְ����в�ѯ\t*\n\t*  6.��סַ���в�ѯ      \t\t     7.�Ե绰���в�ѯ\t*\n");
		printf("\t******************************************************************\n");

		//printf("0.�˳���ѯϵͳ���ص����˵�\n1.���������в�ѯ\n2.�Գ������½��в�ѯ\n3.�Թ������½��в�ѯ\n4.��ѧ�����в�ѯ\n5.��ְ����в�ѯ\n6.��סַ���в�ѯ\n7.�Ե绰������в�ѯ\n");
	}
}



void Listpaixu(SLNode *head)//ְ����Ϣ������
{
	int i, n = 0, m, flag = 1;
	SLNode *p, *q, *s;
	if (head->next == NULL) {//ְ������Ϊ��
		printf("��������ְ����Ϣ���޷�����\n\n");
		return;
	}
	//	printf("����������ٴ����룡\n\n");
	printf("\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");
	printf("\t\t~.~             ְ����Ϣ�������            ~.~\n");
	printf("\t\t~.~                                         ~.~\n");
	printf("\t\t~.~\t0.�˳�����ϵͳ���ص����˵�          ~.~\n\t\t~.~\t1.���Ա��������                    ~.~\n\t\t~.~\t2.�Գ������½�������                ~.~\n\t\t~.~\t3.�Թ������½�������                ~.~\n\t\t~.~\t4.��������������                    ~.~\n");
	printf("\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");
	while (1)
	{
		printf("��������Ҫѡ��Ĳ�����");
		scanf("%d", &i);
		if (i == 0)//����0���˳�����ϵͳ���ص����˵�
			break;
		else if (i == 1) {//����1�����Ա��������
			n = 0, m, flag = 1;
			for (p = head; NULL != p; p = p->next)//ͳ��ְ������
				n++;
			for (m = 1; flag&&m <= n; m++)
			{
				flag = 0;
				for (q = head->next, p = head, s = p; q; s = p, p = q, q = q->next)
				{
					if (p->sex > q->sex)//pΪ��ǰ�ڵ㣬p���Ա�>p�ĺ�̽ڵ���Ա�
					{
						if (head == p)//pΪͷ���
						{
							head->next = q->next;
							head = q;
							q->next = p;//�����ڵ���Ϣ
							q = head->next;
							p = head;
						}
						else
						{
							p->next = q->next;
							q->next = p;
							s->next = q;
							p = q;
							q = p->next;
						}
						flag = 1;
					}
				}
			}
			printf("�ź������Ϣ���£�\n");
			printLink(head);//������нڵ����Ϣ
			return;
		}
		else if (i == 2) {//����2���Գ������½�������
			n = 0, m, flag = 1;
			for (p = head; NULL != p; p = p->next)//ͳ��ְ������
				n++;
			for (m = 1; flag&&m <= n; n++)//ѭ��
			{
				flag = 0;
				for (q = head->next, p = head, s = p; q; s = p, p = q, q = q->next)
				{
					if (p->born_date > q->born_date)//�Գ������½�������
					{
						if (head == p)
						{
							head->next = q->next;
							head = q;
							q->next = p;
							q = head->next;
							p = head;
						}
						else
						{
							p->next = q->next;
							q->next = p;
							s->next = q;
							p = q;
							q = p->next;
						}
						flag = 1;
					}
				}
			}
			printf("�ź������Ϣ���£�\n");
			printLink(head);
			return;
		}
		else if (i == 3) {//����3��������ʱ���������
			n = 0, m, flag = 1;
			for (p = head; NULL != p; p = p->next)
				n++;
			for (m = 1; flag&&m <= n; n++)
			{
				flag = 0;
				for (q = head->next, p = head, s = p; q; s = p, p = q, q = q->next) {
					if (p->work_date > q->work_date) {
						if (head == p) {
							head->next = q->next;
							head = q;
							q->next = p;
							q = head->next;
							p = head;
						}
						else {
							p->next = q->next;
							q->next = p;
							s->next = q;
							p = q;
							q = p->next;
						}
						flag = 1;
					}
				}
			}
			printf("�ź������Ϣ���£�\n");
			printLink(head);
			return;
		}
		else if (i == 4)
		{
			n = 0, m, flag = 1;
			for (p = head; NULL != p; p = p->next)
				n++;
			for (m = 1; flag&&m <= n; n++)
			{
				flag = 0;
				for (q = head->next, p = head, s = p; q; s = p, p = q, q = q->next) {
					if (p->name[0] > q->name[0]) {
						if (head == p) {
							head->next = q->next;
							head = q;
							q->next = p;
							q = head->next;
							p = head;
						}
						else {
							p->next = q->next;
							q->next = p;
							s->next = q;
							p = q;
							q = p->next;
						}
						flag = 1;
					}
				}
			}
			printf("�ź������Ϣ���£�\n");
			printLink(head);
			return;
		}

		else if (i != 0 && i != 1 && i != 2 && i != 3 && i != 4)
			printf("����������ٴ����룡\n\n");
		printf("\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");
		printf("\t\t~.~             ְ����Ϣ����ϵͳ            ~.~\n");
		printf("\t\t~.~                                         ~.~\n");
		printf("\t\t~.~\t0.�˳�����ϵͳ���ص����˵�          ~.~\n\t\t~.~\t1.���Ա��������                    ~.~\n\t\t~.~\t2.�Գ������½�������                ~.~\n\t\t~.~\t3.�Թ������½�������                ~.~\n\t\t~.~\t4.��ʾȫ��ְ����Ϣ                  ~.~\n");
		printf("\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");


		//printf("0.�˳�����ϵͳ���ص����˵�\n1.���Ա��������\n2.�Գ������½�������\n3.�Թ������½�������\n");

	}
}

int main()
{
	DataType x;
	SLNode *head;
	int i, n;
	FILE *fp = NULL;
	ListInitiate(&head);//��ʼ������
	printf("\n");
	printf("*******************************************************************************\n");
	printf("************************    ��ӭʹ��ְ������ϵͳ    ***************************\n");
	printf("*******************************************************************************\n");


	printf("������Ҫ¼���ְ������n��");//����Ҫ¼���ְ������
	scanf("%d", &n);
	if (n == 0)
		goto aa;
	else {
		printf("������ְ����Ϣ��\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
		for (i = 0; i < n; i++)//ְ����Ϣ������
		{
			scanf("%s %s %ld %ld %s %s %s %ld", x.name, &x.sex, &x.born_date, &x.work_date, x.degree, x.job, x.address, &x.tele_num);
			head = ListInsert(head, x);
		}
		goto aa;
		printLink(head);
		put(head, fp);
	}

aa:	printf("\n");
	printf("\t����������������������������������\n");
	printf("\t��                          * ���˵� *                          ��\n");
	printf("\t��                          **********                          ��\n");
	printf("\t��                                                              ��\n");
	printf("\t��  \t0.��������ϵͳ\t\t\t1.����ְ����Ϣ\t\t��\n\t��  \t2.ɾ��ְ����Ϣ\t\t\t3.��ѯְ����Ϣ\t\t��\n\t��  \t4.�޸�ְ����Ϣ\t\t\t5.ְ����Ϣ����\t\t��\n");
	printf("\t��                                                              ��\n");
	printf("\t����������������������������������\n");


	while (1)
	{
		printf("��������Ҫѡ��Ĳ�����");
		scanf("%d", &i);
		if (i == 0)//����0������ϵͳ
		{
			printf("\t\t���Ѿ��ɹ��˳�ְ������ϵͳ,ллʹ��!\n");
			break;
		}
		else if (i == 1)//����1������һ��ְ��
		{
			printf("������ְ����Ϣ��\n�������Ա𡢳������¡��������¡�ѧ����ְ��סַ���绰\n");
			scanf("%s %c %ld %ld %s %s %s %ld", x.name, &x.sex, &x.born_date, &x.work_date, x.degree, x.job, x.address, &x.tele_num);
			head = ListInsert(head, x);
			printf("�����ɹ��������������\n");
			printLink(head);
			put(head, fp);//�������ļ���
		}
		else if (i == 2)//����2��ɾ��һ��ְ��
		{
			ListDelete(head);
			if ((fp = fopen("Employee.txt", "w")) == NULL)
			{
				printf("�޷���'ְ������.txt'!\n");
				exit(0);
			}
			put(head, fp);//�������ļ���
			if (fclose(fp))
				printf("�޷��ر�'Employee.txt'!\n"); exit(0);
		}
		else if (i == 3)//����3������һ��ְ��
			Listfind(*head);
		else if (i == 4)//����4���޸�ְ����Ϣ
		{
			ListModify(head);
			if ((fp = fopen("Employee.txt", "w")) == NULL)
			{
				printf("�޷���'Employee.txt'!\n");
				exit(0);
			}
			put(head, fp);//�������ļ���
			if (fclose(fp))
				printf("�޷��ر�'Employee.txt'!\n"); exit(0);
		}
		else if (i == 5)//����5����ְ����Ϣ��������
		{
			SLNode *p = head;
			Listpaixu(p);
		}
		//�������Ĳ��������κ�һ�������������������
		else printf("����������ٴ����룡\n");
		printf("\n");
		printf("\t����������������������������������\n");
		printf("\t��                          * ���˵� *                          ��\n");
		printf("\t��                          **********                          ��\n");
		printf("\t��                                                              ��\n");
		printf("\t��  0.��������ϵͳ\t\t\t\t1.����ְ����Ϣ\t��\n\t��  2.ɾ��ְ����Ϣ\t\t\t\t3.��ѯְ����Ϣ\t��\n\t��  4.�޸�ְ����Ϣ\t\t\t\t5.ְ����Ϣ����\t��\n");
		printf("\t��                                                              ��\n");
		printf("\t����������������������������������\n");
	}
}

