#include <stdio.h>
#include <stdlib.h>

int triple_count = 0; 

int* add_Element(int *sparse);
int* delete_Element(int *sparse);
void search_Element(int *sparse);
void print_Sparse(int *sparse);

int main()
{

	int *sparse = (int *) malloc(3 * sizeof(int));
	
	if (sparse == NULL) {
		printf("Allocation failed!\n");
		return 0;
	}

	printf("Enter original matrix rows: ");
	int r; scanf("%d", &r);
	printf("Enter original matrix columns: ");
	int c; scanf("%d", &c);
	
	sparse[0] = r;
	sparse[1] = c;
	sparse[2] = 0; 
	
	int operation;
	while(1)
	{
		printf("************************************\n");
		printf("1 - Add or Update a value\n");
		printf("2 - Delete a value from sparse\n");
		printf("3 - Search a value\n");
		printf("4 - Print the Sparse Matrix\n");
		printf("0 - Exit\n");
		printf(": ");
		scanf("%d", &operation);
		
		switch(operation)
		{
			case 1:
				sparse = add_Element(sparse);
				break;
			case 2:
				if (triple_count == 0) {
					printf("Firstly you have to add an element!\n");
					break;
				}
				sparse = delete_Element(sparse);
				break;
			case 3:
				search_Element(sparse);
				break;
			case 4:
				print_Sparse(sparse);
				break;
			case 0:
				free(sparse);
				printf("Closing the system...\n");
				return 0;
		}
	}
	
	return 0;
}


int* add_Element(int *sparse)
{
	int r, c, taken_Data;
	printf("Which Row: "); scanf("%d", &r);
	printf("Which Col: "); scanf("%d", &c);
	printf("What is your value: "); scanf("%d", &taken_Data);

	if(r >= sparse[0] || c >= sparse[1]) {
		printf("Invalid index! Your matrix is %dx%d\n", sparse[0], sparse[1]);
		return sparse;
	}

	for(int i = 1; i <= triple_count; i++)
	{
		if(sparse[i * 3 + 0] == r && sparse[i * 3 + 1] == c)
		{
			sparse[i * 3 + 2] = taken_Data;
			printf("Value was updated in the list!\n");
			return sparse;
		}
	}


	triple_count++;
	int *temp = (int *) realloc(sparse, (triple_count + 1) * 3 * sizeof(int));
	
	if (temp == NULL) return sparse;
	sparse = temp;
	
	sparse[triple_count * 3 + 0] = r;
	sparse[triple_count * 3 + 1] = c;
	sparse[triple_count * 3 + 2] = taken_Data;
	
	sparse[2] = triple_count; 
	printf("Your value added to the sparse matrix!\n");
	return sparse;
}


int* delete_Element(int *sparse)
{
	int r, c;
	printf("Enter Row to delete: "); scanf("%d", &r);
	printf("Enter Col to delete: "); scanf("%d", &c);

	int found_idx = -1;
	for(int i = 1; i <= triple_count; i++)
	{
		if(sparse[i * 3 + 0] == r && sparse[i * 3 + 1] == c)
		{
			found_idx = i;
			break;
		}
	}

	if(found_idx != -1)
	{

		for(int i = found_idx; i < triple_count; i++)
		{
			sparse[i * 3 + 0] = sparse[(i + 1) * 3 + 0];
			sparse[i * 3 + 1] = sparse[(i + 1) * 3 + 1];
			sparse[i * 3 + 2] = sparse[(i + 1) * 3 + 2];
		}
		
		triple_count--;
		sparse[2] = triple_count;
		sparse = (int *) realloc(sparse, (triple_count + 1) * 3 * sizeof(int));
		printf("Your element was deleted from list!\n");
	}
	else
	{
		printf("Your element doesn't exist in the matrix!\n");
	}
	return sparse;
}


void search_Element(int *sparse)
{
	int r, c;
	printf("Row: "); scanf("%d", &r);
	printf("Col: "); scanf("%d", &c);

	for(int i = 1; i <= triple_count; i++)
	{
		if(sparse[i * 3 + 0] == r && sparse[i * 3 + 1] == c)
		{
			printf("Value is: %d\n", sparse[i * 3 + 2]);
			return;
		}
	}
	printf("Value is: 0 (Zero element)\n");
}


void print_Sparse(int *sparse)
{
	if(triple_count == 0) {
		printf("List is empty! No non-zero elements.\n");
		return;
	}

	printf("\nSparse Matrix Traversal (R | C | V):\n");
	printf("------------------------------------\n");

	printf("Matrix Size: %d x %d | Non-zero: %d\n", sparse[0], sparse[1], sparse[2]);
	
	for(int i = 1; i <= triple_count; i++)
	{
		printf("Index [%d][%d] -> Value: %d\n", sparse[i * 3 + 0], sparse[i * 3 + 1], sparse[i * 3 + 2]);
	}
	printf("\n");
}
