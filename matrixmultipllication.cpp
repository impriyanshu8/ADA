#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> multiplyMatrix( const vector<vector<int>> &matrixA ,
     const vector<vector<int>> &matrixB){
        int rowsA = matrixA.size();
        int colsA = matrixA[0].size();
        int rowsB = matrixB.size();
        int colsB = matrixB [0].size();
        vector<vector<int>>result(rowsA , vector<int>(colsB,0)) ;

        for(int i=0;i<rowsA;i++){
            for(int j=0;j<colsB;j++){
                result[i][j] = 0;
                    for(int k=0;k<colsA;k++){
                        result[i][j]+=( matrixA[i][k] )*(matrixB[k][j]);
                    }
            }
        }
                        return result ;
}
void display(vector<vector<int>> &result){
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> matrixA {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> matrixB {
        {3,2,6},
        {6,7,3},
        {1,5,8}
    };
    // check if matrix multiplication is possible
    if(matrixA[0].size() != matrixB.size()){
        cerr<<"Error : Matrix multiplication incompatible with the given dimensions" ;
        return 1;
        
    }
    vector<vector<int>> result = multiplyMatrix( matrixA , matrixB);
    display(result);


}