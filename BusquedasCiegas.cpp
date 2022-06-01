#include "algoritmos.hpp"

//----------SOBRECARGAMOS << PARA IMPRIMIR GRAFOS----------------
 ostream& operator<<(ostream &out,const Grafo &grafo){
 for(auto const &vertice : grafo){
     out<<vertice.first<<": ";
     out<<"[";
     for(size_t i=0;i<vertice.second.size();i++){
     out<<vertice.second[i];
     if(i!=vertice.second.size()-1){
         out<<",";
     }
     }
     out<<"]";
     out<<endl;
 }
 return out;
 }
int main(){
Grafo grafo;
//-------DISEÑAMOS LA ESTRUCTURA DEL GRAFO---------------------------
grafo["A"]={"B","C","D"};
grafo["B"]={"A","H"};//vertice b conectado a la A y H
grafo["C"]={"A","G","F"};
grafo["D"]={"A","E"};
grafo["E"]={"D","K"};
grafo["F"]={"C","J"};
grafo["G"]={"C","J"};
grafo["H"]={"B","I"};
grafo["I"]={"H","J"};
grafo["J"]={"F","G","I","K"};
grafo["K"]={"E","J"};
vector<string> recorrido=busqueda_profundidad(grafo);
for(auto const &vertice:recorrido)
	cout<<vertice<<endl;
}

