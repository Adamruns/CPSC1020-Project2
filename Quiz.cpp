#include "Quiz.h"
int Quiz::score = 0;
Quiz::Quiz(){
    question = "";
    answer = "";
}
Quiz::Quiz(std::string q, std::string a){
    question = q;
    answer = a;
}
std::string Quiz::getQuestion(){
    return question;
}
std::string Quiz::getAnswer(){
    return answer;
}
int Quiz::getScore(){
    return score;
}
void Quiz::updateScore(int s){
    score += s;
    if (score < 0){
        score = 0;
    }
}