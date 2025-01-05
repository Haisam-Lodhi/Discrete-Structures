//#include <iostream>
//
//using namespace std;
//
//// Function to perform union of two sets
//void Union(int* parent, int x, int y) {
//	// If the two nodes have different parents, set the parent of the smaller index node to the parent of the larger index node
//	if (parent[x] != parent[y]) {
//		if (parent[x] < parent[y]) {
//			parent[y] = parent[x];
//		}
//		else {
//			parent[x] = parent[y];
//		}
//	}
//}
//
//// Kruskal's algorithm
//void kruskal(int** adj_matrix, int n) {
//	int* parent = new int[n]; // Array to store the parent of each node in the disjoint set
//	int* edges = new int[n * (n - 1) / 2]; // Array to store the edges
//	int edge_count = 0; // Number of edges
//	int total_cost = 0; // Total cost of the MST
//
//						// Initialize the parent array with each node as its own parent
//	for (int i = 0; i < n; i++) {
//		parent[i] = i;
//	}
//
//	// Create a list of all edges and store them in the edges array
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (adj_matrix[i][j] != 0) {
//				edges[edge_count++] = adj_matrix[i][j];
//			}
//		}
//	}
//
//	// Sort the edges in ascending order
//	for (int i = 0; i < edge_count - 1; i++) {
//		for (int j = 0; j < edge_count - i - 1; j++) {
//			if (edges[j] > edges[j + 1]) {
//				int temp = edges[j];
//				edges[j] = edges[j + 1];
//				edges[j + 1] = temp;
//			}
//		}
//	}
//
//	cout << "Kruskal's MST:\n";
//	// Add edges to the MST as long as they don't create a cycle
//	for (int i = 0; i < edge_count; i++) {
//		int u, v;
//		for (int j = 0; j < n; j++) {
//			for (int k = j + 1; k < n; k++) {
//				if (adj_matrix[j][k] == edges[i]) {
//					u = j;
//					v = k;
//					break;
//				}
//			}
//		}
//		// Check if the two nodes have different parents
//		if (parent[u] != parent[v]) {
//			Union(parent, u, v);
//			total_cost += edges[i];
//			cout << u << " - " << v << " Weight: " << edges[i] << "\n";
//		}
//	}
//	cout << "Minimum cost using Kruskal's: " << total_cost << "\n";
//
//	delete[] parent;
//	delete[] edges;
//}
//
//// Prim's algorithm
//void prim(int** adj_matrix, int n) {
//	int* parent = new int[n]; // Array to store the parent of each node in the MST
//	int* key = new int[n]; // Array to store the minimum weight of each node
//	bool* visited = new bool[n]; // Array to keep track of visited nodes
//
//								 // Initialize the arrays
//	for (int i = 0; i < n; i++) {
//		parent[i] = -1;
//		key[i] = INT_MAX;
//		visited[i] = false;
//	}
//
//	key[0] = 0; // Start with the first node
//	parent[0] = -1; // The first node has no parent
//
//	cout << "Prim's MST:\n";
//	// Find the minimum spanning tree
//	for (int i = 0; i < n - 1; i++) {
//		int min_key = INT_MAX, min_index = -1;
//
//		// Find the node with the minimum weight that hasn't been visited
//		for (int j = 0; j < n; j++) {
//			if (!visited[j] && key[j] < min_key) {
//				min_key = key[j];
//				min_index = j;
//			}
//		}
//
//		visited[min_index] = true; // Mark the node as visited
//
//								   // Update the weights of the neighboring nodes
//		for (int j = 0; j < n; j++) {
//			if (adj_matrix[min_index][j] && !visited[j] && adj_matrix[min_index][j] < key[j]) {
//				parent[j] = min_index;
//				key[j] = adj_matrix[min_index][j];
//			}
//		}
//	}
//
//	int total_cost = 0;
//	for (int i = 1; i < n; i++) {
//		cout << parent[i] << " - " << i << " Weight: " << adj_matrix[parent[i]][i] << "\n";
//		total_cost += adj_matrix[parent[i]][i];
//	}
//	cout << "Minimum cost using Prim's: " << total_cost << "\n";
//
//	delete[] parent;
//	delete[] key;
//	delete[] visited;
//}
//
//int main() {
//	int n;
//	cout << "Enter the number of vertices: ";
//	cin >> n;
//
//	int** adj_matrix = new int*[n]; // Dynamically allocate the adjacency matrix
//	for (int i = 0; i < n; i++) {
//		adj_matrix[i] = new int[n];
//	}
//
//	cout << "Enter the adjacency matrix (use 0 for no edge):\n";
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> adj_matrix[i][j];
//		}
//	}
//
//	kruskal(adj_matrix, n);
//	cout << "\n";
//	prim(adj_matrix, n);
//
//	// Deallocate the dynamically allocated memory
//	for (int i = 0; i < n; i++) {
//		delete[] adj_matrix[i];
//	}
//	delete[] adj_matrix;
//
//	system("pause");
//	return 0;
//}