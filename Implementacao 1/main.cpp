#include <iostream>
#include "ListaEncadeada.h"
#include "Pilha.h"
#include "Fila.h"
#include "Matrix.h"
using namespace std;

void performOperations() {
    ListaEncadeada lista;
    Pilha pilha;
    Fila fila;
    Matrix matrix(3, 3);

    int choice, n, k, valor, row, col;

    while (true) {
        cout << "Escolha uma opcao:\n";
        cout << "1. Adicionar elementos\n";
        cout << "2. Encontrar um elemento\n";
        cout << "3. Remover elementos\n";
        cout << "4. Sair\n";
        cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1:
                cout << "Digite a quantidade de numeros que quer adicionar: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Digitar valor: ";
                    cin >> valor;
                    lista.adicionar(valor);
                    pilha.empilhar(valor);
                    fila.enfileirar(valor);
                    cout << "Digite a linha e a coluna da matriz: ";
                    cin >> row >> col;
                    matrix.set(row, col, valor);
                }
                break;
            case 2:
                cout << "Digite valor para pesquisar: ";
                cin >> valor;
                cout << "Na lista: " << (lista.encontrar(valor) ? "Sim" : "Nao") << "\n";
                cout << "Na pilha: " << (pilha.encontrar(valor) ? "Sim" : "Nao") << "\n";
                cout << "Na fila: " << (fila.encontrar(valor) ? "Sim" : "Nao") << "\n";
                cout << "Na matriz: " << (matrix.encontrar(valor) ? "Sim" : "Nao") << "\n";
                break;
            case 3:
                cout << "Digite a quantidade de elementos que deseja remover: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Digite o valor " << i + 1 << " a ser removido: ";
                    cin >> k;
                    lista.removerPrimeiroK(k);
                    pilha.removerK(k);
                    fila.removerK(k);
                    matrix.removeK(k);
                }
                break;
            default:
                cout << "Escolha invalida\n";
        }
    }
}

int main() {
    performOperations();
    return 0;
}
