#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

map<string, vector<string>> grafo;
set<vector<string>> ciclos;

// Função para verificar se dois vértices são adjacentes
bool saoAdjacentes(const string& a, const string& b) {
    return find(grafo[a].begin(), grafo[a].end(), b) != grafo[a].end();
}

// Função para normalizar um ciclo (começar com o menor vértice e seguir ordem crescente)
vector<string> normalizarCiclo(vector<string> ciclo) {
    // Encontra a posição do menor vértice
    auto minIt = min_element(ciclo.begin(), ciclo.end());
    // Rotaciona o ciclo para começar com o menor vértice
    rotate(ciclo.begin(), minIt, ciclo.end());

    // Verifica se o ciclo está em ordem crescente ou decrescente
    // Se o segundo vértice for maior que o último, inverte o ciclo
    if (ciclo.size() > 2 && ciclo[1] > ciclo.back()) {
        reverse(ciclo.begin() + 1, ciclo.end());
    }

    return ciclo;
}

// Função para verificar se uma permutação forma um ciclo
void verificarPermutacao(const vector<string>& perm) {
    int n = perm.size();

    // Verifica todos os subconjuntos da permutação que podem formar ciclos
    for (int tam = 3; tam <= n; ++tam) { // Ciclos de tamanho >= 3
        for (int i = 0; i <= n - tam; ++i) {
            vector<string> sub(perm.begin() + i, perm.begin() + i + tam);

            // Verifica se o subconjunto forma um ciclo
            bool cicloValido = true;
            for (int j = 0; j < sub.size() - 1; ++j) {
                if (!saoAdjacentes(sub[j], sub[j + 1])) {
                    cicloValido = false;
                    break;
                }
            }

            // Verifica se o último vértice conecta ao primeiro
            if (cicloValido && saoAdjacentes(sub.back(), sub.front())) {
                // Normaliza o ciclo
                vector<string> cicloNormalizado = normalizarCiclo(sub);
                ciclos.insert(cicloNormalizado);
            }
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

    // Gera todas as permutações dos vértices
    sort(vertices.begin(), vertices.end());
    do {
        verificarPermutacao(vertices);
    } while (next_permutation(vertices.begin(), vertices.end()));

    // Exibe os ciclos encontrados
    cout << "\nCiclos encontrados:\n";
    for (const auto& ciclo : ciclos) {
        for (const auto& v : ciclo) {
            cout << v << " ";
        }
        cout << ciclo[0] << " (volta ao início)\n";
    }

    // Exibe o número total de ciclos encontrados
    cout << "\nTotal de ciclos encontrados: " << ciclos.size() << endl;

    return 0;
}