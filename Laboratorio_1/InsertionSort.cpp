#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
using namespace std;
int const tamanho = 50000;

void insertionSort(vector<int> &list){
    for (int j = 1; j < list.size(); j++) {
        int key = list[j]; //Guarda el elemento de la izquierda
        int i    = j - 1; //Numero del elemento menos 1
        while (i >= 0 && list[i] > key) {
            list[i + 1] = list[i]; //Intercambiar de posiciones de la derecha entre la posicion izquierda
            i--;
        }
        list[i + 1] = key;
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
	insertionSort(A);
	t = clock() - t;
    cout << (float)t/CLOCKS_PER_SEC;

    return 1;
}

