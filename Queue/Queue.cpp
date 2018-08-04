template<class Item>
class Queue{
    private:
        struct node{
            Item item;
            node *next;
            node(Item item){
                this->item = item;
                next = NULL;
            }
        };
        typedef node* link;
        link head, tail;
        int _size;
    public:
        Queue(){
            head = NULL;
            _size = 0;
        }
        bool isEmpty(){
            return (head == NULL);
        }
        void put(Item iten){
            link t = tail;
            tail = new node(item);
            if(head == NULL){
                head = tail;
            }else{
                t->next = tail;
            }
            _size++;
        }
        Item get(){
            Item toget = head->item;
            link t = head->next;
            delete head;
            head = t;
            _size--;
            return toget;
        }
        int size(){
            return _size;
        }
};