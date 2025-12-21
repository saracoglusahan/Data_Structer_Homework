#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

/* Stack iþlemleri */
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

/* Operatör önceliði */
int priority(char x)
{
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	return 0;
}

/* Infix -> Postfix */
void infixToPostfix(char infix[], char postfix[])
{
	int i = 0, j = 0;
	char ch;

	while (infix[i] != '\0')
	{
		ch = infix[i];

		/* Operand ise */
		if (isalnum(ch))
		{
			postfix[j++] = ch;
		}
		/* '(' ise */
		else if (ch == '(')
		{
			push(ch);
		}
		/* ')' ise */
		else if (ch == ')')
		{
			while (top != -1 && peek() != '(')
			{
				postfix[j++] = pop();
			}
			pop(); // '(' sil
		}
		/* Operatör ise */
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

	/* Stack boþalt */
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

