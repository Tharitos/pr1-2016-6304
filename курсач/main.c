#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


struct MusicalComposition {
	char name[80];//название композиции
	char author[80];//автор
	int year;//√од создани€
	struct MusicalComposition* next;//указатель на следующий элемнет
	struct MusicalComposition* prev;//указатель на предыдущий элемнт
};

typedef struct MusicalComposition MusicalComposition; //объ€вл€ем тип данных


MusicalComposition* createMusicalComposition(char *name, char* author, int year)//создаем и инициализируем новый элемент структуры "MusicalComposition"
{
	MusicalComposition* x = (MusicalComposition*)malloc(sizeof(MusicalComposition));//выдел€ем пам€ть
	strcpy(x->name, name);//проинициализируем пол€ параметрами, переданными в функцию
	strcpy(x->author, author);
	x->year = year;
	x->next = NULL;
	x->prev = NULL;
	return x;//поставим указатель на новый элемент "MusicalComposition"
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)//функци€ создани€ списка
{
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);//указатель на первый элемент
	MusicalComposition *prev = head;//указатели на движение по списку
	MusicalComposition *leroy;
	for (int i = 1; i < n; ++i)//заполн€ем список данными, которые передали массивы
	{
		leroy = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		leroy->prev = prev;//переставл€ем указатели
		prev->next = leroy;
		prev = leroy;
	}
	return head;//возвращаем указатель на head(первый элемент)

}

void push(MusicalComposition* head, MusicalComposition* element)//функци€ добавлени€ элемента в конец списка
{
	while (head->next)//передвижение указател€ в конец
		head = head->next;
	head->next = element;//добавл€ем в конец элемент и устанавливаем св€зь
	element->prev = head;
	element->next = NULL;
}

//функци€ удалени€ элемента
void removeEl(MusicalComposition*head, char*name_for_remove)
{

	while (head)//передвигаем указатель до конца списка
	{
		if (strcmp(head->name, name_for_remove) == 0)//если в списке есть то, что нам нужно, то выполн€ем следующее
		{
			if (head->next == NULL)//если элемент находитс€ в конце
			{
				head->prev->next = NULL;

				return;
			}
			else if (head->prev == NULL)//если после элемента идут другие
			{
				head->next->prev = NULL;
			}

			head->prev->next = head->next;//если элемент находитс€ в середине
			head->next->prev = head->prev;

			break;
		}

		head = head->next;
	}

}
int count(MusicalComposition*head)//подсчет элементов в списке
{
	int count = 0;
	while (head)
	{
		count++;//увеличиваем кол-во элементов
		head = head->next;
	}
	return count;
};

void print_names(MusicalComposition *head)//функци€ вывода элементов списка
{
	while (head)//цикл выполн€етс€, пока существует список
	{
		printf("%s\n", head->name);//на экран вывод€тс€ им€, автор и год
		head = head->next;
	}
}
void function(MusicalComposition *head)
{
int p=count(head)/2;//середина списка
MusicalComposition* sr1 =head;
MusicalComposition* sr2;
MusicalComposition* nw1=(MusicalComposition*)malloc(sizeof(MusicalComposition));//выделение пам€ти
MusicalComposition* nw2=(MusicalComposition*)malloc(sizeof(MusicalComposition));
MusicalComposition* nw3=(MusicalComposition*)malloc(sizeof(MusicalComposition));

for(int i=0;i<p;i++)//цикл, который начинаетс€ с середины
{
sr1=sr1->next;
}
sr2=sr1->prev;
scanf("%s/n",nw1->name);//ввод данных
printf("¬ведите автора\n");
scanf("%s/n",nw1->author);
printf("¬ведите год\n");
scanf("%d/n",&nw1->year);
printf("¬ведите название\n");
scanf("%s/n",nw2->name);
printf("¬ведите автора\n");
scanf("%s/n",nw2->author);
printf("¬ведите год\n");
scanf("%d/n",&nw2->year);
printf("¬ведите название\n");
scanf("%s/n",nw3->name);
printf("¬ведите автора\n");
scanf("%s/n",nw3->author);
printf("¬ведите год\n");
scanf("%d/n",&nw3->year);

sr2->next=nw1;//соединение со списком
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
	printf("¬ведите размер\n");
	scanf("%d\n", &length);
	char **names = (char**)malloc(sizeof(char*)*length);
	char **authors = (char**)malloc(sizeof(char*)*length);
	int *years = (int*)malloc(sizeof(int)*length);

	for (int i = 0; i < length; ++i)
	{
		char name[80];
		printf("¬ведите автора\n");
		char author[80];

		fgets(name, 80, stdin);
		fgets(author, 80, stdin);
		printf("¬ведите год\n");
		fscanf(stdin, "%d\n", &years[i]);
		(*strstr(name, "\n")) = 0;
		(*strstr(author, "\n")) = 0;
		names[i] = (char*)malloc(sizeof(char*)*(strlen(name) + 1));
		authors[i] = (char*)malloc(sizeof(char*)*(strlen(author) + 1));
		strcpy(names[i], name);
		strcpy(authors[i], author);

	}printf("¬ведите автора\n");

	MusicalComposition *head = createMusicalCompositionList(names, authors, years, length);
	char name_for_push[80];
	char author_for_push[80];
	int year_for_push;
	char name_for_remove[80];
	fgets(name_for_push, 80, stdin);
	fgets(author_for_push, 80, stdin);
	printf("¬ведите год\n");
	fscanf(stdin, "%d\n", &year_for_push);
	printf("¬ведите название\n");
	(*strstr(name_for_push, "\n")) = 0;
	(*strstr(author_for_push, "\n")) = 0;

	MusicalComposition *element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
	fgets(name_for_remove, 80, stdin);
	(*strstr(name_for_remove, "\n")) = 0;
	function(head);
for(int i=0;head->name[i]!='\0';i++)
    {
    head->name[i]=toupper(head->name[i]);// замен€ет все буквы в названии на большие
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
