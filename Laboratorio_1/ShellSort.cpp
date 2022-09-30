#include<iostream>
#include<vector>
#include<fstream>
#include<time.h>
using namespace std;
int const tamanho = 50000;
  
void shellSort(vector<int>&A, int n){
    for(int gap = n/2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int temp = A[i];
            int j;
            for(j = i; j >= gap && A[j - gap] > temp; j -= gap){
                A[j] = A[j - gap];
            }
            A[j] = temp;
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
	shellSort(A,A.size());
	t = clock() - t;
    cout << (float)t/CLOCKS_PER_SEC;
    file.close();
    return 1;
}