#include <vector>
#include <string>
#include <iostream>

class Checker {
private:
    const unsigned int m_size = 60000000;
    const unsigned int hashValues[3] = {29, 31, 37};
    std::vector<bool> m_bits;
    
    unsigned long long int nthHash(std::string key, unsigned int tableSize) {
      unsigned long long int hashVal = 0;

        for(auto c: key){
        hashVal += c - 'a' + 1;

        hashVal *= tableSize;
        }

      return hashVal;
    }
    
public:
    Checker() : m_bits(m_size){}
    void Add(const std::string& s){
        //
        for (int n = 0; n < 3; ++n) {
            m_bits[nthHash(s, hashValues[n]) % m_size] = true;
        }
    }
    bool Exists(const std::string& s){
        
        bool exist = true;
        for (int n = 0; n < 3; ++n) {
            if (m_bits[nthHash(s, hashValues[n]) % m_size] == false) {
                exist = false;
            }
        }

        return exist;
    }
};



