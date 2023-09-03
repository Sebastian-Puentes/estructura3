#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class NodoDoble {
public:
    int dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    NodoDoble(int dato) {
        this->dato = dato;
        this->siguiente = nullptr;
        this->anterior = nullptr;
    }
};

void insertarLista(NodoDoble*&, int);
void buscarLista(NodoDoble*, int);
void mostrarLista(NodoDoble*);
void eliminarNodo(NodoDoble*&, int);
void actualizarNodo(NodoDoble*, int, int);

int main() {
    NodoDoble* lista = nullptr;
    char opcion;

    do {
        std::cout << "MENU:" << std::endl;
        std::cout << "1. Insertar un numero" << std::endl;
        std::cout << "2. Buscar un numero" << std::endl;
        std::cout << "3. Mostrar la lista de numeros" << std::endl;
        std::cout << "4. Eliminar un nodo de la lista" << std::endl;
        std::cout << "5. Modificar/ actualizar un nodo" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case '1': {
                int dato;
                std::cout << "Digite un numero: ";
                std::cin >> dato;
                std::cout << "\n";
                insertarLista(lista, dato);
                break;
            }
            case '2': {
                int dato;
                std::cout << "Digite el numero a buscar: ";
                std::cin >> dato;
                std::cout << "\n";
                buscarLista(lista, dato);
                break;
            }
            case '3': {
                mostrarLista(lista);
                std::cout << "\n";
                break;
            }
            case '4': {
                int dato;
                std::cout << "Ingrese el valor que quiere borrar: ";
                std::cin >> dato;
                eliminarNodo(lista, dato);
                std::cout << "\n";
                break;
            }
            case '5': {
                int dato, nuevoDato;
                std::cout << "Digite el numero a actualizar: ";
                std::cin >> dato;
                std::cout << "Digite el nuevo numero: ";
                std::cin >> nuevoDato;
                std::cout << "\n";
                actualizarNodo(lista, dato, nuevoDato);
                break;
            }
            case '6':
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Por favor, seleccione una opcion valida." << std::endl;
        }
    } while (opcion != '6');
    while (lista != nullptr) {
        NodoDoble* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }

    return 0;
}

void insertarLista(NodoDoble*& lista, int n) {
    NodoDoble* nuevoNodo = new NodoDoble(n);

    if (lista == nullptr) {
        lista = nuevoNodo;
    } else {
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        lista = nuevoNodo;
    }

    std::cout << "Elemento " << n << " insertado en la lista correctamente" << std::endl;
}

void buscarLista(NodoDoble* lista, int n) {
    bool encontrado = false;
    NodoDoble* actual = lista;

    while (actual != nullptr) {
        if (actual->dato == n) {
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (encontrado) {
        std::cout << "Elemento " << n << " ha sido encontrado en la lista" << std::endl;
    } else {
        std::cout << "Elemento " << n << " no ha sido encontrado en la lista" << std::endl;
    }
}

void mostrarLista(NodoDoble* lista) {
    NodoDoble* actual = lista;

    while (actual != nullptr) {
        std::cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    }

    std::cout << "nullptr" << std::endl;
}

void eliminarNodo(NodoDoble*& lista, int n) {
    NodoDoble* actual = lista;

    while (actual != nullptr) {
        if (actual->dato == n) {
            if (actual->anterior != nullptr) {
                actual->anterior->siguiente = actual->siguiente;
            } else {
                lista = actual->siguiente;
                if (lista != nullptr) {
                    lista->anterior = nullptr;
                }
            }

            if (actual->siguiente != nullptr) {
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;
            std::cout << "Elemento " << n << " eliminado correctamente" << std::endl;
            return;
        }

        actual = actual->siguiente;
    }

    std::cout << "Elemento " << n << " no ha sido encontrado en la lista" << std::endl;
}

void actualizarNodo(NodoDoble* lista, int n, int nuevoDato) {
    NodoDoble* actual = lista;

    while (actual != nullptr) {
        if (actual->dato == n) {
            actual->dato = nuevoDato;
            std::cout << "Elemento " << n << " actualizado a " << nuevoDato << " correctamente" << std::endl;
            return;
        }

        actual = actual->siguiente;
    }

    std::cout << "Elemento " << n << " no ha sido encontrado en la lista" << std::endl;
}
