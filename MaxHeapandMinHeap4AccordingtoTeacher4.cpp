#include <stdio.h>
#include <stdlib.h>

// Max Heap Icin Gerekli Fonksiyonlar
int* add_Max(int *heap, int *size);
int* delete_Max(int *heap, int *size);
void max_Heapify_Up(int *heap, int index);
void max_Heapify_Down(int *heap, int n, int i);

// Min Heap Icin Gerekli Fonksiyonlar
int* add_Min(int *heap, int *size);
int* delete_Min(int *heap, int *size);
void min_Heapify_Up(int *heap, int index);
void min_Heapify_Down(int *heap, int n, int i);

void print_Heap(int *heap, int size, char* name);

// Alt Menu Fonksiyonlari
void max_Heap_Menu();
void min_Heap_Menu();

int main()
{
	int operation;
	while(1)
	{
		printf("************************************\n");
		printf("      MAIN HEAP OPERATIONS\n");
		printf("1 - Max Heap Operations\n");
		printf("2 - Min Heap Operations\n");
		printf("0 - Exit System\n");
		printf(": ");
		scanf("%d", &operation);
		
		switch(operation)
		{
			case 1:
				max_Heap_Menu();
				break;
			case 2:
				min_Heap_Menu();
				break;
			case 0:
				printf("Closing the system...\n");
				return 0;
			default:
				printf("Invalid operation!\n");
		}
	}
	return 0;
}

// --- MAX HEAP MENU VE MANTIGI ---

void max_Heap_Menu() {
	int *heap = NULL;
	int size = 0;
	int op;
	while(1) {
		printf("\n--- MAX HEAP SUB-MENU ---\n");
		printf("1 - Add Element\n2 - Delete Max Root\n3 - Print Traversal\n0 - Back to Main Menu\n: ");
		scanf("%d", &op);
		if(op == 1) heap = add_Max(heap, &size);
		else if(op == 2) heap = delete_Max(heap, &size);
		else if(op == 3) print_Heap(heap, size, "Max Heap");
		else if(op == 0) { free(heap); return; }
	}
}

int* add_Max(int *heap, int *size) {
	int taken_Data;
	printf("What is your value to add Max Heap: ");
	scanf("%d", &taken_Data);
	(*size)++;
	heap = (int*)realloc(heap, (*size) * sizeof(int));
	heap[(*size) - 1] = taken_Data;
	max_Heapify_Up(heap, (*size) - 1);
	printf("Your value added the heap!\n");
	return heap;
}

void max_Heapify_Up(int *heap, int index) {
	int parent = (index - 1) / 2;
	if (index > 0 && heap[index] > heap[parent]) {
		int temp = heap[index]; heap[index] = heap[parent]; heap[parent] = temp;
		max_Heapify_Up(heap, parent);
	}
}

int* delete_Max(int *heap, int *size) {
	if (*size == 0) { printf("Heap is empty!\n"); return heap; }
	printf("Max value %d deleted!\n", heap[0]);
	heap[0] = heap[(*size) - 1];
	(*size)--;
	if (*size > 0) {
		heap = (int*)realloc(heap, (*size) * sizeof(int));
		max_Heapify_Down(heap, *size, 0);
	} else { free(heap); heap = NULL; }
	return heap;
}

void max_Heapify_Down(int *heap, int n, int i) {
	int largest = i; int l = 2*i + 1; int r = 2*i + 2;
	if(l < n && heap[l] > heap[largest]) largest = l;
	if(r < n && heap[r] > heap[largest]) largest = r;
	if(largest != i) {
		int temp = heap[i]; heap[i] = heap[largest]; heap[largest] = temp;
		max_Heapify_Down(heap, n, largest);
	}
}

// --- MIN HEAP MENU VE MANTIGI ---

void min_Heap_Menu() {
	int *heap = NULL;
	int size = 0;
	int op;
	while(1) {
		printf("\n--- MIN HEAP SUB-MENU ---\n");
		printf("1 - Add Element\n2 - Delete Min Root\n3 - Print Traversal\n0 - Back to Main Menu\n: ");
		scanf("%d", &op);
		if(op == 1) heap = add_Min(heap, &size);
		else if(op == 2) heap = delete_Min(heap, &size);
		else if(op == 3) print_Heap(heap, size, "Min Heap");
		else if(op == 0) { free(heap); return; }
	}
}

int* add_Min(int *heap, int *size) {
	int taken_Data;
	printf("What is your value to add Min Heap: ");
	scanf("%d", &taken_Data);
	(*size)++;
	heap = (int*)realloc(heap, (*size) * sizeof(int));
	heap[(*size) - 1] = taken_Data;
	min_Heapify_Up(heap, (*size) - 1);
	printf("Your value added the heap!\n");
	return heap;
}

void min_Heapify_Up(int *heap, int index) {
	int parent = (index - 1) / 2;
	if (index > 0 && heap[index] < heap[parent]) {
		int temp = heap[index]; heap[index] = heap[parent]; heap[parent] = temp;
		min_Heapify_Up(heap, parent);
	}
}

int* delete_Min(int *heap, int *size) {
	if (*size == 0) { printf("Heap is empty!\n"); return heap; }
	printf("Min value %d deleted!\n", heap[0]);
	heap[0] = heap[(*size) - 1];
	(*size)--;
	if (*size > 0) {
		heap = (int*)realloc(heap, (*size) * sizeof(int));
		min_Heapify_Down(heap, *size, 0);
	} else { free(heap); heap = NULL; }
	return heap;
}

void min_Heapify_Down(int *heap, int n, int i) {
	int smallest = i; int l = 2*i + 1; int r = 2*i + 2;
	if(l < n && heap[l] < heap[smallest]) smallest = l;
	if(r < n && heap[r] < heap[smallest]) smallest = r;
	if(smallest != i) {
		int temp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = temp;
		min_Heapify_Down(heap, n, smallest);
	}
}

void print_Heap(int *heap, int size, char* name) {
	if (size == 0) { printf("%s is empty!\n", name); return; }
	printf("%s: ", name);
	for(int i=0; i<size; i++) printf("%d ", heap[i]);
	printf("\n");
}
