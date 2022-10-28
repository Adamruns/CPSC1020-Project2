#include "printResult.h"
#include "Quiz.h"

std::string printResult(int q, int c, int w){
    std::stringstream ss;
    ss << std::left << "Number of questions: " << q << "\n";
    ss << std::left << "Number correct answers: " << c << "\n";
    ss << std::left << "Number wrong answers: " << w << "\n";
    ss << std::left << "Final score: " << Quiz::getScore() << "\n";
    return (ss.str());
}