#include <cstring> 
#include <cctype> 
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void readDataFromFile(int twoDim[][2], int rows, const string& fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    // make sure its open
    if(!myfile){
        cout << "cant open file" << endl;
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < 2; j++){
            myfile >> twoDim[i][j];
        }
    }

    myfile.close();
}

int uppercaseChange(){
    cout << "enter a string: " << endl;
    char str[81];
    cin.get(str, 80);
    int len;
    len = strlen(str);
    for (int i = 0; i <len; i++)
        cout << static_cast<char>(toupper(str[i]));
    return 0;
}


char examGrade(int score)
{
    char grade; 
    if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else 
        grade = 'F';

    return grade;
}


int processAnswer(const char answerString[], const char keyString[])
{
    int len;
    int score = 0;
    len = strlen(keyString);
    // for loop to change to upper
    for (int i = 0; i < len; i++){
        if (answerString[i] == keyString[i]){
            score += 2;
        }
        else if (answerString[i] == ' '){
            score = score + 0; 
        }
        else if (answerString[i] != keyString[i]){
            score = score - 1;
        }
    }
    score = (score*100)/40;
    cout << score; 
    return static_cast<int>(score);
}


int main()
{
    char keystr[NO_OF_QUESTIONS + 1];
    char answerstr[NO_OF_QUESTIONS + 1];
    char ID[9];
    char ch;

    ifstream myfile;

    myfile.open("../data/exam.txt");

    if(!myfile){
        cout << "cant open file" << endl;
        return 1;
    }

    myfile.get(keystr, NO_OF_QUESTIONS + 1);
    myfile.get();

    cout << "key: " << keystr << endl;

    while(myfile >> ID){
        myfile.get();
        myfile.get(answerstr, NO_OF_QUESTIONS + 1);
        myfile.get();

        int score = processAnswer(answerstr, keystr);
        cout << ID << answerstr << " " << score << " " << examGrade(score) << endl;
    }
    cout << endl;
    myfile.close();
    return 0;
}

int averageHigh(int twoDim[][2], int rows)
{
    int average = 0;
    int sum = 0;
    // accumulator
    for(int i = 0; i < rows; i++){
        sum += twoDim[i][0];
    }
    average = sum/rows;

    return average;
}

int averageLow(int twoDim[][2], int rows)
{
    int average = 0;
    int sum = 0;
    for(int i = 0; i < rows; i++){
        sum += twoDim[i][1];
    }
    average = sum/rows;

    return average;
}

int indexHighTemp(int twoDim[][2], int rows)
{
    int ind;
    int highs[12];
    for(int i = 0; i < rows; i++){
        for (int f =0; f<2; f++){
            twoDim[i][2] >> highs[i];
        }
    }
    int max_value = highs[0];
    for (int i = 0; i < rows; i++) {
        if (highs[i] > max_value) {
            max_value = highs[i];
            ind = i;
        }
    }
    return ind;
}

int indexLowTemp(int twoDim[][2], int rows)
{
    int ind = 0;

    for (int i = 0; i < rows; i++) {
        if (twoDim[ind][1] > twoDim[i][1]) {
            ind = i;
        }
    }
    return ind;
}