#include <iostream>
#include <unordered_set>

class TimeOfDay {
public:
    uint8_t hour, minute, second;

    TimeOfDay(uint8_t h, uint8_t m, uint8_t s) : hour(h), minute(m), second(s) {}
    
    bool operator<(const TimeOfDay &rhs) const{
        if ((3600*hour+60*minute+second < 3600*rhs.hour+60*rhs.minute+rhs.second) & IsValid())
            return true;
        else
            return false;
    }
    
    bool operator==(const TimeOfDay &rhs) const{
        if ((hour == rhs.hour) && (minute == rhs.minute) && (second == rhs.second))
        return true;
    else
        return false;
    }
    
    bool IsAM() const {
        return IsValid() && (hour < 12);
    }

    bool IsPM() const {
        return IsValid() && (hour >= 12);
    }

    bool IsValid() const {
        return (hour < 24) && (minute < 60) && (second < 60);
    }
};

namespace std{

template<>
struct hash<TimeOfDay>{
    size_t operator() (const TimeOfDay &obj) const{
        return ((size_t)obj.hour << 16) | ((size_t)obj.minute << 8) | obj.second;
    }
};

}

/*int main(){
    
    std::unordered_set<TimeOfDay> s;
    
    s.insert(TimeOfDay(10,21,13));
    
    //std::cout << s[1] << std::endl;
    
    return 0;
}
*/
