#include <iostream>
#include <map>
#include <sstream>
#include <cctype>
#include <vector>

enum Token_value {
    NUMBER, END,
    PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
    PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
};

Token_value curr_tok = PRINT;
std::map<std::string,int> table;
int number_value;

int error(){
    std::cout << "ERROR" << std::endl;
    exit(0);
    return 1;
}

bool count(std::vector<char> &expression){
    int left_it = 0;
    int right_it = 0;
    for (int i = 0; i < expression.size(); i++){
        if (expression[i] == '(')
            left_it ++;
        if (expression[i] == ')')
            right_it ++;
    }
    if (left_it == right_it)
        return true;
    
    return false;
}

Token_value get_token(std::vector<char> &expression){
    char ch = 0;
    do{
        if (!std::cin.get(ch))
            return curr_tok = END;
    } while (ch!='\n' && isspace(ch));
 
    switch (ch) {
        case ';':
        case '\n':
             expression.push_back(ch);
             return curr_tok = PRINT;
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
             expression.push_back(ch);
             return curr_tok = Token_value(ch);
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
             std::cin.putback(ch);
             expression.push_back(ch);
             std::cin >> number_value;
             return curr_tok = NUMBER;
        default:
             error ();
    }
}

int expr(bool get, std::vector<char> &expression);

int prim(bool get, std::vector<char> &expression){
    if (get) get_token(expression);
    switch (curr_tok){
        case NUMBER:{
            int v = number_value;
            get_token(expression);
            return v;
        }
        case MINUS:
                return -prim(true, expression);
        case LP:{
            int e = expr(true, expression);
            
            if (curr_tok != RP)
                return error();
            
            get_token(expression);
            return e;
        }

        default:
            return error();
        }
}

int term(bool get, std::vector<char> &expression){
    int left = prim(get, expression);
    for (;;)
        switch (curr_tok){
             case MUL:
                 left *= prim(true, expression);
                 break;
             case DIV:
                 if (int d = prim(true, expression)){
                     left /= d;
                     break;
                 }
                 return error();
     
             default:
                    return left;
            }
}

int expr(bool get, std::vector<char> &expression){
    int left = term(get, expression);
    for (;;)
        switch(curr_tok){
        case PLUS:
            left += term(true, expression);
            break;
        case MINUS:
            left -= term(true, expression);
            break;
        default:
            return left;
        }
}

int main() {
    std::vector<char> expression;
    int answer;
    
    while (std::cin){
        get_token(expression);
        if (curr_tok == END)
            break;
        if (curr_tok == PRINT)
            continue;
        
        answer = expr(false, expression);
        if (count(expression)){
            std::cout << answer << std::endl;
        }
        else{
            error();
        }
        
    }
    
    //for (int i = 0; i < expression.size(); i++)
        //std::cout << expression[i] ;
    
    //std::cout << std::endl;
    
    return 0;
}
