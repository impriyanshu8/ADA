#include<iostream>
#include<vector>
#include<stack>
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
void quicksort(vector<int>& numbers , int l , int r){
    stack<pair<int , int >> stack;
    stack.push(make_pair(l, r));
    while(!stack.empty()){
        int start = stack.top().first;
        int end = stack.top().second;
        stack.pop();
        if(start>=end)continue;
        int pivot = partition(numbers , start , end);
        stack.push(make_pair(start,pivot-1)) ;
        stack.push(make_pair(pivot+1,end));

    }
    
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