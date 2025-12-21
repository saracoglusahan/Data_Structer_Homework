/****************************************************
 * WEEK 7 – TREE TRAVERSALS
 *
 * Bu örnekte ikili aðaç (Binary Tree) üzerinde
 * farklý dolaþma (traversal) yöntemleri gösterilmiþtir.
 *
 * Traversal Türleri:
 *  - Preorder   : Root - Left - Right
 *  - Inorder    : Left - Root - Right
 *  - Postorder  : Left - Right - Root
 *  - Levelorder : Level by Level (Queue kullanýr)
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Aðaç düðüm yapýsý */
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

/* Yeni düðüm oluþturma */
Node* createNode(int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/* Preorder Traversal: Root - Left - Right */
void preorder(Node* root)
{
	if (root == NULL) return;

	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

/* Inorder Traversal: Left - Root - Right */
void inorder(Node* root)
{
	if (root == NULL) return;

	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

/* Postorder Traversal: Left - Right - Root */
void postorder(Node* root)
{
	if (root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

/* Level Order için Queue yapýsý */
typedef struct {
	Node* data[100];
	int front;
	int rear;
} Queue;

/* Queue iþlemleri */
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

/* Level Order Traversal */
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
	       / \
	      2   3
	     / \ / \
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
