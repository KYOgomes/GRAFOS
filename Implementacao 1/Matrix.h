#ifndef MATRIX_H
#define MATRIX_H
using namespace std;

#include <vector>

class Matrix {
public:
    Matrix(int rows, int cols);
    void set(int row, int col, int valor);
    bool encontrar(int valor);
    void removeK(int k);

private:
    int rows, cols;
    vector<vector<int>> matrix;
};

#endif // MATRIX_H
