#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "List.h"
using namespace std;

int main()
{
	vector<List*> listas;
	
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
		// add [x] list [k]
		else if(tokens[0] == "add") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			listas[k]->add(x); 
			cout << x << " adicionado na lista " << k << endl;
		}
		// remove [x] list [k]
		else if(tokens[0] == "remove") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			listas[k]->remove(x);
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
        // removeall [x] list [k]
		else if(tokens[0] == "removeall") {
			int x = std::stoi(tokens[1]);
			int k = std::stoi(tokens[3]);
			listas[k]->removeAll(x);
		}
		// removeat [i] list [k]
		else if(tokens[0] == "removeat") {
			int i = std::stoi(tokens[1]);
            int k = std::stoi(tokens[3]);
			if(listas[k]->removeNodeAt(i))
				cout << "elemento na posicao " << i << " da lista " << k << " removido" << endl;
			else 
				cout << "falha ao remover elemento na posicao " << 
						i << " da lista " << k << endl;
		}
		// insert [x] after [i] list [k]
		else if(tokens[0] == "insert") {
			int x = std::stoi(tokens[1]);
            int i = std::stoi(tokens[3]);
			int k = std::stoi(tokens[5]);
			if(listas[k]->insertAfter(x,i))
				cout << x << " inserido apos a posicao " << i << " da lista " << k << endl;
			else 
				cout << "falha ao inserir elemento " << x << " apos a posicao " << 
						i << " da lista " << k << endl;
		}
        // copy [k]
		else if(tokens[0] == "copy") {
			int k = std::stoi(tokens[1]);
			List *cp = listas[k]->copy();
			listas.push_back(cp);
            cout << "uma copia da lista " << k << 
                    " foi criada: ela eh a lista " << listas.size()-1 << endl;
		}
        // equal [p] [q]
		else if(tokens[0] == "equal") {
			int p = std::stoi(tokens[1]);
            int q = std::stoi(tokens[2]);
			bool iguais = listas[p]->equal(listas[q]);
			if(iguais) cout << "listas " << p << " e " << q << " sao iguais" << endl;
            else cout << "listas " << p << " e " << q << " sao diferentes" << endl;
		}
        // concat [p] [q]
		else if(tokens[0] == "concat") {
			int p = std::stoi(tokens[1]);
            int q = std::stoi(tokens[2]);
			listas[p]->concat(listas[q]);
			cout << "listas " << p << " e " << q << " concatenadas" << endl;
            cout << "lista " << p << ": " << listas[p]->toString() << endl;
            cout << "lista " << q << ": " << listas[q]->toString() << endl;
		}
        // reverse [k]
		else if(tokens[0] == "reverse") {
			int k = std::stoi(tokens[1]);
			listas[k]->reverse();
			cout << "lista " << k << " invertida" << endl;
            cout << "lista " << k << " = " << listas[k]->toString() << endl;
		} 
		// copyarray [n] [a1] [a2] [a3] .. [an] list [k]
		else if(tokens[0] == "copyarray") {
			int n = std::stoi(tokens[1]);
			int k = std::stoi(tokens[n+3]);
			int arr[n];
			for(int i = 0; i < n; i++) {
				arr[i] = std::stoi(tokens[2+i]);
			}
			listas[k]->copyArray(arr,n);
			cout << "array foi copiado para lista " << k << endl;
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}