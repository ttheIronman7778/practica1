#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE;
	void resize(int new_size);
    public:
        // miembros públicos, incluidos los heredados de List<T>
    	ListArray();
	~ListArray();
	T operator[](int pos);
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
	void insert(int pos, T e) override;
            void append(T e) override;
            void prepend(T e) override;
            T remove(int pos) override;
            T get(int pos) override;
            int search(T e) override;
            bool empty() override;
            int size() override;

};