#include "ListaEncadeada.h"

ListaEncadeada::ListaEncadeada() : cabeca(nullptr) {}

void ListaEncadeada::adicionar(int valor) {
    No* novoNo = new No{valor, cabeca};
    cabeca = novoNo;
}

bool ListaEncadeada::encontrar(int valor) {
    No* atual = cabeca;
    while (atual != nullptr) {
        if (atual->dado == valor) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

void ListaEncadeada::remover(int valor) {
    No* atual = cabeca;
    No* anterior = nullptr;
    while (atual != nullptr && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual != nullptr) {
        if (anterior == nullptr) {
            cabeca = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        delete atual;
    }
}

void ListaEncadeada::removerPrimeiroK(int k) {
    for (int i = 0; i < k && cabeca != nullptr; ++i) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        delete temp;
    }
}
