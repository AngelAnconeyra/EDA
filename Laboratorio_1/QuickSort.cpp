#include<iostream>
#include<fstream>
#include<ctime>
#include<time.h>
#include<vector>
using namespace std;
int const tamanho = 10;
void Quicksort(vector<int>&,int,int);
int Partition(vector<int>&,int,int);
void imprimir(vector<int>);

int partition(vector<int> &A,int p,int r){
    int x = A[p]; 
    int i = 0;
    for(int j = p+1; j <= r;j++){
        if(A[j] <= x){
            i++;
        }
    }
    int pivIndex = p + i;
    swap(A[pivIndex],A[p]);
    int prin = p;
    int fin = r;
    while(prin<pivIndex && fin>pivIndex){
        while (A[prin] <= x){
            prin++;
        }
        while(A[fin] > x){
            fin--;
        }
        if(prin<pivIndex && fin >pivIndex){
            swap(A[prin++],A[fin--]);
        }
    }
    return pivIndex;
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
    imprimir(A);
	clock_t t;
    t = clock();
	quicksort(A,0,A.size());
	t = clock() - t;
    cout << (float)t/CLOCKS_PER_SEC;
    cout<<endl;
    imprimir(A);
    return 1;
}