#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node *create_LinkedList(struct node *head);
struct node *add_Element(struct node *head);
struct node *delete_Element(struct node *head);
void print_LinkedList(struct node *head);

struct node *head = NULL;

int main()
{
	
	
	while(1)
	{
		int operation;
		printf("*******************\n");
		printf("1 - Create Doubly Linked List\n");
		printf("2 - Add Element to the Doubly Linked List\n");
		printf("3 - Delete an Element from the Doubly Linked List\n");
		printf("4 - Print the Doubly Linked List\n");
		printf("0 - Exit\n");
		printf(": ");
		scanf("%d",&operation);
		switch (operation)
		{
			case 1:
				head = create_LinkedList(head);
				break;
			case 2:
				head = add_Element(head);
				break;
			case 3:
				
				break;
			case 4:
				print_LinkedList(head);
				break;
			case 0:
				printf("Closing...\n");
				return 0;
		}
	}
	
	
	
	
	return 0;
}


struct node *create_LinkedList(struct node *head)
{
	if(head != NULL)
	{
		printf("You already create Linked List!\n");
		return head;
	}
	else
	{
		struct node *head = (struct node*) malloc(sizeof(struct node));
		if(head == NULL)
		{	
			printf("Your Linked List did not create!\n");
			return head;
		}
		int data;
		printf("What is your value to add the List: ");
		scanf("%d",&data);
		head->prev = NULL;
		head->next = NULL;
		head->data = data;
		printf("List was created!\n");
		return head;
	}
	
}


struct node *add_Element(struct node *head){
	
	if (head == NULL)
	{
		printf("Firstly you must be create the Linked List!\n");
		return head;
	}
	
	
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if (newNode == NULL)
	{
		printf("The element did not create!\n");
		return head;
	}
	int data;
	printf("What is your element to add the List: ");
	scanf("%d",&data);
	newNode->data = data;
	
	struct node *iter = head;
	if(head->data > newNode->data)
	{
		head->prev = newNode;
		newNode->prev = NULL;
		newNode->next = head;
		printf("The element added to the list!\n");
		return newNode;
	}
	else
	{
		while (iter->next != NULL)
		{
			if(iter->data > newNode->data)
			{
				newNode->prev = iter->prev;
				newNode->next = iter;
				iter->prev = newNode;
				printf("The element added to the list!\n");
				return head;
			}
			iter = iter->next;
		}
		iter->next = newNode;
		newNode->prev = iter;
		newNode->next = NULL;
		printf("The element added to the list!\n");
		return head;
	}
}


struct node *delete_Element(struct node *head)
{
	
	
	
	
}




void print_LinkedList(struct node *head)
{
	if (head == NULL)
	{
		printf("Firstly you must be create the Linked List!\n");
		return;
	}
	struct node *iter = head;
	while (iter != NULL)
	{
		printf("%d ",iter->data);
		iter = iter->next;
	}
	printf("\n\n");
}









