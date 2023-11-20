#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
    
        Node<T>* first; // Puntero que apunta al primer nodo de la secuencia enlazada
        int n;      // Cantidad de elementos que contiene la lista.

    public:
    
        ListLinked(){   // Método constructor simple.
            this-> first = nullptr;
            this-> n = 0;
        }
    
        ~ListLinked(){  // Método destructor.
        
            Node<T>* aux = first->next; 
            while (aux != nullptr){
                delete first;           
                first->next = aux->next;
                aux = first->next;      
            }        
        }
    
        T operator[](int pos){  // Devuelve el elemento que está ubicado en la posición pos.
            if (pos < 0 || pos > size()-1)
                 throw std::out_of_range("Posición inválida");
                    
            Node<T>* aux = first;
            int i=0;
            while (aux != nullptr && i!=pos){
                i++;
                aux = aux->next;
            }
            
            return aux->data;
        }
        
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){  // Sobecarga global del operador <<.
            out << "List => [";

            if(0 < list.n){
                out << endl;

                Node<T>* aux = list.first;
                while (aux != nullptr){
                    out << "  " << aux->data << endl;
                    aux = aux->next;
                }
            }

            out << "]";

            return out;
        }

	    void insert(int pos, T e) override{     // Inserta el elemento e en la posición indicada por pos.
            if (pos < 0 || pos > size())
                throw std::out_of_range("Posición inválida");

            n++;
            
            if(pos==0){
                first = new Node(e, first);
            } else {
                Node<T>* prev = nullptr;
                Node<T>* aux = first;

                int i = 0;
                while (aux != nullptr && i < pos){
                    prev = aux;
                    aux = aux->next;
                    i++;
                }
                prev->next = new Node(e, aux);               
            } 
        }

	    void append(T e) override{ // Añade el elemento e al final de la lista
            n++;
            Node<T>* prev = nullptr;
            Node<T>* aux = first;
            int i = 0;
            while (aux != nullptr && i < size()){ 
                prev = aux;
                aux = aux->next;
                i++;
            }
            prev->next = new Node(e, aux);
    	    }

	    void prepend(T e) override{  //Como el append pero al inicio de la lista.
            n++;
            
            first = new Node(e, first);       
        }

        T remove(int pos) override{  // Elimina el elemento ubicado en la posición pos.
    	    if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            n--;
            
            Node<T>* prev = nullptr;
            Node<T>*aux = first;
            int i=0;

            while (aux != nullptr && i != pos){
                prev = aux;
                aux = aux->next;
                i++;
            }

            int num = aux->data;

            if (aux != nullptr) {
    		    if (aux == first) {
                    first = aux->next;
                } else { 
                    prev->next = aux->next;
                }
            
                delete aux; 
            }

            return num;
        }

        T get(int pos) override{     // Devuelve el elemento ubicado en la posición pos.
    	    if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            Node<T>* aux = first;
            int i=0;
            while (aux != nullptr && i!=pos){
                i++;
                aux = aux->next;
            }
            
            return aux->data;
        }
        
        int search(T e) override{     // Devuelve la posición en la que se encuentra por primera vez elemento e, o si no se encuentra devuelve -1.
    	    Node<T>* aux = first;
            int i = 0;
            while (aux != nullptr && aux->data != e){
                aux = aux->next;
                i++;
            }
            
            if (aux != nullptr) { 
                return i;
            } else { 
                return -1;
            }
        } 

        bool empty() override{      // Indica si la lista está vacía.
            if(n > 0){
                return false;
            } else {
                return true;
            } 
        } 

        int size() override{         // Devuelve el número de elementos de la lista.
            return n;
        }


};
