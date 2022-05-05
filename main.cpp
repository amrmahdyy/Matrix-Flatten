#include <iostream>
#include<vector>

//  helper function that prints a 1d vector
    void print_vector(const std::vector<int>&arr){
        for(auto elem:arr)
            std::cout<<elem<<" ";
        std::cout<<std::endl;
    }
    void print_3d_matrix(const std::vector<std::vector<std::vector<int>>> & matrix){
        for(auto row:matrix){
            for(auto col:row){
                for(auto elem:col)
                    std::cout<<elem<<" ";
                std::cout<<"   ";
            }
            std::cout<<std::endl;
        }
    }
/**
     * converting 3d vector of type int to 1d vector
     *
     * @param matrix a 3d vector, @param i for row number, @param j for column number, @param k for depth number (Target Element)
     * @return    index of the element
*/
    int getIndex(const std::vector<std::vector<std::vector<int>>> & matrix,int i,int j,int k){
//        finding number of rows
        int rows=matrix.size();
//        finding number of columns
        int cols=matrix[0].size();
//        finding length of depth
        int depth=matrix[0][0].size();
        return i * cols * depth + j * depth + k;
    }

/**
     * converting 3d vector of type int to 1d vector
     *
     * @param matrix specified topology id
     * @return    1d vector of type int
*/
    std::vector<int> flatten(const std::vector<std::vector<std::vector<int>>> matrix) {
//        finding number of rows
        int rows=matrix.size();
//        finding number of columns
        int cols=matrix[0].size();
//        finding length of depth
        int depth=matrix[0][0].size();

//        allocating a vector with the matrix dimensions
    std::vector<int>flattened_1d(rows*cols*depth);

//       Flattening the 3d matrix by iterating over each element using indexes
        for (std::size_t i = 0; i < rows; i++) {
            for (std::size_t j = 0; j < cols; j++) {
                for (std::size_t k = 0; k < depth; k++) {
                    int index=i * cols * depth + j * depth + k;
                    flattened_1d[index]= matrix[i][j][k];
                }
            }
        }
        return flattened_1d;
    }

    int main() {
        // testing the flatten function
        std::vector<std::vector<std::vector<int>>> matrix = {
                {
                        {1, 2},
                        {3, 4},
                        {5,  6}
                },
                {
                        {7, 8},
                        {9, 10},
                        {11, 12}
                }
        };

        std::vector<int>flattened=flatten( matrix);

        std::cout<<"Printing 3d matrix:"<<std::endl;
        print_3d_matrix(matrix);

        std::cout<<"Printing flattened array: "<<std::endl;
        print_vector(flattened);

        std::cout<<std::endl;

        int i=0,j=0,k=0;
        int index=0;

//      Test 1
        std::cout<<"Test 1:"<<std::endl;
         i=1,j=2,k=1;
        std::cout<<"Testing on row: "<<i<<"  column: "<<j<<"  depth: "<<k<<std::endl;
        std::cout<<"Value in 3d matrix: "<<matrix[i][j][k]<<std::endl;
         index= getIndex(matrix,i,j,k);
        std::cout<<"Value in 1d vector: "<<flattened[index]<<std::endl;

//      Test 2
        std::cout<<"Test 2:"<<std::endl;
         i=0,j=2,k=1;
        std::cout<<"Testing on row: "<<i<<"  column: "<<j<<"  depth: "<<k<<std::endl;
        std::cout<<"Value in 3d matrix: "<<matrix[i][j][k]<<std::endl;
         index= getIndex(matrix,i,j,k);
        std::cout<<"Value in 1d vector: "<<flattened[index]<<std::endl;

        return 0;
    }
