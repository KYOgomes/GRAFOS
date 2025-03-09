#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

map<string, vector<string>> grafo;
set<vector<string>> ciclos;

void buscarCiclos(string inicio, string atual, vector<string> caminho, set<string> visitados) {
    caminho.push_back(atual);
    visitados.insert(atual);

    for (string vizinho : grafo[atual]) {
        if (vizinho == inicio && caminho.size() > 2) { 
            // Encontramos um ciclo, adicionar ao conjunto de ciclos
            ciclos.insert(caminho);
        } 
        else if (visitados.find(vizinho) == visitados.end()) { 
            buscarCiclos(inicio, vizinho, caminho, visitados);
        }
    }
}

int main() {
    int n;
    cout << "Digite o numero de vertices: ";
    cin >> n;

    vector<string> vertices(n);
    cout << "Escreva o nome dos vertices: ";
    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
    }

    // Entrada das arestas
    for (const string& v : vertices) {
        cout << "O vertice [" << v << "] esta ligado a quais vertices? (Digite 0 se nenhum, ou nomes separados por espaco): ";
        string conexoes;
        cin.ignore();
        getline(cin, conexoes);
        
        if (conexoes != "0") {
            stringstream ss(conexoes);
            string vizinho;
            while (ss >> vizinho) {
                grafo[v].push_back(vizinho);
            }
        }
    }

    // Encontrar ciclos para cada vértice
    for (const string& v : vertices) {
        vector<string> caminho;
        set<string> visitados;
        buscarCiclos(v, v, caminho, visitados);
    }

    // Exibir ciclos encontrados
    cout << "\nCiclos encontrados:\n";
    for (const auto& ciclo : ciclos) {
        for (const string& v : ciclo) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << "Total de ciclos: " << ciclos.size() << endl;
    return 0;
}
