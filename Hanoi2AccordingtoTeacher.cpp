#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char val);
char pop();
char peek();
int get_Priority(char op);
void convert_Infix_To_Postfix(char infix[]);

int main()
{
	int operation;
	char taken_Data[MAX];

	while(1)
	{
		printf("************************************\n");
		printf("1 - Enter Infix Expression\n");
		printf("2 - Convert to Postfix and Print\n");
		printf("0 - Exit\n");
		printf(": ");
		scanf("%d", &operation);

		switch(operation)
		{
			case 1:
				printf("Enter your infix expression (e.g. a+b*(c-d)): ");
				scanf("%s", taken_Data);
				printf("Your expression was saved!\n");
				break;

			case 2:
				if (strlen(taken_Data) == 0) {
					printf("Firstly you have to enter an infix expression!\n");
					break;
				}
				printf("\nConverting process started...\n");
				printf("Postfix result: ");
				convert_Infix_To_Postfix(taken_Data);
				printf("\nConversion is succeed!\n\n");
				break;

			case 0:
				printf("Closing the Shunting Yard system...\n");
				return 0;

			default:
				printf("Invalid operation! Try again.\n");
				break;
		}
	}

	return 0;
}


void push(char val)
{
	if (top >= MAX - 1) {
		printf("Stack Overflow!\n");
		return;
	}
	stack[++top] = val;
}


char pop()
{
	if (top == -1) {
		return -1;
	}
	return stack[top--];
}


char peek()
{
	if (top == -1) {
		return -1;
	}
	return stack[top];
}


int get_Priority(char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	if (op == '*' || op == '/')
	{
		return 2;
	}
	if (op == '^')
	{
		return 3;
	}
	return 0;
}


void convert_Infix_To_Postfix(char infix[])
{
	int i = 0;
	char ch;

	while (infix[i] != '\0')
	{
		ch = infix[i];

		// Eger karakter bir harf veya rakamsa direkt yazdir (Operands)
		if (isalnum(ch))
		{
			printf("%c", ch);
		}
		// Parantez acma ise stack'e at
		else if (ch == '(')
		{
			push(ch);
		}
		// Parantez kapama ise acma parantezi gorene kadar pop yap
		else if (ch == ')')
		{
			while (top != -1 && peek() != '(')
			{
				printf("%c", pop());
			}
			pop(); // '(' karakterini stack'ten temizle
		}
		// Operator ise oncelik kontrolu yap
		else
		{
			while (top != -1 && get_Priority(peek()) >= get_Priority(ch))
			{
				printf("%c", pop());
			}
			push(ch);
		}
		i++;
	}

	// Stack'te kalan her seyi bosalt (Traversal gibi)
	while (top != -1)
	{
		printf("%c", pop());
	}
}
