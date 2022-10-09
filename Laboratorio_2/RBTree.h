#include "Node.h"
#include<iostream>
#include<fstream>
using namespace std;
string colores[2]={" BLACK "," RED "};
template <class T>
class RBTree{
    private:
        Node<T>*m_pRoot;

        void Add(Node<T>*&pAux,T value,Node<T>*pPadre){
            if(!pAux){
                pAux=new Node<T>(value);
                pAux->m_pSig[2]=pPadre;
                Add_case_1(pAux);
            }
            if(pAux->value==value)return;
            else Add(pAux->m_pSig[pAux->value<value],value,pAux);
            
        }

        Node<T>* find(Node<T>* pAux,T value){
            if(!pAux)return 0;
            if(pAux->value==value)return pAux;
            else return find(pAux->m_pSig[pAux->value<value],value);
        }

        void pintar(Node<T>* nodo,ofstream &archivo){
            if(nodo){
                if(nodo->color == 0){
                    archivo << nodo->value <<"[style=filled,fillcolor=azure4];\n";
                }
                else{
                    archivo << nodo->value <<"[style=filled,fillcolor=firebrick1];\n";
                }
                pintar(nodo->m_pSig[0],archivo);
                pintar(nodo->m_pSig[1],archivo);
            }
        }

        void graficar(Node<T>* nodo, ofstream &archivo){
            if(!nodo) return;
            if(nodo->m_pSig[0]){
                archivo << nodo->value << "--" << nodo->m_pSig[0]->value << ";\n";
            }
            if(nodo->m_pSig[1]){
                archivo << nodo->value << "--" << nodo->m_pSig[1]->value << ";\n";
            }
            graficar(nodo->m_pSig[0], archivo);
            graficar(nodo->m_pSig[1], archivo);
        } 

        void Add_case_1(Node<T>*pAux){
            if(pAux->m_pSig[2]==0)pAux->color=BLACK;
            else Add_case_2(pAux);
        }

        void Add_case_2(Node<T>*pAux){
            if(pAux->m_pSig[2]->color==BLACK)return;
            else Add_case_3(pAux);
        }

        void Add_case_3(Node<T>*pAux){
            Node<T>*pTio=tio(pAux);
            Node<T>*pAbuelo=abuelo(pAux);
            if(pTio && pTio->color==RED){
                pAux->m_pSig[2]->color=BLACK;
                pTio->color=BLACK;
                pAbuelo->color=RED;
                Add_case_1(pAbuelo);
            }
            else Add_case_4(pAux);
        }

        void Add_case_4(Node<T>*pAux){
            Node<T>*pAbuelo=abuelo(pAux);
            if((pAux==pAux->m_pSig[2]->m_pSig[1]) && (pAux->m_pSig[2]==pAbuelo->m_pSig[0])){
                rotar_izq(pAux->m_pSig[2]);
                pAux=pAux->m_pSig[0];
                //rotar_dcha(pAux->m_pSig[2]->m_pSig[2]);
                //return;
            }
            else if((pAux==pAux->m_pSig[2]->m_pSig[0]) &&(pAux->m_pSig[2]==pAbuelo->m_pSig[1])){
                rotar_dcha(pAux->m_pSig[2]);
                pAux=pAux->m_pSig[1];
                //rotar_izq(pAux->m_pSig[2]->m_pSig[2]);
                //return;
            }
            Add_case_5(pAux);
        }

        void Add_case_5(Node<T>*pAux){
            Node<T>*pAbuelo=abuelo(pAux);
            pAbuelo->color=RED;
            pAux->m_pSig[2]->color=BLACK;
            //pAux->color=RED;
            if ( (pAux==pAux->m_pSig[2]->m_pSig[0]) && (pAbuelo->m_pSig[0]==pAux->m_pSig[2]) ){
                rotar_dcha(pAbuelo);
            }
            else{
                rotar_izq(pAbuelo);
            }
        }

        void rotar_izq(Node<T>*p){
            Node<T>**aux=&(this->m_pRoot);
            if(p->m_pSig[2] && p->m_pSig[2]->m_pSig[1]==p) aux=&(p->m_pSig[2]->m_pSig[1]);
            else if(p->m_pSig[2] && p->m_pSig[2]->m_pSig[0]==p)aux=&(p->m_pSig[2]->m_pSig[0]);

            *aux=p->m_pSig[1];
            (*aux)->m_pSig[2]=p->m_pSig[2];
            p->m_pSig[2]=*aux;
            p->m_pSig[1]=(*aux)->m_pSig[0];
            (*aux)->m_pSig[0]=p;
            if(p->m_pSig[1])p->m_pSig[1]->m_pSig[2]=p;
        }

        void rotar_dcha(Node<T>*p){
            Node<T>**aux=&(this->m_pRoot);
            if(p->m_pSig[2] && p->m_pSig[2]->m_pSig[1]==p) aux=&(p->m_pSig[2]->m_pSig[1]);
            else if(p->m_pSig[2] && p->m_pSig[2]->m_pSig[0]==p) aux=&(p->m_pSig[2]->m_pSig[0]);

            *aux=p->m_pSig[0];
            (*aux)->m_pSig[2]=p->m_pSig[2];
            p->m_pSig[2]=*aux;
            p->m_pSig[0]=(*aux)->m_pSig[1];
            (*aux)->m_pSig[1]=p;

            if(p->m_pSig[0]) p->m_pSig[0]->m_pSig[2]=p;
            
        }

        void RDI(Node<T>*&p){
            Node<T>*q=p->m_pSig[1];
            Node<T>*r=q->m_pSig[0];
            p->m_pSig[1]=r->m_pSig[0];
            q->m_pSig[0]=r->m_pSig[1];
            r->m_pSig[0]=p;
            r->m_pSig[1]=q;
            r->m_pSig[2]=p->m_pSig[2];
            p->m_pSig[2]=r;
            q->m_pSig[2]=r;
            r->color=BLACK;
            p->color=RED;
            q->color=RED;
            p=r;
        }

        void RID(Node<T>*&p){
            
            Node<T>*q=p->m_pSig[0];
            Node<T>*r=q->m_pSig[1];
            
            q->m_pSig[1]=r->m_pSig[0];
            p->m_pSig[0]=r->m_pSig[1];
            r->m_pSig[1]=p;
            r->m_pSig[0]=q;
            r->m_pSig[2]=p->m_pSig[2];
            p->m_pSig[2]=r;
            q->m_pSig[2]=r;
            r->color=BLACK;
            q->color=RED;
            p->color=RED;

            p=r;
        }

        void RII(Node<T>*&p){
            Node<T>*q=p->m_pSig[0];
            p->m_pSig[0]=q->m_pSig[1];
            q->m_pSig[1]=p;

            if(!p->m_pSig[0])q->FE=p->FE=0;
            else{
                q->FE=0;
                p->FE=0;
            }
            p=q;
        }

        void RDD(Node<T>*&p){
            Node<T>*q=p->m_pSig[1];
            p->m_pSig[1]=q->m_pSig[0];
            q->m_pSig[0]=p;

            if(!p->m_pSig[1])q->FE=p->FE=0;
            else{
                p->FE=0;
                q->FE=0;
            }
            p=q;
        }

    public:
        Node<T>* hermano(Node<T>* pAux){
            if(pAux && pAux->m_pSig[2])return pAux->m_pSig[2]->m_pSig[pAux->m_pSig[2]->value>pAux->value];
        }
        
        T hermano(T value){
            return hermano(find(value))->value;
        }
        Node<T>* find(T value){
            return find(this->m_pRoot,value);
        }
        Node<T>* tio(Node<T>* pAux){
            Node<T>*pAbuelo=abuelo(pAux);
            if(pAux->m_pSig[2]==pAbuelo->m_pSig[0]) return pAbuelo->m_pSig[1];
            else return pAbuelo->m_pSig[0];
        }
        T tio(T value){
            return tio(find(value))->value;
        }
        void Add(T value){
            Add(this->m_pRoot,value,0);
        }
        
        void graficar(){
            if(!this->m_pRoot) return;
            ofstream archivo;
            archivo.open("grafo.dot");
            archivo << "graph A{\n";
            pintar(this->m_pRoot,archivo);
            graficar(this->m_pRoot,archivo);
            archivo << "\n}";
            archivo.close();
            system("dot grafo.dot -o grafo.png -Tpng");
            //system("grafo.png");
        }
        Node<T>*abuelo(Node<T>*pAux){
            if(pAux && pAux->m_pSig[2])return pAux->m_pSig[2]->m_pSig[2];
            else return 0;
        }
        T abuelo(T value){
            return abuelo(find(value))->value;
        }
       
    public:
        RBTree(){
            this->m_pRoot=0;
        }
        
};