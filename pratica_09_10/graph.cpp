#include "graph.h"
#include "heap.h"

#include <queue>

using namespace std;

// Cria array do tipo T com tamanho "size" e inicializa com valor "def"
template<class T>
T* array(int size, T def) {
	T *arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = def;
	return arr;
}

Graph::Graph(int nVert) {
	this->nVert = nVert;
	this->adj = new list<Edge> [nVert];
}

Graph::~Graph() {
	delete[] adj;
}

int Graph::size() {
	return nVert;
}

// Cria��o da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
	//Edge edge = Edge(src, dst, w);
	//adj[src].push_back(edge);
	adj[src].push_back(Edge(src, dst, w));
}

int Graph::degree(int src) {

	return adj[src].size();
}

list<int> Graph::neighbors(int src) {
	list<int> neighbors;
	for (Edge edge : adj[src]) {
		neighbors.push_back(edge.dst);
	}
	;

	return neighbors;
}

int Graph::weight(int src, int dst) {
	for (Edge e : adj[src]) {
		if (e.dst == dst) {
			return e.weight;
		}
	}

	return -1;
}

void Graph::print() {
	for (int i = 0; i < this->size(); i++) {
		int d = this->degree(i);

		cout << i << "(" << d << "): ";

		list<int> nei = this->neighbors(i);
		for (int dst : nei) {
			int w = this->weight(i, dst);
			cout << dst << "[" << w << "]; ";
		}

		cout << endl;
	}
}

bool Graph::isConnected() {
	int group[nVert];

	for (int i = 0; i < nVert; i++) {
		group[i] = i;
	}

	for (int i = 0; i < nVert; i++) {
		for (Edge edge : adj[i]) {
			int srcGroup = group[i];
			int dstGroup = group[edge.dst];
			if (srcGroup != dstGroup) {
				for (int j = 0; j < nVert; j++) {
					if (group[j] == dstGroup) {
						group[j] = srcGroup;
					}
				}
			}
		}
	}

	int firstGroup = group[0];
	for (int i = 1; i < nVert; i++) {
		if (group[i] != firstGroup) {
			return false;
		}
	}
	return true;
}

// -------- PRAT 10 --------------//

// Busca em profundidade
list<int> Graph::dfs(int src) {
	list<int> result;
	bool visited[nVert] = { 0 };

	DFS(src, visited, result);

	return result;
}

// Busca em profundidade
void Graph::DFS(int src, bool (&visited)[], list<int> &result) {
	visited[src] = true;
	result.push_back(src);

	for (Edge edge : adj[src]) {
		int neighbor = edge.dst;
		if (!visited[neighbor]) {
			DFS(neighbor, visited, result);
		}
	}

}

// Busca em largura
list<int> Graph::bfs(int src) {
	list<int> result;
	bool visited[nVert] = { 0 };

	BFS(src, visited, result);

	return result;
}

// Busca em largura
void Graph::BFS(int src, bool (&visited)[], list<int> &result) {
	queue<int> f;

	// Marque todos os vértices como não visitados
	for (int i = 0; i < nVert; i++) {
		visited[i] = false;
	}

	// Colocar v na fila F e marcar v como visitado
	f.push(src);
	visited[src] = true;

	// ENQUANTO F não vazia, FAÇA
	while (!f.empty()) {
		// Pegue vértice w da fila F
		int w = f.front();
		f.pop();
		result.push_back(w);

		// PARA os vértices adjacentes x de w, FAÇA
		for (Edge x : adj[w]) {
			// SE x não visitado, ENTÃO
			if (!visited[x.dst]) {
				// coloque x na fila F
				f.push(x.dst);
				// marque x como visitado
				visited[x.dst] = true;
			}
		}
	}
}

list<int> Graph::spf(int src, int dst) {
	int *dist = array(nVert, 99999);// array de dist�ncias acumuladas; 99999 = INF
	int *prev = array(nVert, -1);			// array de v�rtices anteriores
											//   cont�m menores caminhos
	dist[src] = 0;

	// Cria o heap (m�nimo) baseado na dist�ncia
	Heap<int> pq(nVert, dist);

	while (!(pq.empty())) {
		int node = pq.dequeue();	// pega n� com menor dist�ncia acumulada

		for (Edge e : adj[node]) {
			int v = e.dst;				// n� vizinho
			int w = e.weight;			// peso da aresta

			int D = dist[node] + w;			// nova dist�ncia

			if (D < dist[v]) {				// menor que antiga?
				prev[v] = node;				// atualize anterior
				dist[v] = D;				// atualize dist�ncia
				pq.decrease(v);				// atualize o heap (PQ)
			}
		}
	}

	list<int> result;						// menor caminho

	path(dst, prev, result);				// extrair caminho em result

	delete[] dist;
	delete[] prev;

	return result;
}

void Graph::path(int dst, int *prev, list<int> &result) {
	queue<int> q;
	bool *visited = new bool[nVert];

	for (int i = 0; i < nVert; i++) {
		visited[i] = false;
	}
	q.push(dst);
	visited[dst] = true;
	while (!q.empty()) {
		int w = q.front();
		q.pop();
		for (Edge x : adj[w]) {
			if (!visited[x.dst]) {
				q.push(x.dst);
				visited[x.dst] = true;
				prev[x.dst] = w;
			}
		}
	}
	// Adicione o caminho encontrado à lista "result"
	if (prev[dst] != -1) {
		int curr = dst;
		while (curr != -1) {
			result.push_front(curr);
			curr = prev[curr];
		}
	}

}

