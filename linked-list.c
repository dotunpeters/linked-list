#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

//define a data structure node
typedef struct node
{
    int value;
    struct node* next;
}
node;

//declare functions
void insert(void);
void delete(void);
void search(void);
void print(void);

node* list = NULL;

int main(void)
{
    int command;
    printf("\nAvaliable commands\n\n"
			"1 - Insert\n"
			"2 - Delete\n"
			"3 - Search\n"
			"0 - Quit\n\n");

	command = get_int("Your command: ");

	//iterate through command
	if(command == 1)
	{
        insert();
    }
	else if(command == 2)
	{
	    delete();
    }
    else if (command == 3)
    {
        search();
    }
    else if (command == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


//insert function
void insert (void)
{
    int numb = get_int("How many list?: ");
    for(int i=0; i<numb; i++)
    {
        node* new = malloc(sizeof(node));
        if(list == NULL)
        {
            list = new;
            new->value = get_int("new value to insert: ");
            new->next = NULL;
        }
        else
        {
            new->next = list;
            new->value = get_int("new value to insert: ");
            list = new;
        }
    }
    print();
}


//delete function
void delete (void)
{
    int del = get_int("value to delete: ");
    node* ptr2 = list;
    node* prev = NULL;
    while (ptr2 != NULL)
    {
		if (ptr2->value == del)
		{
			if (ptr2 == list) {
				list = ptr2->next;
			} else
			{
				prev->next = ptr2->next;
			}
			free(ptr2);
			//return;
		}

		prev = ptr2;
		ptr2 = ptr2->next;
	}
        printf("Value has been deleted!\n");
        print();
}


//search function
void search (void)
{
    int srh = get_int("value to search: ");
    node* ptr3 = list;
    while(ptr3 !=NULL)
    {
        if (ptr3->value == srh)
        {
            printf("true\n\n");
            main();
        }
        ptr3 = ptr3->next;
    }
    printf("false\n\n");
    main();
}


//print current list to screen
void print(void)
{
    node* ptr = list;
    while (ptr != NULL)
	{
		printf("%i, ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n\n");
	main();
}