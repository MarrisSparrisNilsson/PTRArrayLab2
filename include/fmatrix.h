
#ifndef _fmatrix_h
#define _fmatrix_h

#define ROWS 3
#define COLS 3
#define SIZE 100

typedef float fMatrix[ROWS][COLS];

fMatrix* createMatrix(float f);
void destroyMatrix(fMatrix* m);
void printMatrix(fMatrix* m);
bool getMatrix(fMatrix* m);
void matAdd(fMatrix* m1, fMatrix* m2);
void matMul(fMatrix* m1, fMatrix* m2);

#endif /* _fmatrix_h */