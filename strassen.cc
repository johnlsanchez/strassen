#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <ctime>

struct matrix {
    int* mat;

    matrix(int n, int* values) {
        mat = new int[n * n];
        for (int i = 0; i < n * n; i++) {
            mat[i] = values[i];
        }
    }
};

// matrix* transpose(int n, matrix* a) {
//     int ans[n * n];
//     if ()
// }

matrix* standard_mult(int n, matrix* a, matrix* b) {
    int answer[n * n];
    matrix* b_t = b; // change to transpose
    
    int pos = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n * n; j++) {
            sum += a->mat[i * n + j % n] * b_t->mat[j];
            if (j % n == n - 1) {
                answer[pos] = sum;
                pos++;
                sum = 0;
            }
            
        }
    }


    matrix* product = new matrix(n, answer);
    return product;
}


int main() {
    
}