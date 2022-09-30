#include<iostream>
#include<fstream>
#include<time.h>

using namespace std;

int main(){
    int num,cantidad = 1000;
    int limit= 50000;
    ofstream file("numeros.txt");
    if(!file){
        cout<<"Error al abrir file\n";
    }
    else{
        for(int i=0;i<limit;i++){
            num = 1 + rand()% (cantidad);
            file << num << " ";
        }
    }
    file.close();
    return 1;
}