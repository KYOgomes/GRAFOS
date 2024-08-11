#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

struct No 
{
    int dado;
    No* proximo;
};

class ListaEncadeada {
public:
    ListaEncadeada();
    void adicionar(int valor);
    bool encontrar(int valor);
    void remover(int valor);
    void removerPrimeiroK(int k);

private:
    No* cabeca;
};

#endif // LISTAENCADEADA_H
