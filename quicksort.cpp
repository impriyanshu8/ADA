#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&numbers,int l, int r){
    int pivot = numbers[l];
    int i = l+1;
    int j = r;
    while(i<=j){
        while(i<=j && numbers[i]<= pivot){
            i++ ;
        }
        while(i<=j && numbers[j]>= pivot){
            j--;
        }
        if(i<j){
            swap(numbers[i],numbers[j]);
        }  
    }
    swap (numbers[l],numbers[j]);
        return j;
}
void quicksort(vector<int>&numbers , int l , int r){
    if (l >= r) { 
        return;
    }
    int pivot = partition(numbers ,l,r);
    quicksort(numbers,l,pivot-1);
    quicksort(numbers,pivot+1,r);

}
int main(){
    vector<int> numbers ={
        1,23,45,21,26,87,97};
        int n = numbers.size() - 1;
        quicksort(numbers , 0 , n);
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
        return 0;
      

}

  