#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];    // Adjacency Matrix
int visited[MAX];     // Dugum kontrol arrayi
int node_count = 0;

void graph_Olustur();
void kenar_Ekle();
void DFS(int v);
void BFS(int start_node);
void visited_Reset();

int main() {
	int operation, start_node;

	while(1) {
		printf("\n************************************\n");
		printf("      GRAPH SEARCH OPERATIONS\n");
		printf("1 - Graph'i Baslat (Node Sayisi Belirle)\n");
		printf("2 - Kenar Ekle (Add Edge)\n");
		printf("3 - DFS (Depth First Search) Uygula\n");
		printf("4 - BFS (Breadth First Search) Uygula\n");
		printf("0 - Cikis\n");
		printf(": ");
		scanf("%d", &operation);

		switch(operation) {
			case 1:
				graph_Olustur();
				break;
			case 2:
				if(node_count == 0) {
					printf("Once graph yapisini olusturun!\n");
					break;
				}
				kenar_Ekle();
				break;
			case 3:
				if(node_count == 0) break;
				visited_Reset();
				printf("DFS hangi dugumden baslasin (0-%d): ", node_count - 1);
				scanf("%d", &start_node);
				printf("DFS Traversal: ");
				DFS(start_node);
				printf("\n");
				break;
			case 4:
				if(node_count == 0) break;
				visited_Reset();
				printf("BFS hangi dugumden baslasin (0-%d): ", node_count - 1);
				scanf("%d", &start_node);
				printf("BFS Traversal: ");
				BFS(start_node);
				printf("\n");
				break;
			case 0:
				printf("Sistem kapatiliyor...\n");
				return 0;
			default:
				printf("Gecersiz secim!\n");
		}
	}
	return 0;
}

void graph_Olustur() {
	int x;
	printf("Kac dugumlu bir graph olsun: ");
	scanf("%d", &x);
	node_count = x;

	for(int i = 0; i < node_count; i++) {
		for(int j = 0; j < node_count; j++) {
			adj[i][j] = 0;
		}
	}
	printf("%d dugumlu matrix hazirlandi!\n", node_count);
}

void kenar_Ekle() {
	int u, v;
	printf("Baslangic dugumu: "); scanf("%d", &u);
	printf("Bitis dugumu: "); scanf("%d", &v);

	if(u < node_count && v < node_count) {
		adj[u][v] = 1;
		adj[v][u] = 1; // Yonlendirilmemis graph
		printf("Kenar basariyla eklendi!\n");
	} else {
		printf("Hatali dugum numaralari!\n");
	}
}

void visited_Reset() {
	for(int i = 0; i < MAX; i++) visited[i] = 0;
}

// Derinlemesine Arama (Recursive)
void DFS(int v) {
	visited[v] = 1;
	printf("%d ", v);

	for(int i = 0; i < node_count; i++) {
		if(adj[v][i] == 1 && !visited[i]) {
			DFS(i);
		}
	}
}

// Genisligine Arama (Queue Mantigiyla)
void BFS(int start_node) {
	int queue[MAX];
	int front = 0, rear = 0;

	// Baslangic dugumunu kuyruga at
	visited[start_node] = 1;
	queue[rear++] = start_node;

	

	while(front < rear) {
		int current = queue[front++]; // Kuyruktan cek (Dequeue)
		printf("%d ", current);

		for(int i = 0; i < node_count; i++) {
			// Komsu varsa ve gezilmemisse
			if(adj[current][i] == 1 && !visited[i]) {
				visited[i] = 1;
				queue[rear++] = i; // Kuyruga ekle (Enqueue)
			}
		}
	}
}
