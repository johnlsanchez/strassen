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
        data_ = file_data;
        dim_ = dim;
        r_start_ = 0;
        c_start_ = 0;
        dim_whole_ = dim;
    }

    matrix(int* file_data, int dim_whole, int dim, int r_start, int c_start) {
        data_ = file_data;
        dim_whole_ = dim_whole;
        dim_ = dim;
        r_start_ = r_start;
        c_start_ = c_start;
    }

    void print() {
        for (int i = 0; i < dim_; i++) {
            for (int j = 0; j < dim_; j++) {
                std::cout << (*this)(i,j) << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    inline int& operator()(int r, int c) {
        return data_[dim_ * r + c];
    }

    inline int operator()(int r, int c) const {
        return data_[dim_ * r + c];
    }

    inline int dim() {
        return dim_;
    }

    matrix operator*(matrix B) {
        int* c_data;
        c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
        matrix C = matrix(c_data, this->dim_);
        for (int i = 0; i < this->dim_; i++) {
            for (int k = 0; k < this->dim_; k++) {
                for (int j = 0; j < this->dim_; j++) {
                    C(i, j) += (*this)(i, k) * B(k, j);
                }
            }
        }
        return C;

    }

    matrix operator+(matrix B) {
        int* c_data;
        c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
        matrix C = matrix(c_data, this->dim_);
        for (int i = 0; i < this->dim_ * this->dim_; i++) {
            c_data[i] = (*this)(i / this->dim_, i % this->dim_) + B(i / this->dim_, i % this->dim_);
        }
        return C;
    }
        void shift_start_pointer(int r_start, int c_start, int new_dim) {
            this->r_start_ += r_start;
            this->c_start_ += c_start;
            this->dim_ = new_dim;
        }

    matrix operator-(matrix B) {
        int* c_data;
        c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
        matrix C = matrix(c_data, this->dim_);
        for (int i = 0; i < this->dim_ * this->dim_; i++) {
            c_data[i] = (*this)(i / this->dim_, i % this->dim_) - B(i / this->dim_, i % this->dim_);
        }
        return C;
    }


private:
    int* data_;
    int dim_;
    int r_start_;
    int c_start_;
    int dim_whole_;
};

int main() {
    int a[4] = { 1, 2, 3, 4 };
    int b[4] = { 5, 6, 7, 8 };
    matrix A = matrix(&a[0], 2);
    matrix B = matrix(&b[0], 2);
    A.print();
    B.print();
    matrix C = A + B;
    C.print();
    matrix D = A - B;
    D.print();
;}