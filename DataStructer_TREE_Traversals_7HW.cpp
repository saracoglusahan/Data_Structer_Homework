/*
Traversal Türleri:
Preorder   : Root - Left - Right
Inorder    : Left - Root - Right
Postorder  : Left - Right - Root
Levelorder : Level by Level (Queue kullanýr)
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;


Node* createNode(int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}


void preorder(Node* root)
{
	if (root == NULL) return;

	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}


void inorder(Node* root)
{
	if (root == NULL) return;

	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(Node* root)
{
	if (root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}


typedef struct {
	Node* data[100];
	int front;
	int rear;
} Queue;


void initQueue(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

int isEmpty(Queue* q)
{
	return q->front == q->rear;
}

void enqueue(Queue* q, Node* node)
{
	q->data[q->rear++] = node;
}

Node* dequeue(Queue* q)
{
	return q->data[q->front++];
}


void levelorder(Node* root)
{
	if (root == NULL) return;

	Queue q;
	initQueue(&q);
	enqueue(&q, root);

	while (!isEmpty(&q))
	{
		Node* current = dequeue(&q);
		printf("%d ", current->data);

		if (current->left != NULL)
			enqueue(&q, current->left);

		if (current->right != NULL)
			enqueue(&q, current->right);
	}
}

int main()
{
	/*
	        1
	      2   3
	    4  5 6  7
	*/

	Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);

	root->left->left = createNode(4);
	root->left->right = createNode(5);

	root->right->left = createNode(6);
	root->right->right = createNode(7);

	printf("Preorder Traversal   : ");
	preorder(root);
	printf("\n");

	printf("Inorder Traversal    : ");
	inorder(root);
	printf("\n");

	printf("Postorder Traversal  : ");
	postorder(root);
	printf("\n");

	printf("Levelorder Traversal : ");
	levelorder(root);
	printf("\n");

	return 0;
}
