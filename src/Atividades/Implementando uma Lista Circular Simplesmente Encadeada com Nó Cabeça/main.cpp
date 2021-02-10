#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include "List.h"
using namespace std;

int main()
{
	vector<List*> listas; // vector que guarda todas as listas criadas
	
	while(true) {
		string cmd;
		getline(cin, cmd);

		std::stringstream ss{ cmd };
		vector<string> tokens;
		string buffer;

		while(ss >> buffer) {
			tokens.push_back(buffer);
		}

		if(tokens[0] == "exit") {
			for(int i = 0; i < listas.size(); ++i) {
				delete listas[i];
				listas[i] = nullptr;
			}
			listas.clear();
			break;
		}
		// createlist
		else if(tokens[0] == "createlist") {
            List *l = new (std::nothrow) List();
			listas.push_back( l );
            if(l != nullptr) cout << "lista " <<  listas.size()-1 << " criada" << endl;
		}
		// addback [x] list [k]
		else if(tokens[0] == "addback") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			listas[k]->add_back(x); 
			cout << x << " adicionado ao final da lista " << k << endl;
		}
		// addfront [x] list [k]
		else if(tokens[0] == "addfront") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			listas[k]->add_front(x); 
			cout << x << " adicionado no inicio da lista " << k << endl;
		}
		// remove [x] list [k]
		else if(tokens[0] == "remove") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			listas[k]->remove(x);
		}
		// removeall [x] list [k]
		else if(tokens[0] == "removeall") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			listas[k]->removeAll(x);
		}
		// removefront [k]
		else if(tokens[0] == "removefront") {
			int k = std::stoi(tokens[1]);
			int elem = listas[k]->remove_front();
			if(elem != INT_MIN) cout << elem << " removido do inicio lista " << k << endl;
			else cout << " nao foi possivel remover do inicio da lista " << k << endl;
		}
		// removeback [k]
		else if(tokens[0] == "removeback") {
			int k = std::stoi(tokens[1]);
			int elem = listas[k]->remove_back();
			if(elem != INT_MIN) cout << elem << " removido do final lista " << k << endl;
			else cout << " nao foi possivel remover do final da lista " << k << endl;
		}
        // empty [k]
		else if(tokens[0] == "empty") {
			int k = std::stoi(tokens[1]);
			if(listas[k]->empty()) cout << "lista " << k << " vazia" << endl;
			else cout << "ha elementos na lista " << k << endl;
		}
        // size [k]
		else if(tokens[0] == "size") {
			int k = std::stoi(tokens[1]);
			cout << "cardinalidade da lista " << k << " = " << listas[k]->size() << endl;
		}
        // clear [k]
		else if(tokens[0] == "clear") {
			int k = std::stoi(tokens[1]);
			listas[k]->clear();
			cout << "lista " << k << " vazia" << endl;
		}
		// print [k]
		else if(tokens[0] == "print") {
			int k = std::stoi(tokens[1]);
			cout << "lista " << k << " = " << listas[k]->toString() << endl;
		}
		// contains [x] list [k]
		else if(tokens[0] == "contains") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			if(listas[k]->contains(x)) cout << x << " esta na lista " << k << endl;
			else cout << x << " NAO esta na lista " << k << endl;
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}