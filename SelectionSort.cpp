#include<iostream>
#include<vector>
#include<fstream>
#include<time.h>
using namespace std;
int const tamanho = 50000;
 
void selectionSort(vector<int>& A, int n){
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            if (A[j] < A[min_idx]){
                min_idx = j;
            }
            if(min_idx!=i){
                swap(A[min_idx],A[i]);
            }
        }
    }
}
 
void imprimir(vector<int> A){
    for(int i = 0;i < A.size();i++){
        cout<< A[i] <<" ";
    }
    cout<<endl;
}
 
int main(){
    vector<int> A;
	ifstream file;
	file.open("numeros.txt");
	int num{},j=0;
	while(j++<tamanho){//Cantidad de numeros
		file>> num;
		A.push_back(num);
	}
	clock_t t;
    t = clock();
	selectionSort(A,A.size());
	t = clock() - t;
    cout << (float)t/CLOCKS_PER_SEC;
    return 1;
}