#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

struct node* create_List(struct node *head);
void print_List(struct node *head);
struct node* add_Element(struct node *head);
struct node* delete_Element(struct node *head,int data);

int main()
{
	struct node *head = NULL;
	int operation;
	while(1)
	{
		printf("************************************\n");
		printf("1 - Create Linked List\n");
		printf("2 - Add an element to list\n");
		printf("3 - Delete an element from list\n");
		printf("4 - Print the List\n");
		printf("0 - Exit\n");
		printf(": ");
		scanf("%d",&operation);
		
		switch(operation)
		{
			case 1:
				if (head != NULL) {
                    printf("List was createn!\n");
                    break;
                }
				head = create_List(head);
				break;
			case 2:
				if (head == NULL)
				{
					printf("Firstly you have to create the Linked List!\n");
					break;
				}
				head = add_Element(head);
				break;
			case 3:
				if (head == NULL){
					printf("Firstly you have to create the Linked List!\n");
					break;
				}
				int data;
				printf("Which element do you want to delete: ");
				scanf("%d",&data);
				head = delete_Element(head,data);
				break;
			case 4:
				print_List(head);
			break;
			case 0:
				return 0;
				
		}
		
	}
	
	return 0;
}


struct node *create_List(struct node* head){
	head = (struct node*) malloc(sizeof(struct node));
	if(head == NULL){
		printf("Linked List can not create!\n");
		return head;
	}
	int taken_Data;
	printf("What is your value which add to list: ");
	scanf("%d",&taken_Data);
	head->data = taken_Data;
	head->next = NULL;
	printf("Linked List was create!\n");
	return head;
}


struct node *add_Element(struct node* head){
	
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if (newNode == NULL) {return head;}
	int taken_Data;
	printf("What is your value: ");
	scanf("%d",&taken_Data);
	newNode->data = taken_Data;
	if (head->data > taken_Data)
	{
		newNode->next = head;
		printf("Your value added the list!\n");
		return newNode;
	}
	struct node *iter = head;
	while(iter->next != NULL)
	{
		if(iter->data > newNode->data){
			head->next = newNode;
			newNode->next = NULL;
			printf("Your value added the list!\n");
			return head;
		}
		iter = iter->next;
	}
	iter->next = newNode;
	newNode->next = NULL;
	printf("Your value added the list!\n");
	return head;
}



struct node *delete_Element(struct node *head,int data){
	struct node *iter = head;
	if(data == head->data)
	{
		head = iter->next;
		free(iter);
		return head;
	}
	else
	{
		while (iter != NULL)
		{
			if (iter->next->data == data)
			{
				struct node *deleted = iter->next;
				iter->next = iter->next->next;
				iter = iter->next;
				free(deleted);
				return head;
			}
			iter = iter->next;
		}
		
		printf("Your element doesn't exist in the linked list!\n");
		return head;
	}
	
}


void print_List(struct node *head){
	if(head == NULL)
	{
		printf("You must be create linked list!\n");
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
