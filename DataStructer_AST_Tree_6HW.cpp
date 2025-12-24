/******************************************************
 * 2. HAFTA – DERLEYÝCÝLER (COMPILERS)
 *
 * Programlama dillerinde, kod yapýsý
 * Abstract Syntax Tree (AST) ile temsil edilir.
 *
 * Örnek ifade:
 *      a = b + c * 2
 *
 * AST Yapýsý:
 *          =
 *         / \
 *        a   +
 *           / \
 *          b   *
 *              / \
 *             c   2
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Düðüm tipleri */
typedef enum {
	NODE_OP,   // Operatör düðümü (+, *, =)
	NODE_ID,   // Deðiþken (a, b, c)
	NODE_NUM   // Sayý (2 gibi)
} NodeType;

/* AST düðüm yapýsý */
typedef struct ASTNode {
	NodeType type;
	char op;                // Operatör
	char id[32];            // Deðiþken adý
	int num;                // Sayý deðeri
	struct ASTNode *left;
	struct ASTNode *right;
} ASTNode;

/* Operatör düðümü oluþturma */
ASTNode* newOp(char op, ASTNode* left, ASTNode* right)
{
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = NODE_OP;
	node->op = op;
	node->id[0] = '\0';
	node->num = 0;
	node->left = left;
	node->right = right;
	return node;
}

/* Deðiþken düðümü oluþturma */
ASTNode* newId(const char* name)
{
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = NODE_ID;
	node->op = '\0';
	strncpy(node->id, name, sizeof(node->id) - 1);
	node->id[sizeof(node->id) - 1] = '\0';
	node->num = 0;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/* Sayý düðümü oluþturma */
ASTNode* newNum(int value)
{
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = NODE_NUM;
	node->op = '\0';
	node->id[0] = '\0';
	node->num = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/* Düðüm içeriðini yazdýr */
void printNode(ASTNode* node)
{
	if (node == NULL) return;

	if (node->type == NODE_OP)
		printf("%c", node->op);
	else if (node->type == NODE_ID)
		printf("%s", node->id);
	else
		printf("%d", node->num);
}

/* Preorder Traversal: Root - Left - Right */
void preorder(ASTNode* root)
{
	if (root == NULL) return;
	printNode(root); printf(" ");
	preorder(root->left);
	preorder(root->right);
}

/* Inorder Traversal: Left - Root - Right */
void inorder(ASTNode* root)
{
	if (root == NULL) return;

	if (root->type == NODE_OP) printf("(");
	inorder(root->left);
	printNode(root); printf(" ");
	inorder(root->right);
	if (root->type == NODE_OP) printf(")");
}

/* Postorder Traversal: Left - Right - Root */
void postorder(ASTNode* root)
{
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printNode(root); printf(" ");
}

/* AST aðacýný yan þekilde yazdýr */
void printTree(ASTNode* root, int level)
{
	if (root == NULL) return;

	printTree(root->right, level + 1);

	for (int i = 0; i < level; i++)
		printf("    ");

	printNode(root);
	printf("\n");

	printTree(root->left, level + 1);
}

/* Bellek temizleme */
void freeTree(ASTNode* root)
{
	if (root == NULL) return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

int main()
{
	/*
		a = b + c * 2
		Ýfade adým adým AST olarak oluþturuluyor
	*/

	// c * 2
	ASTNode* mulNode = newOp('*', newId("c"), newNum(2));

	// b + (c * 2)
	ASTNode* addNode = newOp('+', newId("b"), mulNode);

	// a = (b + c * 2)
	ASTNode* assignNode = newOp('=', newId("a"), addNode);

	printf("AST (Sideways View):\n");
	printTree(assignNode, 0);

	printf("\nPreorder Traversal : ");
	preorder(assignNode);

	printf("\nInorder Traversal  : ");
	inorder(assignNode);

	printf("\n\nPostorder Traversal: ");
	postorder(assignNode);

	printf("\n");

	freeTree(assignNode);
	return 0;
}

