#include <iostream>
#include "RBTree.h"
using namespace std;

int main(){
    RBTree<int>test;
    for(int i=1;i<=13;i++)test.Add(i);
    test.graficar();
    return 0;
}
