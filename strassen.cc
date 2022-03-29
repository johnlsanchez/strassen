#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <ctime>
#include <iostream>

// struct matrix {
//     int* mat;

//     matrix(int n, int* values) {
//         mat = new int[n * n];
//         for (int i = 0; i < n * n; i++) {
//             mat[i] = values[i];
//         }
//     }
// };

// // matrix* transpose(int n, matrix* a) {
// //     int ans[n * n];
// //     if ()
// // }

// matrix* standard_mult(int n, matrix* a, matrix* b) {
//     int answer[n * n];
//     matrix* b_t = b; // change to transpose
    
//     int pos = 0;
//     for (int i = 0; i < n; i++) {
//         int sum = 0;
//         for (int j = 0; j < n * n; j++) {
//             sum += a->mat[i * n + j % n] * b_t->mat[j];
//             if (j % n == n - 1) {
//                 answer[pos] = sum;
//                 pos++;
//                 sum = 0;
//             }
            
//         }
//     }


//     matrix* product = new matrix(n, answer);
//     return product;
// }

class matrix {
    public:
        matrix(int* file_data, int dim) {
            dim_ = dim;
            for (int i = 0; i < dim_; i++) {
                data_[i] = file_data[i];
            }
        }

        void print() {
            for (int i = 0; i < dim_; i++) {
                for (int j = 0; j < dim_; j++) {
                    std::cout << data_[i * dim_ + j] << ' ';
                }
                std::cout << '\n';
            }
        }

    private:
        int* data_;
        int dim_;
};

int main() {
    std::cout << 'p';
    int a[4] = {1, 2, 3, 4};
    std::cout << 'p';
    matrix A = matrix(a, 2);
    std::cout << 'p';
    A.print();
    std::cout << 'p';
}