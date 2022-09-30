#include<iostream>
#include<vector>
#include<fstream>
#include<time.h>
using namespace std;
int const tamanho = 50000;

void bubbleSort(vector<int> &list){
	int aux;
	for(int i = 0; i < list.size() - 1 ; i++){
		for(int j = 0 ; j < list.size()-i-1 ; j++){
			if(list[j] > list[j + 1]){
				swap(list[j],list[j+1]);
			}
		}
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
	bubbleSort(A);
	t = clock() - t;
	//cout<<A.size()<<endl;
    cout << (float)t/CLOCKS_PER_SEC;
	return 1;
}