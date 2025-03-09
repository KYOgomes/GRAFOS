#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Grafo {
public:
    int n; // Número de vértices
    vector<string> vertices;
    vector<vector<int>> adj; // Lista de adjacência

    Grafo(int numVertices) {
        n = numVertices;
        adj.resize(n);
        vertices.resize(n);
    }

    void adicionarAresta(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Grafo não-direcionado
    }

    void encontrarCiclos() {
        set<vector<int>> ciclos;
        vector<int> perm(n);
        for (int i = 0; i < n; i++) perm[i] = i;

        do {
            if (adj[perm[n-1]].end() != find(adj[perm[n-1]].begin(), adj[perm[n-1]].end(), perm[0])) {
                bool cicloValido = true;
                for (int i = 0; i < n - 1; i++) {
                    if (find(adj[perm[i]].begin(), adj[perm[i]].end(), perm[i + 1]) == adj[perm[i]].end()) {
                        cicloValido = false;
                        break;
                    }
                }
                if (cicloValido) {
                    vector<int> ciclo = perm;
                    sort(ciclo.begin(), ciclo.end());
                    ciclos.insert(ciclo);
                }
            }
        } while (next_permutation(perm.begin(), perm.end()));

        cout << "Ciclos encontrados:" << endl;
        for (auto ciclo : ciclos) {
            for (int v : ciclo) cout << vertices[v] << " ";
            cout << vertices[ciclo[0]] << endl; // Fechar o ciclo
        }
    }
};

int main() {
    int numVertices;
    cout << "Digite o número de vértices: ";
    cin >> numVertices;

    Grafo grafo(numVertices);

    cout << "Escreva o nome dos vértices:" << endl;
    for (int i = 0; i < numVertices; i++) {
        cin >> grafo.vertices[i];
    }

    cin.ignore(); // Limpar buffer do teclado

    for (int i = 0; i < numVertices; i++) {
        cout << grafo.vertices[i] << " está ligado a quais? (Digite os nomes separados por espaço ou 0 para nenhum): ";
        string linha;
        getline(cin, linha);

        if (linha != "0") {
            vector<string> conexoes;
            string nome;
            for (char c : linha) {
                if (c == ' ') {
                    conexoes.push_back(nome);
                    nome = "";
                } else {
                    nome += c;
                }
            }
            if (!nome.empty()) conexoes.push_back(nome);

            for (string conexao : conexoes) {
                auto it = find(grafo.vertices.begin(), grafo.vertices.end(), conexao);
                if (it != grafo.vertices.end()) {
                    int j = distance(grafo.vertices.begin(), it);
                    grafo.adicionarAresta(i, j);
                }
            }
        }
    }

    grafo.encontrarCiclos();
    return 0;
}
