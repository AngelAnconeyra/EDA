#include<iostream>
#include<vector>
#include<limits>
#include<time.h>
#include<fstream>
using namespace std;
int const tamanho = 50000;
void merge(vector<int> &A, int p, int q, int r){
    int n1 = q - p +1;
    int n2 = r - q;
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    for(int i = 0 ; i < n1 ; i++){
        L[i] = A[p + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = A[q + j +1];
    }
    L[n1] = INT32_MAX;
    R[n2]= INT32_MAX;
    int i = 0;
    int j = 0;
    for(int k = p ; k < r + 1; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &A, int p, int r){
    if(p < r){
        int q = (p+r)/2; 
        mergeSort(A,p,q); 
        mergeSort(A,q + 1,r); 
        merge(A,p,q,r); 
    }
}

void imprimir(vector<int> A, int n){
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << "\n";
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
	mergeSort(A,0,A.size());
	t = clock() - t;
    cout << (float)t/CLOCKS_PER_SEC;
    
    return 1;
}