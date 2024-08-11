#include <iostream>
#include "ListaEncadeada.h"
#include "Pilha.h"
#include "Fila.h"
#include "Matrix.h"
using namespace std;

// Função principal que realiza operações em várias estruturas de dados
void performOperations() {
    // Instanciando as estruturas de dados: lista encadeada, pilha, fila e matriz
    ListaEncadeada lista;
    Pilha pilha;
    Fila fila;
    Matrix matrix(3, 3); // Matriz 3x3

    int choice, n, k, valor, row, col; // Variáveis auxiliares

    while (true) { // Loop infinito até o usuário escolher sair
        // Exibindo o menu de opções para o usuário
        cout << "Escolha uma opcao:\n";
        cout << "1. Adicionar elementos\n";
        cout << "2. Encontrar um elemento\n";
        cout << "3. Remover elementos\n";
        cout << "4. Sair\n";
        cin >> choice;

        // Se o usuário escolher sair, o loop é interrompido
        if (choice == 4) break;

        switch (choice) {
            case 1:
                // Adicionar elementos às estruturas
                cout << "Digite a quantidade de numeros que quer adicionar: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Digitar valor: ";
                    cin >> valor;
                    lista.adicionar(valor); // Adiciona o valor na lista encadeada
                    pilha.empilhar(valor);  // Empilha o valor na pilha
                    fila.enfileirar(valor); // Enfileira o valor na fila
                    cout << "Digite a linha e a coluna da matriz: ";
                    cin >> row >> col;
                    matrix.set(row, col, valor); // Define o valor na posição especificada da matriz
                }
                break;
            case 2:
                // Procurar um elemento nas estruturas
                cout << "Digite valor para pesquisar: ";
                cin >> valor;
                cout << "Na lista: " << (lista.encontrar(valor) ? "Sim" : "Nao") << "\n";
                // Checa se o valor está na lista
                cout << "Na pilha: " << (pilha.encontrar(valor) ? "Sim" : "Nao") << "\n";
                // Checa se o valor está na pilha
                cout << "Na fila: " << (fila.encontrar(valor) ? "Sim" : "Nao") << "\n";
                // Checa se o valor está na fila
                cout << "Na matriz: " << (matrix.encontrar(valor) ? "Sim" : "Nao") << "\n";
                // Checa se o valor está na matriz
                break;
            case 3:
                // Remover elementos das estruturas
                cout << "Digite a quantidade de elementos que deseja remover: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Digite o valor " << i + 1 << " a ser removido: ";
                    cin >> k;
                    lista.removerPrimeiroK(k); // Remove o primeiro elemento igual a 'k' na lista
                    pilha.removerK(k);          // Remove o elemento 'k' da pilha
                    fila.removerK(k);           // Remove o elemento 'k' da fila
                    matrix.removeK(k);          // Remove o elemento 'k' da matriz
                }
                break;
            default:
                // Caso o usuário escolha uma opção inválida
                cout << "Escolha invalida\n";
        }
    }
}

int main() {
    performOperations(); // Chama a função que realiza as operações
    return 0;
}
