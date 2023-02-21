/*

Hacer una pila con POO en C++
//platos, llantas de auto, monedas, cuadernos, libros 

Metodos: 
    - agregar  > push  > ok
    - eliminar > pop
    - tope     > top   > ok

    ------------------------
    - funcion tamaño de la pila 
    - impresión de elementos de la pila 
    
Atributos: 
    - Monedas :  int

    stack 

*/

#include<bits/stdc++.h>
using namespace std; 


class myStack{

    private: 

        struct myNode{

            int currency;
            myNode* nextNode;

        };

        myNode* myTop;


    public:

        //constructor ??

        myStack(){
            this->myTop = nullptr;
        }


        //destructor

        ~myStack(){
        }

        // getter

        int myTopGet(){
            return myTop->currency;
        }


        // setter 


        string myPush(int currencyToAdd){

            //creacion del nodo 

            myNode* newNodeCreation = new myNode();
            newNodeCreation->currency = currencyToAdd; 


            //1er caso cuando es el primero a agregar 
            if(myTop == nullptr){
                myTop = newNodeCreation;
            }else{   // 2do caso cuando tengo elementeos en la pila y quiero agregar con complejidad O(1)

                //guardo mi tope
                myNode* auxNode = myTop;

                //muevo mi tope al nuevo tope que agregué
                myTop = newNodeCreation;

                //linkeo  <- | 1 | <-  |  2 | 
                myTop->nextNode = auxNode; 

                //auxNode = nullptr;
                delete(auxNode);

            }

            return "Moneda Apilada";

        }


};


int main(){

    myStack testStack;

    cout << testStack.myPush(1) << "\n";
    string tester = testStack.myPush(30);

    cout << tester <<"\n";

    cout << testStack.myTopGet() <<"\n";

return 0;
}