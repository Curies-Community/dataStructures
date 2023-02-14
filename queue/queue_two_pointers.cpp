// Implementación de una queue de enteros con apuntadores
/* 
    Métodos 
    -> Push
    -> Pop
    -> Size
    -> Front
    -> Back (tarea)
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int element;
    node* nextElement;

    node(int element){
        this->element = element; // Valor
        nextElement = NULL; // Dirección del siguiente elemento
    }
};

struct Queue {
    node* back_pointer;
    node* front_pointer;
    int size_var;

    // Constructor
    Queue(){
        // Inicialización de punteros
        back_pointer = NULL; // -> Puntero del final de la queue
        front_pointer = NULL; // -> Puntero al inicio de la queue
        size_var = 0; // -> Tamaño de la queue
    }

    // Método: Size -> Regresa el tamaño de la queue
    int size(){
        return size_var;
    }

    // Método: Pop -> Elimina el elemento del front
    void pop(){
        if(size_var == 0){
            cout << "Queue is empty!" << endl;
        }else{
            // Saber cuál es mi nuevo front
            node* temp = front_pointer->nextElement;
            // Eliminar front anterior
            delete front_pointer;
            // Asignar mi nuevo valor
            front_pointer = temp;

            // Cuando tengo un sólo elemento mi front y mi back -> NULL
            if(size_var == 1){
                // El fin de la queue
                back_pointer = NULL;
            }

            size_var--;
        }
    }

    // Método: Push -> Inserta un elemento al back
    void push(int element){
        // Crear un nuevo nodo
        node* newNode = new node(element);
        // Almacenar mi valor anterior (back anterior)
        node* temp = back_pointer;
        // Cambiar el valor del back
        back_pointer = newNode;

        // Explicación del código anterior
        // -> 1     - 2     3 
        // front_p  back_p  newNode

        // -> 1     - 2     2 
        // front_p  temp    back_pointer   

        // -> 1     - 2   -  3 
        // front_p  temp    back_pointer 

        // Queue empty
        
        // 0 elementos
        // NULL     NULL    3
        // front_p  back_p  newNode

        // Validar que le queue no esté vacía
        if(size_var == 0){
            front_pointer = newNode;
        }else{
            temp->nextElement = back_pointer;
        }

        size_var++;
    }

    // Método: Front -> Regresa el elemento que se encuentra en el front
    int front(){
        // Si la queue está vacía
        if(size_var == 0){
            cout << "Queue is empty!" << endl;
            return 0;
        }else{
            return front_pointer->element;
        }
    }
};


int main(){

    Queue q;
    bool cicle = true;

    while(cicle){
        int opt = 0;
        cout << endl << "Select one option: " << endl;
        cout << "1) Size" << endl;   
        cout << "2) Front" << endl;   
        cout << "3) Pop" << endl;   
        cout << "4) Push" << endl;   
        cout << "5) Exit" << endl;   
        cout << endl << "Option: "; 

        cin >> opt;

        switch (opt)
        {
        case 1:{
            cout << "The size of your queue is: " << q.size() << endl; 
            break;
        }

        case 2:{
            cout << "Front element is: " << q.front() << endl;
            break;
        }
        
        case 3:{
            q.pop();
            cout << "Front element deleted, the current size of your queue is: " << q.size() << endl;
            break;
        }
        
        case 4:{
            cout << "Value to push: "; 
            int value = 0;
            cin >> value;

            q.push(value);

            cout << "Element pushed, the current size of your queue is: " << q.size() << endl;
            break;
        } 

        case 5:{
            cicle = false;
            break;
        }   

        }
    }
    
    return 0;
}

/* | Valor - Puntero | */ 
/* | Element - nextElement | */ 

