#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class matrizadyacencia {
private:
	int tam;
	int** matriz;
	void init() {
		for (int i = 0; i < tam; i++) {
			for (int j = 0; j < tam; j++) {
				matriz[i][j] = 0;
			}
		}
	}
public:
	matrizadyacencia();
	matrizadyacencia(int);
	void print();
	void addEdge(int, int);
	void adj(int);
	void bfs(int);
	void DFS(int);
};

matrizadyacencia::matrizadyacencia()
{
	this->tam = 0;
	this->matriz = nullptr;
}

matrizadyacencia::matrizadyacencia(int tam)
{
	this->tam = tam;
	this->matriz = new int* [this->tam];
	for (int i = 0; i < this->tam; i++) {
		this->matriz[i] = new int[this->tam];
	}
	this->init();
}

void matrizadyacencia::print() {
	cout << "MATRIZ ADYACENCIA" << endl;
	for (int i = 0; i < this->tam; i++) {
		for (int j = 0; j < this->tam; j++) {
			cout << *(*(this->matriz + i) + j) << "\t ";
		}
		cout << endl;
	}
}
void matrizadyacencia::addEdge(int v1, int v2) {
	if (v1 > this->tam || v2 > this->tam) {
		cout << "El vertice no existe" << endl;
	}
	else {
		this->matriz[v1][v2] = 1;
	}
}
void matrizadyacencia::adj(int v) {
	cout << "Lista de vertices adyacentes al vertice " << v << ": ";
	for (int i = 0; i < this->tam; i++) {
		if (this->matriz[v][i] == 1) {
			cout << i << ",";
		}
	}
	cout << endl;
}

//RECORRIDO EN ANCHURA
void matrizadyacencia::bfs(int s) {
	vector<bool> visitas(this->tam);
	for (int b = 0; b < visitas.size(); b++) {
		visitas[b]=false;
	}
	queue<int> ga;
	visitas[s] = true;
	ga.push(s);
	std::cout << "BFS: ";
	while (!ga.empty()) {
		
		s = ga.front();
		std::cout << s << " ";	ga.pop();
		for (int i = 0; i < this->tam; i++) {
			if (matriz[s][i] == 1 && visitas[i]!=true) {
				visitas[i] = true;
				ga.push(i);
			}
		}
	}
}

//RECORRIDO EN PROFUNDIDAD ITERATIVO
void matrizadyacencia::DFS(int s) {
	stack<int> ra;
	vector<bool> visitar(this->tam);
	for (int b = 0; b < visitar.size(); b++) {
		visitar[b] = false;
	}

	visitar[s] = true;
	ra.push(s);
	std::cout << "DFS: ";
	while (!ra.empty()) {
		s = ra.top();
		std::cout << s << " ";
		ra.pop();
		for (int i = 0; i < this->tam; i++) {
			if (matriz[s][i] == 1 && visitar[i] != true) {
				visitar[i] = true;
				ra.push(i);
			}
		}
	}
}

int main() {
	matrizadyacencia m1(6);
	m1.addEdge(0, 2);
	m1.addEdge(0, 4);
	m1.addEdge(0, 3);
	m1.addEdge(5, 1);
	m1.addEdge(1, 2);
	m1.addEdge(3, 5);
	m1.addEdge(3, 4);
	m1.addEdge(2, 4);
	m1.addEdge(4, 5);
	m1.print();
	m1.bfs(0);
	cout << endl;
	m1.DFS(0);
}