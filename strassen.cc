#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <ctime>
#include <iostream>


class matrix {
    public:
        matrix(int* file_data, int dim) {
            this->data_ = file_data;
            dim_ = dim;
            dim_whole_ = dim;
            r_start_ = 0;
            c_start_ = 0;
        }
    


    // matrix mul(matrix B) {
    //     int* c_data;
    //     c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
    //     for (int i = 0; i < this->dim_; i++) {
    //         for (int j = 0; j < this->dim_; j++) {
    //             int sum = 0;
    //             for (int k = 0; k < this->dim_; k++) {
    //                 sum += this->at(j, k) * B.at(k, i);
    //             }
    //             c_data[j * this->dim_ + i] = sum;
    //         }
    //     }
    //     return matrix(c_data, this->dim_);

    // }


        matrix add(matrix B) {
            int* c_data = (int*) malloc(sizeof(int) * this->dim_ * this->dim_);
            for (int i = 0; i < this->dim_; i++) {
                for (int j = 0; j < this->dim_; j++) {
                    c_data[i * this->dim_ + j] = this->at(i, j) + B.at(i, j);
                }
            }
            return matrix(c_data, this->dim_);
        }

        matrix sub(matrix B) {
            int* c_data = (int*) malloc(sizeof(int) * this->dim_ * this->dim_);
            for (int i = 0; i < this->dim_; i++) {
                for (int j = 0; j < this->dim_; j++) {
                    c_data[i * this->dim_ + j] = this->at(i, j) + B.at(i, j);
                }
            }
            return matrix(c_data, this->dim_);
        }

        void shift_start_pointer(int r_start, int c_start, int new_dim) {
            this->r_start_ += r_start;
            this->c_start_ += c_start;
            this->dim_ = new_dim;
        }

        int at(int r, int c) {
            assert(r < this->dim_);
            assert(c < this->dim_);
            return this->data_[(this->r_start_ + r) * this->dim_whole_ + this->c_start_ + c];
        }

    private:
        int* data_;
        int dim_whole_;
        int dim_;
        int r_start_;
        int c_start_;
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
    int a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    matrix A = matrix(a, 4);
    A.shift_start_pointer(1, 1, 2);
    // A.print();
}
