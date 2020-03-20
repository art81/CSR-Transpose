// EECS340Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

struct CRSMatrix
{
    int m; // number of rows
    int n; // number of columns
    int k; // number of non-zero elements
    std::vector<double> V; // non-zero elements
    std::vector<int> C; // column indices
    std::vector<int> R; // row ptr
};


CRSMatrix sparse_transpose(const CRSMatrix& input) {
    CRSMatrix res{
        input.n,
        input.m,
        input.k,
        std::vector<double>(input.k, 0.0),
        std::vector<int>(input.k, 0), 
        std::vector<int>(input.n + 1, 0) 
    };

    for (int r = 0; r <= input.m - 1; r++) {
        for (int j = input.R[r]; j <= input.R[r + 1] - 1; j++) {
            int c = input.C[j];
            res.R[c] = res.R[c] + 1;
        }
    }

    for (int r = 1; r < res.R.size(); r++) {
        res.R[r] += res.R[r - 1]; 
    }
    
    for (int r = input.m-1; r >= 0; r--) {
        for (int j = input.R[r + 1] - 1; j >= input.R[r];j--) {
            int c = input.C[j];
            res.R[c]--;
            res.C[res.R[c]] = r;
            res.V[res.R[c]] = input.V[j];
        }
    }
      
    return res;
}

int main()
{
    CRSMatrix testCRS = {
        3,
        4,
        5,
        std::vector<double> {9,1,1,3,8},
        std::vector<int> {1,3,2,0,1},
        std::vector<int> {0,2,3,5}
    };
    CRSMatrix returner = sparse_transpose(testCRS);


    CRSMatrix testCRS2 = {
        4,
        2,
        4,
        std::vector<double> {5,8,9,9},
        std::vector<int> {0,0,1,0},
        std::vector<int> {0,1,2,3,4}
    };


    CRSMatrix returner2 = sparse_transpose(testCRS2);
    
    std::cout << std::endl;
}
