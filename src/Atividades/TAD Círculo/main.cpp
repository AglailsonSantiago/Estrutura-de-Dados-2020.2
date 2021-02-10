#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Ponto.h"
#include "Circulo.h"

using namespace std;

int main()
{
	vector<Circulo*> circulos;
	
	while(true) {
		string cmd;
		getline(cin, cmd);

		std::stringstream ss{ cmd };
		vector<string> tokens;
		string buffer;

		while(ss >> buffer) {
			tokens.push_back(buffer);
		}

		if(tokens[0] == "libera" || tokens[0] == "exit") {
			for(int i = 0; i < circulos.size(); ++i) {
				circ_libera(circulos[i]);
				circulos[i] = nullptr;
			}
			circulos.clear();
			break;
		}
		// cria [raio] [x] [y]
		else if(tokens[0] == "cria") {
			Ponto *centro = pto_cria(std::stod(tokens[2]), std::stod(tokens[3]));
			Circulo *c = circ_cria(std::stod(tokens[1]), centro);
			circulos.push_back(c);
		}
		// imprime [int]
		else if(tokens[0] == "imprime") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));
			cout << "[raio:" << circ_getRaio(c) << ", X:" <<
				    circ_getX(c) << ", Y:" << circ_getY(c) << "]" << endl;
		}
		// imprime_todos
		else if(tokens[0] == "imprime_todos") {
			for(int i = 0; i < circulos.size(); ++i) {
				Circulo *c = circulos[i];
				cout << "[raio:" << circ_getRaio(c) << ", X:" <<
				    	circ_getX(c) << ", Y:" << circ_getY(c) << "]" << endl;
			}
		}
		// getx [int] 
		else if(tokens[0] == "getx") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));
			cout << "X: " << circ_getX(c) << endl;
		}
		// gety [int] 
		else if(tokens[0] == "gety") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));
			cout << "Y: " << circ_getY(c) << endl;
		}
		// setx [int] [novo X]
		else if(tokens[0] == "setx") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));
			double newX = std::stoi(tokens[2]);
			circ_setX(c, newX);
		}
		// sety [int] [novo Y]
		else if(tokens[0] == "sety") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));
			double newY = std::stoi(tokens[2]);
			circ_setY(c, newY);
		}
		// getarea [int] 
		else if(tokens[0] == "getarea") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));;
			cout << "area: " << circ_getArea(c) << endl;
		}
		// getraio [int] 
		else if(tokens[0] == "getraio") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));
			cout << "raio: " << circ_getRaio(c) << endl;
		}
		// getcentro [int] 
		else if(tokens[0] == "getcentro") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));			
			cout << "centro: (" << circ_getX(c) << "," << circ_getY(c) << ")" << endl;
		}
		// setraio [int] [new raio]
		else if(tokens[0] == "setraio") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));
			double newRaio = std::stoi(tokens[2]);
			circ_setRaio(c, newRaio);
		}
		// setcentro [int] [X] [Y]
		else if(tokens[0] == "setcentro") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));	
			Ponto *newp = pto_cria(std::stoi(tokens[2]), std::stoi(tokens[3]));		
			circ_setCentro(c, newp);
		}
		// interior [int] [X] [Y]
		else if(tokens[0] == "interior") {
			Circulo *c = circulos.at(std::stoi(tokens[1]));	
			Ponto *p = pto_cria(std::stoi(tokens[2]), std::stoi(tokens[3]));
			if(circ_interior(c, p) == 1) cout << "true" << endl;
			else cout << "false" << endl;
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}