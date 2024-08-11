#ifndef PILHA_H
#define PILHA_H

#include <stack>
using namespace std;

class Pilha 
{
public:
    void empilhar(int valor);
    bool encontrar(int valor);
    void desempilhar();
    void removerK(int k);

private:
    stack<int> pilha;
};

#endif // PILHA_H
