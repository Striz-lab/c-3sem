#include <iostream>

 
class Students {
    // Имя студента
    std::string name;
    // Фамилия
    std::string last_name;
    // Пять промежуточных оценок студента
    int scores[5];
    // Итоговая оценка за семестр
    float average_ball;
    
    public:
        // Установка имени студента
        void set_name(std::string student_name)
        {
            name = student_name;
        }
        // Получение имени студента
        std::string get_name()
        {
            return name;
        }
        // Установка фамилии студента
        void set_last_name(std::string student_last_name)
        {
            last_name = student_last_name;
        }
        // Получение фамилии студента
        std::string get_last_name()
        {
            return last_name;
        }
        // Установка промежуточных оценок
        void set_scores(int student_scores[])
        {
            for (int i = 0; i < 5; ++i) {
                scores[i] = student_scores[i];
            }
        }
        // Установка среднего балла
        void set_average_ball(float ball)
        {
            average_ball = ball;
        }
        // Получение среднего балла
        float get_average_ball()
        {
            return average_ball;
        }

    private:
        // Промежуточные оценки
        int scores[5];
        // Средний балл
        float average_ball;
        // Имя
        std::string name;
        // Фамилия
        std::string last_name;
};

// Установка имени студента
void Students::set_name(std::string student_name)
{
    Students::name = student_name;
}

// Получение имени студента
std::string Students::get_name()
{
    return Students::name;
}

// Установка фамилии студента
void Students::set_last_name(std::string student_last_name)
{
    Students::last_name = student_last_name;
}

// Получение фамилии студента
std::string Students::get_last_name()
{
    return Students::last_name;
}

// Установка промежуточных оценок
void Students::set_scores(int scores[])
{
    for (int i = 0; i < 5; ++i) {
        Students::scores[i] = scores[i];
    }
}

// Установка среднего балла
void Students::set_average_ball(float ball)
{
    Students::average_ball = ball;
}

// Получение среднего балла
float Students::get_average_ball()
{
    return Students::average_ball;
}
 
int main(){
    
    return 0;
}
