#ifndef ALGORITMOS_h
#define ALGORITMOS_h
#include <iostream>
#include <map>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
//-------------DECLARAMOS UN GRAFO---------------------------------
 typedef map<string,vector<string> > Grafo;//(string-nombre del vertice,vector de aristas)
 
vector<string> busqueda_profundidad(const Grafo &grafo, const string &origen="A")
{
  vector<string> visitados;
  stack<string> pila;
vector<string>recorrido;
visitados.push_back(origen);
pila.push(origen);
while(!pila.empty())
{
  auto const &vertice = pila.top();
  recorrido.push_back(vertice);
  pila.pop();
  auto const &adyacentes = grafo.at(vertice);
  for(size_t i=0; i < adyacentes.size();i++){
  	auto const &ady = adyacentes[i];
  	if(find(visitados.begin(), visitados.end(), ady)== visitados.end()){
  	  visitados.push_back(ady);
		pila.push(ady);	
	  }
  }
}
return recorrido;
}
#endif
