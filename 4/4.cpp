#include <string>
class IOWrapper{
    handle_t handle;
    
public:
    /*CopyConstructible
    CopyAssignable
    Destructible*/
    IOWrapper() = delete;
    IOWrapper(const IOWrapper&) = delete;
    IOWrapper(handle_t handle){
        this->handle = handle;
    }
    IOWrapper(IOWrapper&& rls){
        handle = rls.handle;
    }
    IOWrapper& operator=(const IOWrapper&) = delete;
    IOWrapper& operator&() = delete;
    //IOWrapper(const IOWrapper&) = delete;
    void operator=(IOWrapper&& rhs){
        handle = rhs.handle;
        rhs.handle = kNullHandle;
    }
    //IOWrapper(int64_t numerator, uint64_t denominator);
    void Write(const std::string& content){
        raw_write(handle, content);
    }
    /*void raw_write(handle_t handle, const std::string& content);
    void raw_close(handle_t handle);*/
    ~IOWrapper(){
        if (handle != kNullHandle)
            raw_close(handle);
    }
};
