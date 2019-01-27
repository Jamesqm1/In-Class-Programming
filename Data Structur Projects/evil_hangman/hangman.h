#ifndef _HANGMAN_H
#define _HANGMAN_H

/*
    hangman.h
        
    Class definition for the hangman class.

    assignment: CSCI 262 Project - Evil Hangman        

    author: 

    last modified: 9/24/2017
*/

#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

/******************************************************************************
   class hangman

   Maintains game state for a game of hangman.

******************************************************************************/

class hangman {
public:
    hangman();
    
    void print_words_left();

    // start a new game where player gets num_guesses unsuccessful tries
	void start_new_game(int num_guesses, int len);

    // player guesses letter c; return whether or not char is in word
    bool process_guess(char c);

    // display current state of word - guessed characters or '-'
    string get_display_word();

    // How many guesses remain?
	int get_guesses_remaining();
	int get_words_left();

    // What characters have already been guessed (for display)?
    string get_guessed_chars();

    // Has this character already been guessed?
    bool was_char_guessed(char c);

    // Has the game been won/lost?  (Else, it continues.)
    bool is_won();
    bool is_lost();
    bool is_valid_length(int len);

    // Return the true hidden word.
    string get_hidden_word();

private:
    set<char> guessed;
    map<int, vector<string> > _words;
    vector<string> current_words;
    
    int guesses;
    int length;
    int words_left;
    
    string hidden;
    string display;
    
    vector<string> word_families(char guess);
    void change_display(string dis, char c_guess);
    
};

#endif
