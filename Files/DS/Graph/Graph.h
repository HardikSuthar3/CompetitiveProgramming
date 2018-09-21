#include "bits/stdc++.h"
using namespace std;

#define MAX_Vertice 100

vector<long> G[MAX_Vertice];
vector<pair<int, int>> edgeList;
vector<pair<long, long>> weight;


vector<long> parent(MAX_Vertice, -1);
vector<bool> used(MAX_Vertice, false);
vector<long> dist(MAX_Vertice, -1);

int noOfVertices = 0, noOfEdges = 0;

///Graph creation module
void makeGraph(int V, int E) {
	noOfEdges = E;
	noOfVertices = V;

	for (size_t i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back((long)i);
		G[v].push_back((long)i);

		edgeList.push_back(make_pair(u, v));
		weight.push_back(make_pair(i, w));
	}
}
void printGraph() {
	cout << "Nodes" << endl;
	for (int i = 1; i <= noOfVertices; i++) {
		cout << i << " : ";
		for (int j = 0; j < G[i].size(); j++) {
			int edgeId = G[i][j];
			auto item = edgeList[edgeId];
			int neighb = item.first ^item.second ^i;
			cout << neighb << " ";
		}
		cout << endl;
	}


	cout << endl << endl << "Edges";
	for (int i = 0; i < noOfEdges; i++) {
		auto item = edgeList[i];
		int u = item.first;
		int v = item.second;
		int w = weight[i].second;
		cout << "(" << u << "," << v << ") : " << w << endl;
	}
}
void ClearGraph() {
	fill(parent.begin(), parent.begin() + noOfVertices + 1, -1);
	fill(used.begin(), used.begin() + noOfVertices + 1, false);
	fill(dist.begin(), dist.begin() + noOfVertices + 1, -1);

	edgeList.clear();
	weight.clear();
	for (int i = 0; i < noOfVertices; ++i) {
		G[i].clear();
	}

	noOfVertices = noOfEdges = 0;
}
///End of graph creation module


///Union Find Data Structure

//find parent
int Find(int x) {
	if (parent[x] == -1) {
		return x;
	}
	else {
		return Find(parent[x]);
	}
}
void Union(int x,int y) {
	int pX = Find(x); 
	int pY = Find(y);

	if (pX != pY) {
		parent[y] = pX;
	}
}
///End of Union Find

