/*class MinStack { //люблю решать задачи
private:
    struct linklst{
        int num;
        linklst* next;
    };

    linklst* t;
public:
    MinStack(){
        t = new linklst();
        t->num = -1;
        t->next = nullptr;
    }
    
    ~MinStack() {
            linklst * r = new linklst();
            while (true){
                r = t;
                t = t->next;
                delete r;
            }
            delete t;
    }
    
    int size(){
        int k = 0;
        while (true){
            t = t->next;
            k++;
        }
        return k;
    };
    
    bool isempty(){
        return (t->next == nullptr);
    };
    
    void push(int x){
                    linklst * r = new linklst();
                    r->num = x;
                    r->next = t;
                    t = r;
    };
    
    int pop(){
                    if (not isempty()){
                        linklst * r = t;
                        t = t->next;
                        int x = r->num;
                        delete r;
                        return x;
                    }
    };
    
    int getMin(){
        int floor = t->num;
        for (int i = 1; i < size(); ++i){
            if (t->next->num < floor)
                floor = t->next->num;
            t = t->next;
        }
        return floor;
    }
    
    int print(){
        for (int i = size() - 1; i >= 0; --i){
            t = t->next;
            std::cout << t->num << ' ';
        }
        std::cout << " ";
    }
    
    int top(){
        for (int i = 0; i < size() - 1; i++)
            t = t->next;
        return t->next->num;
    }
    
};*/

class MinStack
{
    private:
        int* stack;
        int size;
        int isfull;

    public:
        MinStack(){
            stack = new int[1];
            size = 1;
            isfull = 0;
        }
    
        ~MinStack(){
            delete[] stack;
        }
    
        void push(int x){
               if (isfull == size){
                   size ++;
                   int* tmp = new int[size];
                   for (int i = 0; i < isfull; ++i)
                       tmp[i] = stack[i];
                   delete[] stack;
                   stack = tmp;
               }
               stack[isfull] = x;
               isfull++;
           }
    
        void pop(){
               isfull--;
           }
    
        void print(){
            for (int i = isfull - 1; i >= 0; --i)
                std::cout << stack[i] << ' ';
        }
       
        int top(){
            return stack[isfull - 1];
        }
    
        int getMin(){
            int floor = stack[0];
            for (int i = 1; i < isfull; ++i)
                if (stack[i] < floor)
                    floor = stack[i];
            return floor;
        }
};
