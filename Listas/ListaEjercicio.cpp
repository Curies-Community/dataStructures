/*

Implementando listas en C++
Tipo de lista: simplemente ligada (: 

doblemente ligada 
circulares 

| nodo_1 |  ->   | nodo_2 |  ->   | nodo_3 |

Crear un lista simplemente ligada de mis mejores amigos...

    agregar
    imprimir (recorrido de lista)
    eliminar 
    agregar funcion tamaño 


Tipo de dato nodoMisAmigos
    - nombre        > string
    - edad          > int
    - peso          > double
    - tieneFerrari  > bool 


| nodo_1 | -> | nodo_2 | ->
*/


#include<bits/stdc++.h>
using namespace std; 

//Tipo de dato  > nodo > personalizable 


struct nodoMisAmigos{

    string      nombre; 
    int         edad;
    double      peso;
    bool        ferrari;

    nodoMisAmigos* siguienteAmigo;
};

//root 
nodoMisAmigos* iniciaListaAmigos = nullptr;

/*
class lista{

    private:
        //tipo de dato 

    public: 
        //agregar
        // borrar
        // ...


};






    V
| nodo_1 | -> | nodo_2|  -> |nodo_3|  -> |nodo_4| ->


//1er caso 
//Borramos el del frente nodo_1 
    
    //aux al root 
    V
| nodo_1 | -> | nodo_2|  -> |nodo_3|  -> |nodo_4| ->

    aux = root;

    //  mi root tiene que ser igual al siguiente
        root = aux->siguienteAmigo;
   aux                 V
| nodo_1 | ->    | nodo_2|  -> |nodo_3|  -> |nodo_4| ->

    // borro nodo_1 
        delete(aux);

    V
| nodo_2|  -> |nodo_3|  -> |nodo_4| ->

--------------------------------------------------------------------------

//2do caso
//Borramos el ultimo nodo_4

    V
| nodo_2|  -> |nodo_3|  -> |nodo_4| -> null
                              it

    //2.1 Como me doy cuenta que es el último ? 
        // 1. con un contador y funcion tamaño
        // 2. cuando nodoMiAmigo nodo->sigAmigo == nullptr

    //Recorrer 
   V
| nodo_2|  -> |nodo_3|  -> |nodo_4| -> null
                 prev          it


    // previo al final apuntaria a nullptr 
        delete(it);
        prev->sigAmigo = nullptr;

    //pregunto si pasa 2.1


    V
| nodo_2|  -> |nodo_3|  -> null

------------------------------------------------------------------------------

//3er caso borrar de enmedio 


    V
| nodo_2|  -> |nodo_3| -> |nodo_4| -> null
    prev     
    it

                                V
    //1. | nodo_basura |  -> | nodo_2|  -> |nodo_3| -> |nodo_4| -> null
                                prev           it

            // Checar que el primer elemento no sea el que borremos y entonces asignar                 
    //2. | nodo_2|  -> |nodo_3| -> |nodo_4| -> null
            prev            it te llamas pedro? Si 



//Recorrer
         v
 //2. | nodo_2|  -> |nodo_3| -> |nodo_4| -> null
        prev           it 

        prev->sigAmigo = it->sigAmigo;

// borro 
        delete(it); 


    V
| nodo_2|  ->  |nodo_4| -> null
*/

void borrarAmigo (string nombrePorBorrar){

    nodoMisAmigos* iterador = iniciaListaAmigos;


    if(iterador->nombre == nombrePorBorrar){

        nodoMisAmigos* aux = iterador;
        iniciaListaAmigos = iniciaListaAmigos->siguienteAmigo;

        delete(aux);


    }else{

        nodoMisAmigos* prev = iniciaListaAmigos;
        iterador = iniciaListaAmigos->siguienteAmigo;

        for( ; iterador != nullptr ; iterador = iterador->siguienteAmigo){
            if(iterador->nombre == nombrePorBorrar){
                prev->siguienteAmigo = iterador->siguienteAmigo;  
                break;                                                                                 
            }
        }

        delete(iterador);
    }

return;
}


int main(){

    agregarAmigo();
    cout<< tamanoListaAmigos();
    imprimirListaAmigos();

    borrarAmigo("Juan");

    imprimirListaAmigos();

return 0;
}