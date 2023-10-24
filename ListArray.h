#include <ostream>
#include "List.h"
#include <iostream>

using namespace std;

template <typename T>
class ListArray : public List<T> {

    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE=2;
        void resize(int new_size){
            T* aux = new int[new_size];
            for(int i=0; i < size(); i++){
                aux[i] = arr[i];
            } 
            delete[] arr;
            arr = aux;
            max = new_size;
        }

    public:
        ListArray(){
            max = 0;
            arr = new int[0];
            n = 0;
        }

        ~ListArray(){
            delete arr;
        } 

        T operator[](int pos){
     	    if (pos<0||pos>size()-1){
                throw std::out_of_range("Posición inválida");
            }
            return arr[pos];
        }            
        
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
            out << "List => [";
            if(0<list.max){
                out << endl;
                }

            for(int i=0;i<list.max;i++){
                out << "  " << list.arr[i] << endl;
            }
            out << "]";
            return out;
        }

	    void insert(int pos, T e) override{
            if (pos<0||pos>size())
                throw std::out_of_range("Posición inválida");
            n++;
            resize(n);

            if(pos<n){
                for(int i=0;i<n-pos;i++){
                    arr[n-i]=arr[n-1-i];
                }
            }

            arr[pos]=e;
        }

	    void append(T e) override{
            n++;
            resize(n);
            arr[size()-1] = e;
        }

	    void prepend(T e) override{
            n++;
            resize(n);
            for(int i=0;i<size();i++){
                arr[size()-1-i]=arr[size()-2-i];
            }
            arr[0]=e;
        }

        T remove(int pos) override{
    	    if (pos<0||pos>size()-1){
                throw std::out_of_range("Posición inválida");
            }
            int aux = arr[pos];
            if(pos < n){
                for(int i=pos;i<n;i++){
                    arr[i]=arr[i+1];
                }
            }
            n--;   
            resize(n);
            return aux;
        }

        T get(int pos) override{
    	    if (pos<0||pos>size()-1){
                throw std::out_of_range("Posición inválida");
            }
            return arr[pos];
        }
        
        int search(T e) override{
    	    int pos;
            for(pos=0;pos<size();pos++){
                if(arr[pos]==e){
                    return pos;
                }
            }

            return -1;
        } 

        bool empty() override{
            if(n > 0){
                return false;
            }
            else {
                return true;
            }
        }

        int size() override{
            return n;
        }
};


