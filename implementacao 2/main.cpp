#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Função para gerar subgrafos de um grafo completo
void gerarSubgrafos(int n) {
    int numSubgrafos = pow(2, n * (n - 1) / 2); // Formula para calcular número de subgrafos de um grafo completo
    cout << "Numero total de subgrafos gerados: " << numSubgrafos << endl;

    vector<pair<int, int>> arestas;

    // Criando a lista de arestas do grafo completo
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            arestas.push_back({i, j});
        }
    }

    // Gerando subgrafos
    for (int mask = 0; mask < numSubgrafos; ++mask) {
        cout << "Subgrafo " << mask + 1 << ": ";
        for (int i = 0; i < arestas.size(); ++i) {
            if (mask & (1 << i)) {
                cout << "(" << arestas[i].first << ", " << arestas[i].second << ") ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Informe o numero de vertices do grafo completo: ";
    cin >> n;

    if (n < 1) {
        cout << "O numero de vertices deve ser maior que zero." << endl;
        return 1;
    }

    gerarSubgrafos(n);

    return 0;
}
