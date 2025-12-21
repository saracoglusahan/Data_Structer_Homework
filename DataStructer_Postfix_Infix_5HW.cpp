#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Stack islemleri 
void push(char x)
{
	stack[++top] = x;
}

char pop()
{
	return stack[top--];
}

char peek()
{
	return stack[top];
}

// Operator onceligi 
int priority(char x)
{
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	return 0;
}

/* Infix to Postfix */
void infixToPostfix(char infix[], char postfix[])
{
	int i = 0, j = 0;
	char ch;

	while (infix[i] != '\0')
	{
		ch = infix[i];

		// Operandsa 
		if (isalnum(ch))
		{
			postfix[j++] = ch;
		}
		// parantez açma ise 
		else if (ch == '(')
		{
			push(ch);
		}
		// parantez kapama ise 
		else if (ch == ')')
		{
			while (top != -1 && peek() != '(')
			{
				postfix[j++] = pop();
			}
			pop(); // parantez kapama sil
		}
		// Operatorse 
		else
		{
			while (top != -1 && priority(peek()) >= priority(ch))
			{
				postfix[j++] = pop();
			}
			push(ch);
		}
		i++;
	}

	/* Stack bosalt */
	while (top != -1)
	{
		postfix[j++] = pop();
	}

	postfix[j] = '\0';
}

int main()
{
	char infix[SIZE], postfix[SIZE];

	printf("Enter infix expression: ");
	scanf("%s", infix);

	infixToPostfix(infix, postfix);

	printf("Postfix expression: %s\n", postfix);

	return 0;
}

