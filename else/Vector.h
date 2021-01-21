template <typename T>
class Vector{

private:
    
    T *data;
    unsigned int size;
    unsigned int isfull;
    
public:
    
    ~Vector(){
        delete[] data;
    }
    Vector(size_t size = 0, T* old_ptr = nullptr);
    explicit Vector(int n);
    size_t length();
    void push_back(T thing);
    T pop_back(T thing);
    T print(T thing);
    int top(T thing);
    Vector<T>& operator+(Vector<T>& V1);
    Vector<T>& operator-(Vector<T>& V1);
    T operator[](int i);
    
};

