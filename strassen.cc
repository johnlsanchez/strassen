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

    matrix mul(matrix B) {
        int* c_data;
        c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
        for (int i = 0; i < this->dim_; i++) {
            for (int j = 0; j < this->dim_; j++) {
                int sum = 0;
                for (int k = 0; k < this->dim_; k++) {
                    sum += (*this)(j, k) * B(k, i);
                }
                c_data[j * this->dim_ + i] = sum;
            }
        }
        return matrix(c_data, this->dim_);

    }

    matrix operator+(matrix B) {
        int* c_data;
        c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
        for (int i = 0; i < this->dim_ * this->dim_; i++) {
            c_data[i] = (*this)(i / this->dim_, i % this->dim_) + B(i / this->dim_, i % this->dim_);
        }
        return matrix(c_data, this->dim_);

    }

    matrix operator-(matrix B) {
        int* c_data;
        c_data = (int*)malloc(sizeof(int) * this->dim_ * this->dim_);
        for (int i = 0; i < this->dim_ * this->dim_; i++) {
            c_data[i] = (*this)(i / this->dim_, i % this->dim_) - B(i / this->dim_, i % this->dim_);
        }
        return matrix(c_data, this->dim_);
    }


private:
    int* data_;
    int dim_;
};

int main() {
    int a[4] = { 1, 2, 3, 4 };
    int b[4] = { 5, 6, 7, 8 };
    matrix A = matrix(&a[0], 2);
    matrix B = matrix(&b[0], 2);
    A.print();
    B.print();
    matrix C = A - B;
    C.print();
;}