#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


struct MusicalComposition {
	char name[80];//�������� ����������
	char author[80];//�����
	int year;//��� ��������
	struct MusicalComposition* next;//��������� �� ��������� �������
	struct MusicalComposition* prev;//��������� �� ���������� ������
};

typedef struct MusicalComposition MusicalComposition; //��������� ��� ������


MusicalComposition* createMusicalComposition(char *name, char* author, int year)//������� � �������������� ����� ������� ��������� "MusicalComposition"
{
	MusicalComposition* x = (MusicalComposition*)malloc(sizeof(MusicalComposition));//�������� ������
	strcpy(x->name, name);//����������������� ���� �����������, ����������� � �������
	strcpy(x->author, author);
	x->year = year;
	x->next = NULL;
	x->prev = NULL;
	return x;//�������� ��������� �� ����� ������� "MusicalComposition"
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)//������� �������� ������
{
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);//��������� �� ������ �������
	MusicalComposition *prev = head;//��������� �� �������� �� ������
	MusicalComposition *leroy;
	for (int i = 1; i < n; ++i)//��������� ������ �������, ������� �������� �������
	{
		leroy = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		leroy->prev = prev;//������������ ���������
		prev->next = leroy;
		prev = leroy;
	}
	return head;//���������� ��������� �� head(������ �������)

}

void push(MusicalComposition* head, MusicalComposition* element)//������� ���������� �������� � ����� ������
{
	while (head->next)//������������ ��������� � �����
		head = head->next;
	head->next = element;//��������� � ����� ������� � ������������� �����
	element->prev = head;
	element->next = NULL;
}

//������� �������� ��������
void removeEl(MusicalComposition*head, char*name_for_remove)
{

	while (head)//����������� ��������� �� ����� ������
	{
		if (strcmp(head->name, name_for_remove) == 0)//���� � ������ ���� ��, ��� ��� �����, �� ��������� ���������
		{
			if (head->next == NULL)//���� ������� ��������� � �����
			{
				head->prev->next = NULL;

				return;
			}
			else if (head->prev == NULL)//���� ����� �������� ���� ������
			{
				head->next->prev = NULL;
			}

			head->prev->next = head->next;//���� ������� ��������� � ��������
			head->next->prev = head->prev;

			break;
		}

		head = head->next;
	}

}
int count(MusicalComposition*head)//������� ��������� � ������
{
	int count = 0;
	while (head)
	{
		count++;//����������� ���-�� ���������
		head = head->next;
	}
	return count;
};

void print_names(MusicalComposition *head)//������� ������ ��������� ������
{
	while (head)//���� �����������, ���� ���������� ������
	{
		printf("%s\n", head->name);//�� ����� ��������� ���, ����� � ���
		head = head->next;
	}
}
void function(MusicalComposition *head)
{
int p=count(head)/2;//�������� ������
MusicalComposition* sr1 =head;
MusicalComposition* sr2;
MusicalComposition* nw1=(MusicalComposition*)malloc(sizeof(MusicalComposition));//��������� ������
MusicalComposition* nw2=(MusicalComposition*)malloc(sizeof(MusicalComposition));
MusicalComposition* nw3=(MusicalComposition*)malloc(sizeof(MusicalComposition));

for(int i=0;i<p;i++)//����, ������� ���������� � ��������
{
sr1=sr1->next;
}
sr2=sr1->prev;
scanf("%s/n",nw1->name);//���� ������
printf("������� ������\n");
scanf("%s/n",nw1->author);
printf("������� ���\n");
scanf("%d/n",&nw1->year);
printf("������� ��������\n");
scanf("%s/n",nw2->name);
printf("������� ������\n");
scanf("%s/n",nw2->author);
printf("������� ���\n");
scanf("%d/n",&nw2->year);
printf("������� ��������\n");
scanf("%s/n",nw3->name);
printf("������� ������\n");
scanf("%s/n",nw3->author);
printf("������� ���\n");
scanf("%d/n",&nw3->year);

sr2->next=nw1;//���������� �� �������
nw1->next=nw2;
nw1->prev=sr2;
nw2->prev=nw1;
nw2->next=nw3;
nw3->prev=nw2;
nw3->next=sr1;
sr1->prev=nw3;
}
int main()
{
	int length;
	setlocale(LC_ALL, "Russian");
	printf("������� ������\n");
	scanf("%d\n", &length);
	char **names = (char**)malloc(sizeof(char*)*length);
	char **authors = (char**)malloc(sizeof(char*)*length);
	int *years = (int*)malloc(sizeof(int)*length);

	for (int i = 0; i < length; ++i)
	{
		char name[80];
		printf("������� ������\n");
		char author[80];

		fgets(name, 80, stdin);
		fgets(author, 80, stdin);
		printf("������� ���\n");
		fscanf(stdin, "%d\n", &years[i]);
		(*strstr(name, "\n")) = 0;
		(*strstr(author, "\n")) = 0;
		names[i] = (char*)malloc(sizeof(char*)*(strlen(name) + 1));
		authors[i] = (char*)malloc(sizeof(char*)*(strlen(author) + 1));
		strcpy(names[i], name);
		strcpy(authors[i], author);

	}printf("������� ������\n");

	MusicalComposition *head = createMusicalCompositionList(names, authors, years, length);
	char name_for_push[80];
	char author_for_push[80];
	int year_for_push;
	char name_for_remove[80];
	fgets(name_for_push, 80, stdin);
	fgets(author_for_push, 80, stdin);
	printf("������� ���\n");
	fscanf(stdin, "%d\n", &year_for_push);
	printf("������� ��������\n");
	(*strstr(name_for_push, "\n")) = 0;
	(*strstr(author_for_push, "\n")) = 0;

	MusicalComposition *element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
	fgets(name_for_remove, 80, stdin);
	(*strstr(name_for_remove, "\n")) = 0;
	function(head);
for(int i=0;head->name[i]!='\0';i++)
    {
    head->name[i]=toupper(head->name[i]);// �������� ��� ����� � �������� �� �������
    }
	printf("%s %s %d\n", head->name, head->author, head->year);
	int k = count(head);

	printf("%d\n", k);
	push(head, element_for_push);

	k = count(head);
	printf("%d\n", k);

	removeEl(head, name_for_remove);
	print_names(head);

	k = count(head);
	printf("%d\n", k);
	return 0;
}
