#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Matrix.h"
using namespace std;

void performOperations() {
    LinkedList list;
    Stack stack;
    Queue queue;
    Matrix matrix(3, 3);

    int choice, n, k, value, row, col;

    while (true) {
        cout << "Escolha uma opcao:\n";
        cout << "1. Adicionar elementos\n";
        cout << "2. Encontrar um elemento\n";
        cout << "3. Remover um elemento\n";
        cout << "4. Sair\n";
        cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1:
                cout << "Digite a quantidade de numeros que quer adiocionar: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Enter value: ";
                    cin >> value;
                    list.add(value);
                    stack.push(value);
                    queue.enqueue(value);
                    cout << "Digite a linha e a coluna da matriz: ";
                    cin >> row >> col;
                    matrix.set(row, col, value);
                }
                break;
            case 2:
                cout << "Digite valor para pesquisar: ";
                cin >> value;
                cout << "Na lista: " << (list.find(value) ? "Sim" : "Nao") << "\n";
                cout << "Na pilha: " << (stack.find(value) ? "Sim" : "Nao") << "\n";
                cout << "Na fila: " << (queue.find(value) ? "Sim" : "Nao") << "\n";
                cout << "Na matriz: " << (matrix.find(value) ? "Sim" : "Nao") << "\n";
                break;
            case 3:
                cout << "Digite a quantidade de numeros que quer remover: ";
                cin >> k;
                list.removeFirstK(k);
                stack.removeK(k);
                queue.removeK(k);
                matrix.removeK(k);
                break;
            default:
                cout << "Escolha invalida!\n";
        }
    }
}

int main() {
    performOperations();
    return 0;
}