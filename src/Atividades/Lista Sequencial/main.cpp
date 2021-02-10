#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "SeqList.h"
using namespace std;

int main()
{
	vector<SeqList*> listas;
	
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
			for(uint i = 0; i < listas.size(); ++i) {
				delete listas[i];
				listas[i] = nullptr;
			}
			listas.clear();
			break;
		}
		// create [n]
		else if(tokens[0] == "create") {
            int n = std::stoi(tokens[1]);
            SeqList *l = new SeqList(n);
			listas.push_back( l );
			cout << "lista " << listas.size()-1 << " criada" << endl;
		}
		// add [x] list [k]
		else if(tokens[0] == "add") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			if(listas[k]->add(x)) 
				cout << x << " foi adicionado ao final da lista " << k << endl;
			else 
				cout << "falha ao adicionar na lista " << k << ": lista cheia" << endl;
		}
		// remove [x] list [k]
		else if(tokens[0] == "remove") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			if(listas[k]->remove(x)) cout << x << " removido da lista " << k << endl;
			else cout << "nao ha elemento " << x << " na lista " << k << endl;
		}
		// search [x] list [k]
		else if(tokens[0] == "search") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			int i = listas[k]->search(x);
			if(i == -1) cout << "elemento " << x << " nao esta na lista " << k << endl;
			else cout << "elemento " << x << " esta no indice " << 
						i << " da lista " << k << endl;
		}
		// at [i] list [k]
		else if(tokens[0] == "at") {
			int i = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			cout << "elemento no indice " << i << " da lista " << k << " = " << 
					listas[k]->at(i) << endl;
		}
		// size [k]
		else if(tokens[0] == "size") {
			int k = std::stoi(tokens[1]);
			cout << "cardinalidade da lista " << k << " = " << listas[k]->size() << endl;
		}
		// isfull [k]
		else if(tokens[0] == "isfull") {
			int k = std::stoi(tokens[1]);
			if(listas[k]->isFull()) cout << "lista " << k << " cheia" << endl;
			else cout << "ainda ha espaco na lista " << k << endl;
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
        // replace [x] at [i] list [k]
		else if(tokens[0] == "replace") {
			int x = std::stoi(tokens[1]);
            int i = std::stoi(tokens[3]);
            int k = std::stoi(tokens[5]);
			if(listas[k]->replaceAt(x,i))
				cout << "slot " << i << " da lista " << k << " substituido com sucesso" << endl;
			else 
				cout << "falha ao substituir slot " << i << " da lista " << k << endl;
		}
		// removeat [i] list [k]
		else if(tokens[0] == "removeat") {
			int i = std::stoi(tokens[1]);
            int k = std::stoi(tokens[3]);
			if(listas[k]->removeAt(i))
				cout << "elemento na posicao " << i << " da lista " << k << " removido" << endl;
			else 
				cout << "falha ao remover elemento na posicao " << 
						i << " da lista " << k << endl;
		}
		// insert [x] at [i] list [k]
		else if(tokens[0] == "insert") {
			int x = std::stoi(tokens[1]);
            int i = std::stoi(tokens[3]);
			int k = std::stoi(tokens[5]);
			if(listas[k]->insertAt(x,i))
				cout << x << " inserido na posicao " << i << " da lista " << k << endl;
			else 
				cout << "falha ao inserir elemento " << x << " na posicao " << 
						i << " da lista " << k << endl;
		}
		// removeall [x] list [k]
		else if(tokens[0] == "removeall") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			listas[k]->removeAll(x);
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}