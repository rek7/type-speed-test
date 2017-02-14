#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

double word_count(double words_num, double time_elapsed){
    return words_num/time_elapsed;   
}

void print_text(int text_num){
    string type_file, text_line;
    if(text_num==1){
        type_file = "texts/1.txt";
    }
    else{
        type_file = "texts/2.txt";
    }
	ifstream type_text;
	type_text.open (type_file);
    while(!type_text.eof())
    {
        getline(type_text,text_line); 
        cout<<text_line;
    }
    cout << endl << "Start typing!" << endl;
	type_text.close();
    return;    
}

void type_test(){
    string line, split_line;
    vector<string> words_typed;
    time_t start = time(NULL);
    getline(cin, line);
    time_t end = time(NULL);
    stringstream white_space_divide(line);
    while(white_space_divide.good())
    {
        split_line = "";
        getline(white_space_divide,split_line,' ');
        if(split_line.size() > 0){
            words_typed.push_back(split_line);
        }
    }
    cout << "You averaged: " << word_count(words_typed.size(), end-start) <<  " Words per second" << endl;
    return;
}

int main(){
    string question;
    cout << "Type as many words as possible!" << endl << "Do you want text 1 or 2? ";
    cin >> question;
    if(stoi(question) <= 2 && stoi(question) > 0){
        print_text(stoi(question));
        cin.ignore();
        type_test();
    }
    else{
        cout << "Either text one or two" << endl;
    }
    return 0;
}