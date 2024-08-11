#ifndef FILA_H
#define FILA_H

#include <queue>
using namespace std;

class Fila {
public:
    void enfileirar(int valor);
    bool encontrar(int valor);
    void desenfileirar();
    void removerK(int k);

private:
    queue<int> fila;
};

#endif // FILA_H
