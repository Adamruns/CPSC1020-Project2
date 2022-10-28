#ifndef QUIZ_H
#define QUIZ_H
#include <string>
class Quiz {
    private:
        std::string question;
        std::string answer;
        static int score;
    public:
        Quiz();
        Quiz(std::string q, std::string a);
        std::string getQuestion();
        std::string getAnswer();
        static int getScore();
        static void updateScore(int v);
        std::string showDate();

        friend std::string printResult(int q, int c, int w);

};
#endif