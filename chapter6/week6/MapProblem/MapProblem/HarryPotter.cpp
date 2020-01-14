#include <iostream>
using namespace std;
#define Maxsize 100
#define Infinity 65535
typedef int Vertex;
typedef int weight;
typedef struct MgraphNode* Mgraph;
typedef struct EdgeNode* Edge;
struct MgraphNode{
	int ne;
	int nv;
	weight G[Maxsize][Maxsize];
};
struct EdgeNode {
	Vertex v1;
	Vertex v2;
	weight w;
};

Mgraph buildgraph(int Nv) {
	Mgraph map = new MgraphNode;
	map->ne = 0;
	map->nv = Nv;
	for (int i = 0; i < Nv; i++) {
		for (int j = 0; j < Nv; j++) {
				map->G[i][j] = Infinity;
		}
	}
	return map;
}

Edge ScanEdge() {
	Edge res = new EdgeNode;
	cin >> res->v1 >> res->v2 >> res->w;
	return res;
}

void InsertEdge(Mgraph map,Edge e) {
	Vertex v1=e->v1;
	Vertex v2 = e->v2;
	map->G[v1-1][v2-1] = e->w;
	map->G[v2 - 1][v1 - 1] = e->w;
	map->ne++;
}

void Floyd(Mgraph M) {
	int nv = M->nv;
	auto W = M->G;
	for (int k = 0; k < nv; k++) {
		for (int i = 0; i < nv; i++) {
			for (int j = 0; j < nv; j++) {
				if (W[i][k] + W[k][j] < W[i][j]) {
					W[i][j] = W[i][k] + W[k][j];
				}
			}
		}
	}
}

/*
weight FindRowMax(Mgraph M, Vertex V) {
	int nv = M->nv;
	auto W = M->G;
	weight RowMaximum = 0;
	for (int j = 0; j < nv; j++) {
		if (V!=j&&RowMaximum < W[V][j]) {
			RowMaximum = W[V][j];
		}
	}
	return RowMaximum;
}
void FindMinDist(Mgraph M) {
	int nv = M->nv;
	weight MaxMat=Infinity;
	Vertex Vindex;
	for (int i = 0; i < nv; i++) {
		if (MaxMat > FindRowMax(M, i)) {
			MaxMat = FindRowMax(M, i);
			Vindex = i + 1;
		}
	}
	if (MaxMat == Infinity)
		cout << "0" << endl;
	else
		cout << Vindex << " " << MaxMat << endl;

}
*/


void FindMinDist(Mgraph M) {
	int nv = M->nv;
	int MinMaxrowtemp=Infinity;
	Vertex Vindex=0;
	auto W = M->G;
	for (int i = 0; i < nv; i++) {
		int maxrowtemp = 0;
		for (int j = 0; j < nv; j++) {
			if (i!=j&&W[i][j] > maxrowtemp) {
				maxrowtemp = W[i][j];
			}
		}
		if (maxrowtemp <MinMaxrowtemp) {
			MinMaxrowtemp = maxrowtemp;
				Vindex = i+1;
		}
	}
	if (MinMaxrowtemp == Infinity)
		cout << "0" << endl;
	else
	cout << Vindex << " " << MinMaxrowtemp << endl;
}


void DispMap(Mgraph M) {
	auto W = M->G;
	int nv = M->nv;
	for (int i = 0; i < nv; i++) {
		for (int j = 0; j < nv; j++) {
			cout << W[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int nv, ne;
	Edge e;
	cin >> nv >> ne;
	Mgraph map = buildgraph(nv);
	for (int i = 0; i < ne; i++) {
		e = ScanEdge();
		InsertEdge(map, e);
	}
	DispMap(map);
	Floyd(map);
	cout << endl;
	DispMap(map);

	FindMinDist(map);
	return 0;
}


