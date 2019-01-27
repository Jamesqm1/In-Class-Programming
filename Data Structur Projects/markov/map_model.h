#ifndef _MAP_MODEL_H
#define _MAP_MODEL_H

#include "model.h"
#include <map>
#include <vector>


class map_model : public markov_model {
public:
	virtual void initialize(std::string text, int order) {

		_data = text+text;
		_order = order;
		for(int i=0;i+_order<_data.length();i++){
		    kgram[_data.substr(i,_order)].push_back(_data[i+_order]);
		}
	}

	virtual std::string generate(int size){
	    int start = rand() % (_data.length() - _order);
	    std::string seed = _data.substr(start, _order);

    	std::string answer ="";
    	answer+=seed;


    	for (int i = 0; i < size-_order; i++) {

    		char c = kgram[answer.substr(i,_order)][rand()%kgram[answer.substr(i,_order)].size()];
	    	answer.push_back(c);
    	}

    	return answer;
	}
	
    

protected:
	std::string _data;
	int _order;
	std::map<std::string,std::vector<char>> kgram;
};

#endif

