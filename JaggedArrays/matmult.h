#ifndef MATMULT_H
#define MATMULT_H

namespace calculate {
    class matrixMultiplyer {
    private:
        int** Matrix;
        int row;
        int col;
    public:
        matrixMultiplyer(); 
        ~matrixMultiplyer();
        void calculateMatrix(int** mat1, int row1, int col1, int** mat2, int row2, int col2);
        void displayMatrix();
        bool chkMultiplication(int col1,int row2);
    };
};

#endif 
