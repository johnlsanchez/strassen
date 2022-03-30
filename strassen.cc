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
        data_ = (int*)malloc(sizeof(int) * dim * dim);
        dim_ = dim;
        for (int i = 0; i < dim_ * dim_; i++) {
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

    matrix mul(matrix B) {
        int* c_data;
        c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
        for (int i = 0; i < this->dim_; i++) {
            for (int j = 0; j < this->dim_; j++) {
                int sum = 0;
                for (int k = 0; k < this->dim_; k++) {
                    sum += this->at(j, k) * B.at(k, i);
                }
                c_data[j * this->dim_ + i] = sum;
            }
        }
        return matrix(c_data, this->dim_);

    }
    matrix add(matrix B) {
        int* c_data;
        c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
        for (int i = 0; i < this->dim_ * this->dim_; i++) {
            c_data[i] = this->at(i / this->dim_, i % this->dim_) + B.at(i / this->dim_, i % this->dim_);
        }
        return matrix(c_data, this->dim_);

    }
    matrix sub(matrix B) {
        int* c_data;
        c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
        for (int i = 0; i < this->dim_ * this->dim_; i++) {
            c_data[i] = this->at(i / this->dim_, i % this->dim_) - B.at(i / this->dim_, i % this->dim_);
        }
        return matrix(c_data, this->dim_);

    }
    

    matrix strassen(matrix B) {
        

    }

    int at(int r, int c) {
        return data_[r * this->dim_ + c];
    }

    int block_at(int r, int c, int quad_number, int block_size) {
        int child_start_r = r + block_size * (quad_number % 2);
    }

private:
    int* data_;
    int dim_;
    int* strassen_rec(int* data) {
        return NULL;
    };
};

//void make_matrix_h(int& in_data, int& data, int big_dim, int dim, int seg, int r, int c) {
//    if (dim == 2) {
//        data[r * big_dim + c] = in_data[r * big_dim + c];
//        data[r * big_dim + c] = in_data[r * big_dim + c + 1];
//        data[r * big_dim + c] = in_data[r * big_dim + c];
//        data[r * big_dim + c] = in_data[r * big_dim + c];
//    }
//}
//
//int* make_matrix(int* in_data, int dim) {
//    int* data;
//    data = (int*)malloc(sizeof(int) * dim * dim);
//    make_matrix_h(*in_data, *data, dim, dim / 2, 0, 0, 0);
//    make_matrix_h(*in_data, *data, dim, dim / 2, 1, 0, dim / 2);
//    make_matrix_h(*in_data, *data, dim, dim / 2, 2, dim / 2, 0);
//    make_matrix_h(*in_data, *data, dim, dim / 2, 3, dim / 2, dim / 2);
//}



int main() {
    int a[4] = { 1, 2, 3, 4 };
    int b[4] = { 5, 6, 7, 8 };
    matrix A = matrix(&a[0], 2);
    matrix B = matrix(&b[0], 2);
    A.print();
    B.print();
    matrix C = A.sub(B);
    C.print();
;}