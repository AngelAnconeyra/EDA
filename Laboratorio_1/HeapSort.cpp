#include<iostream>
#include<vector>
#include<fstream>
#include<time.h>
using namespace std;
int const tamanho = 50000;

void heapify(vector<int> &A, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && A[l] > A[largest]){
        largest = l;
    }
 
    if (r < n && A[r] > A[largest]){
        largest = r;
    }
 
    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}
 
void heapSort(vector<int> &A, int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(A, n, i);
    }
 
    for (int i = n - 1; i >= 0; i--){
        swap(A[0], A[i]);
        heapify(A, i, 0);//O(1)
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
	heapSort(A,A.size());
	t = clock() - t;
    //cout<<A.size()<<endl;
    cout << (float)t/CLOCKS_PER_SEC;


    return 1;
}