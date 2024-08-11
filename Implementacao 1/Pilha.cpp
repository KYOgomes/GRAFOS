#include "Pilha.h"
using namespace std;
void Pilha::empilhar(int valor) {
    pilha.push(valor);
}

bool Pilha::encontrar(int valor) {
    stack<int> pilhaTemporaria = pilha;
    while (!pilhaTemporaria.empty()) {
        if (pilhaTemporaria.top() == valor) {
            return true;
        }
        pilhaTemporaria.pop();
    }
    return false;
}

void Pilha::desempilhar() {
    if (!pilha.empty()) {
        pilha.pop();
    }
}

void Pilha::removerK(int k) {
    for (int i = 0; i < k && !pilha.empty(); ++i) {
        pilha.pop();
    }
}
