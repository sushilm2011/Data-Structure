#include <iostream>
using namespace std;

template <class Item>
class PQ{
    private:
        Item* pq;
        int size;
    public:
        PQ(int maxN){
            pq = new Item[maxN+1];
            size = 0;
        }

        int empty(){
            return size == 0;
        }

        void insert(Item item){
            pq[++size] = item;
            fixUp(pq, size);
        }

        void getmax(){
            swap(pq[1], pq[size]);
            fixDown(pq, 1, size-1);
            return pq[size--];
        }
};

template <class Item>
void fixUp(Item a[], int pos){
    while(pos>1 && a[pos/2] < a[pos]){
        swap(a[pos/2], a[pos]);
        pos = pos/2;
    }
}

template <class Item>
void fixDown(Item a[], int pos, int N){
    while(pos*2 <= N){
        int j = pos*2;
        if(j<N && a[j]<a[j+1]){
            j++;
        }
        if(!(a[pos]	<	a[j]))	
            break;
		swap(a[pos], a[j]);	
        pos = j;
    }
}