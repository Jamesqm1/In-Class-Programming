#ifndef _WORD_MODEL_H
#define _WORD_MODEL_H

#include "model.h"
#include <map>
#include <vector>
#include <sstream>


class word_model : public markov_model {
public:
	virtual void initialize(std::string text, int order) {

		_data = text+text;
		_order = order;
		std::istringstream iss(_data);
		std::string s;
		while(!iss.eof()){
		    iss >> s;
		    words.push_back(s);
		}
		for(int i =0; i<words.size()-_order;i++){
		    std::string key ="";
		    for(int j =0;j<_order;j++){
		        key+=words[i+j]+" ";
		    }
		    wgram[key].push_back(words[i+_order]);
		}
	}

	virtual std::string generate(int size){
	    int start = rand() % (words.size()-_order);
	    std::string seed ="", answer="";
	    std::vector<std::string> gen;
        for(int i =0; i<_order;i++){
            seed+=words[i+start]+" ";
            gen.push_back(words[i+start]);
        }
        answer+=seed;
        std::string s1;
        
    	for (int i = 1; i < size-_order; i++) {

    	    s1 = wgram[seed][rand()%wgram[seed].size()];
    	    gen.push_back(s1);
    	    answer+=s1+" ";
    	    seed="";
    	    for(int j = i; j<i+_order;j++){
    	        seed+=gen[j]+" ";
    	    }
    	}

    	return answer;
	}
	
    

protected:
	std::string _data;
	int _order;
	std::map<std::string,std::vector<std::string>> wgram;
	std::vector<std::string> words;
};

#endif

