#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, vector<string>> grafo;
set<vector<string>> ciclos;

void dfs(string inicio, string atual, vector<string>& caminho, set<string>& visitados) {
    caminho.push_back(atual);
    visitados.insert(atual);
    
    for (const string& vizinho : grafo[atual]) {
        if (vizinho == inicio && caminho.size() > 2) { 
            vector<string> ciclo = caminho;
            sort(ciclo.begin(), ciclo.end());  // Normaliza o ciclo para evitar repetições de ordem
            ciclos.insert(ciclo);
        } 
        else if (visitados.find(vizinho) == visitados.end()) { 
            dfs(inicio, vizinho, caminho, visitados);
        }
    }
    
    caminho.pop_back();
    visitados.erase(atual);
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

    cin.ignore();
    for (const string& v : vertices) {
        cout << "O vertice [" << v << "] esta ligado a quais vertices? (Digite 0 se nenhum, ou nomes separados por espaco): ";
        string conexoes;
        getline(cin, conexoes);
        
        if (conexoes != "0") {
            stringstream ss(conexoes);
            string vizinho;
            while (ss >> vizinho) {
                grafo[v].push_back(vizinho);
            }
        }
    }

    for (const string& v : vertices) {
        vector<string> caminho;
        set<string> visitados;
        dfs(v, v, caminho, visitados);
    }

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
