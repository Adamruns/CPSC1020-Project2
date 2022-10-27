#include "Quiz.h"
#include "printResult.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
using namespace std;
int main (int argc, char const *argv[]){
    ifstream inputfile;
    vector<Quiz> quizVector;
    string question, answer;
    inputfile.open(argv[1]);
    int numberCorrect = 0;
    int numberWrong = 0;

    while (!inputfile.eof()){
        getline(inputfile, question);
        question.erase(0,3);
        getline(inputfile, answer);
        answer.erase(0,3);
        Quiz quizObject(question, answer);
        quizVector.push_back(quizObject);
    }
    // This shuffles the vector using time random
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle ( quizVector.begin(), quizVector.end(), default_random_engine(seed));


    for(vector<Quiz>::size_type i = 0; i != quizVector.size(); i++) {
        string userAnswer;
        string realAnswer = quizVector[i].getAnswer();
        cout << quizVector[i].getQuestion() << endl;
        getline(cin, userAnswer);
        cout << "Comparing " << "'" << userAnswer << "'" << " to " << "'" << realAnswer << "'" << endl;
        if (userAnswer.compare(realAnswer) == 0){
            quizVector[i].updateScore(1);
            numberCorrect += 1;
            cout << "Correct!" << endl;
        }
        else {
            quizVector[i].updateScore(-1);
            numberWrong += 1;
            cout << "Wrong! Correct Answer: " << realAnswer << endl;
        }
        cout << "Current Score: " << Quiz::getScore() << endl;

    }
    cout << printResult(quizVector.size(), numberCorrect, numberWrong);

 

    return 0;
}