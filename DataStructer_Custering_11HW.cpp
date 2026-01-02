#include <stdio.h>

#define MAX_NODE 100

int adj[MAX_NODE][MAX_NODE];
int visited[MAX_NODE];
int nodeCount;

void createGraph(int n)
{
	nodeCount = n;

	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
		for (int j = 0; j < n; j++)
		{
			adj[i][j] = 0;
		}
	}
}

void addEdge(int u, int v)
{
	adj[u][v] = 1;
	adj[v][u] = 1;
}

void DFS(int node)
{
	visited[node] = 1;
	printf("%d ", node);

	for (int i = 0; i < nodeCount; i++)
	{
		if (adj[node][i] == 1 && visited[i] == 0)
		{
			DFS(i);
		}
	}
}

void findClusters()
{
	int clusterID = 1;

	for (int i = 0; i < nodeCount; i++)
	{
		if (visited[i] == 0)
		{
			printf("Cluster %d: { ", clusterID);
			DFS(i);
			printf("}\n");
			clusterID++;
		}
	}
}

int main()
{
	/*
		Graph Yapýsý:
		Cluster 1: 0 - 1 - 2
		Cluster 2: 3 - 4 - 5
		Cluster 3: 6 - 7 - 8
	*/

	createGraph(9);

	addEdge(0, 1);
	addEdge(1, 2);
	addEdge(3, 4);
	addEdge(4, 5);
	addEdge(3, 5);
	addEdge(6, 7);
	addEdge(7, 8);

	printf("Graph Clusters (Connected Components) \n");

	findClusters();

	return 0;
}
