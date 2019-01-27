/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author:

    last modified: 9/24/2017
*/

#include "hangman.h"

using namespace std;

// constructor
hangman::hangman() { 
    ifstream fin;
    fin.open("dictionary.txt");
    string temp;
    while(!fin.eof()){
        fin >> temp;
        _words[temp.size()].push_back(temp);
    }
    fin.close();
}


// start_new_game()
//
// Setup a new game of hangman.
void hangman::start_new_game(int num_guesses, int len) {
    guesses = num_guesses;
    length=len;
    hidden = _words[len][0];
    words_left = _words[len].size();
    current_words = _words[len];
    string dis(len,'_');
    display = dis;
    
}


// process_guess()
//
// Process a player's guess - should return true/false depending on whether
// or not the guess was in the hidden word.  If the guess is incorrect, the
// remaining guess count is decreased.
bool hangman::process_guess(char c) {
    guessed.insert(c);
    vector<string> next = word_families(c);
    if(next.size()==0){
        guesses--;
        return false;
    }
    else{
        current_words=next;
        change_display(current_words[0],c);
        current_words.erase(current_words.begin());
        hidden = current_words[0];
        words_left = current_words.size();
        guesses--;
        return true;
    }
    
}


// get_display_word()
//
// Return a representation of the hidden word, with unguessed letters
// masked by '-' characters.
string hangman::get_display_word() {
    return display;
}


// get_guesses_remaining()
//
// Return the number of guesses remaining for the player.
int hangman::get_guesses_remaining() {
    return guesses;
}

int hangman::get_words_left(){
    return words_left;
}


// get_guessed_chars()
//
// What letters has the player already guessed?  Return in alphabetic order.
string hangman::get_guessed_chars() {
    string output ="";
    for(std::set<char>::iterator it = guessed.begin(); it!=guessed.end();it++){
        output+= *it;
    }
    return output;
}


// was_char_guessed()
//
// Return true if letter was already guessed.
bool hangman::was_char_guessed(char c) {
    if(guessed.count(c)==1){
        return true;
    }
    return false;
}


// is_won()
//
// Return true if the game has been won by the player.
bool hangman::is_won() {
    if(display.find('_')==std::string::npos){
        return true;
    }
    return false;
}


// is_lost()
//
// Return true if the game has been lost.
bool hangman::is_lost() {
    if(guesses==0){
        return true;
    }
    return false;
}


// get_hidden_word
//
// Return the true hidden word to show the player.
string hangman::get_hidden_word() {
    return hidden;
}

bool hangman::is_valid_length(int len){
    if(_words.count(len)>=1){
        return true;
    }
    return false;
}

vector<string> hangman::word_families(char guess){
    map<string,vector<string>> tempmap;
    for( string s : current_words){
        string temp(s.length(), ' ');
        for(int i =0; i<s.length();i++){
            if(s[i] == guess){
                temp[i]='1';
            }
            else{
                temp[i]='0';
            }
        }
        if(tempmap.count(temp)==0){
            tempmap[temp].push_back(temp);
            tempmap[temp].push_back(s);
        }
        else{
            tempmap[temp].push_back(s);
        }
        
    }
    vector<string> largest;
    for(std::map<string,vector<string>>::iterator it = tempmap.begin();it!=tempmap.end();it++){
        vector<string> t = it->second;
        if(t.size() > largest.size()){
            largest = t;
        }
    }
    return largest;
}

void hangman::change_display(string dis, char c_guess){
    for(int i =0; i<dis.length();i++){
        if(dis[i]=='1'){
            display[i]= c_guess;
        }
    }
}

// void print_words_left(){
//     for(std::vector<string>::iterator it = current_words.begin(); it!=current_words.end();it++){
//         cout << *it << " ";
//     }
// }