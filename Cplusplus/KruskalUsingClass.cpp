#include <iostream>
#include <algorithm>
using namespace std;

class Edge {
	public :
		int source;
		int dest;
		int weight;
};

bool compareEdge(Edge E1, Edge E2) {
	return E1.weight < E2.weight;
}

int findNext(int V, int *parent) {
	if (parent[V] == V) {
		return V;
	}
	return findNext(parent[V], parent);
}

void KruskalsAlgorithm(Edge *input, int V, int E) {
	// Step 1 : Sorting based on weights
	sort(input, input + E, compareEdge);
	
	Edge *output = new Edge[V-1];
	
	int *next = new int[V];
	for (int i = 0; i < V; i++) {
		next[i] = i;
	}
	
	int counter = 0;
	int i = 0;
	while (counter != (V-1)) {
		Edge currentEdge = input[i];
		
		// Step 2 : Detect Cycle
		int sourceNext = findNext(currentEdge.source, next);
		int destNext = findNext(currentEdge.dest, next);
		
		if (sourceNext != destNext) {
			output[counter] = currentEdge;
			counter++;
			next[sourceNext] = destNext;
		}
		i++;
	}
	int sumOfWeights = 0;
	cout << "Edges in MST are:" << endl;
	cout << "Source" << "\t" << "    Destination" << "\t" << "     Weight" << endl;
	for (int i = 0; i < V-1; i++) {
		if (output[i].source < output[i].dest) {
			cout << output[i].source << "\t\t" << output[i].dest << "\t\t" << output[i].weight << endl;
		} else {
			cout << output[i].dest << "\t\t" << output[i].source << "\t\t" << output[i].weight << endl;
		}
		sumOfWeights += output[i].weight;
	}
	cout << "The sum of weights of MST is: " << sumOfWeights << endl;
}

int main () {
	int V, E;
	cout << "Enter no. of vertices: " << endl;
	cin >> V;
	cout << "Enter no. of edges: " << endl;
	cin >> E;
	Edge *input = new Edge[E];
	
	for (int i = 0; i < E; i++) {
		int source, dest, weight;
		cout << "For Edge " << i + 1 << " enter the {Source Destination Weight} sperated by space" << endl;
		cin >> source >> dest >> weight;
		input[i].source = source;
		input[i].dest = dest;
		input[i].weight = weight;
	}
	
	KruskalsAlgorithm(input, V, E);
}
