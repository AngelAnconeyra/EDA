#include<iostream>
#include<fstream>
#include<ctime>
#include<time.h>
#include<vector>
using namespace std;
int const tamanho = 50000;
void Quicksort(vector<int>&,int,int);
int Partition(vector<int>&,int,int);
void imprimir(vector<int>);

int partition(vector<int> &A,int p,int r){
    int x = A[r]; 
    int i = p-1;
    for(int j = p; j < r;j++){
        if(A[j] <= x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(vector<int> &A,int p,int r){
    if(p < r){
        int q = partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
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
	quicksort(A,0,A.size());
	t = clock() - t;
    cout << (float)t/CLOCKS_PER_SEC;

    return 1;
}