#include <stdio.h>
#include <stdlib.h>

// Diskleri tutacak node yapýsý (Senin stilindeki node)
struct node {
	int diskSize;
	struct node *next;
};

// Kulelerin (Pegs) tepesini tutan pointerlar
struct node *pegA = NULL;
struct node *pegB = NULL;
struct node *pegC = NULL;

// Fonksiyon prototipleri
struct node* push_Disk(struct node *head, int size);
struct node* pop_Disk(struct node **head);
void print_Pegs();
void solve_Hanoi(int n, struct node **src, struct node **dest, struct node **aux, char s, char d, char a);

int main()
{
	int operation;
	int taken_Data; // Disk sayýsý
	
	while(1)
	{
		printf("************************************\n");
		printf("1 - Setup Hanoi Puzzle (Add Disks)\n");
		printf("2 - Print Current Pegs (Traversal)\n");
		printf("3 - Solve Puzzle Automatically\n");
		printf("0 - Exit\n");
		printf(": ");
		scanf("%d", &operation);
		
		switch(operation)
		{
			case 1:
				if (pegA != NULL) {
					printf("Puzzle already setup!\n");
					break;
				}
				printf("How many disks: ");
				scanf("%d", &taken_Data);
				// Diskleri büyükten küçüðe Peg A'ya ekle (Senin add element mantýðýn)
				for(int i = taken_Data; i >= 1; i--) {
					pegA = push_Disk(pegA, i);
				}
				printf("Disks added to Peg A!\n");
				break;
				
			case 2:
				print_Pegs();
				break;
				
			case 3:
				if(pegA == NULL) {
					printf("Firstly you have to setup the puzzle!\n");
					break;
				}
				// Kaç disk olduðunu say
				struct node *iter = pegA;
				int count = 0;
				while(iter != NULL) {
					count++;
					iter = iter->next;
				}
				solve_Hanoi(count, &pegA, &pegC, &pegB, 'A', 'C', 'B');
				printf("Puzzle solved successfully!\n");
				break;
				
			case 0:
				printf("Closing Hanoi system...\n");
				return 0;
		}
	}
	return 0;
}

// Diski kuleye ekleme (Add Element / Push)
struct node* push_Disk(struct node *head, int size) {
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if(newNode == NULL) return head;
	
	newNode->diskSize = size;
	newNode->next = head; // Her zaman baþa ekler (Stack mantýðý)
	return newNode;
}

// Diskten kuleyi çýkarma (Delete Element / Pop)
struct node* pop_Disk(struct node **head) {
	if(*head == NULL) return NULL;
	
	struct node *temp = *head;
	*head = (*head)->next;
	return temp; // Çýkan node'u döndür ki diðer kuleye ekleyebilelim
}

// Kulelerin durumunu gezme (Traversal)
void print_Peg_Status(struct node *head, char pegName) {
	printf("Peg %c: ", pegName);
	struct node *iter = head;
	if(iter == NULL) printf("Empty");
	while(iter != NULL) {
		printf("[%d] ", iter->diskSize);
		iter = iter->next;
	}
	printf("\n");
}

void print_Pegs() {
	printf("\n--- Current State ---\n");
	print_Peg_Status(pegA, 'A');
	print_Peg_Status(pegB, 'B');
	print_Peg_Status(pegC, 'C');
	printf("---------------------\n\n");
}

// Özyinelemeli çözüm (Kule pointerlarý ile)
void solve_Hanoi(int n, struct node **src, struct node **dest, struct node **aux, char s, char d, char a) {
	if(n == 1) {
		struct node *disk = pop_Disk(src);
		*dest = push_Disk(*dest, disk->diskSize);
		free(disk);
		printf("Moved disk 1 from %c to %c\n", s, d);
		print_Pegs();
		return;
	}
	
	solve_Hanoi(n - 1, src, aux, dest, s, a, d);
	
	struct node *disk = pop_Disk(src);
	*dest = push_Disk(*dest, disk->diskSize);
	free(disk);
	printf("Moved disk %d from %c to %c\n", n, s, d);
	print_Pegs();
	
	solve_Hanoi(n - 1, aux, dest, src, a, d, s);
}
