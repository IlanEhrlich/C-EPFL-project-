#include <iostream>
#include "TextViewer.h"

using namespace std;

//Nous n'avons pas jugé utile de se servir de textViewer pour représenter différemment les Dessinables que le cout ne faisait déjà. c'est donc simplement défini ainsi.  

void TextViewer::dessine(Pendule & obj) {cout<<obj<<endl;} 
void TextViewer::dessine(Balle & obj) {cout<<obj<<endl;} 
void TextViewer::dessine(Plan & obj) {cout<<obj<<endl;}
void TextViewer::dessine(Brique & obj) {cout<<obj<<endl;}
void TextViewer::dessine(PortionPlan & obj) {cout<<obj<<endl;}
void TextViewer::dessine(Gravite & obj) {cout<<obj<<endl;}
void TextViewer::dessine(Vent & obj) {cout<<obj<<endl;}
void TextViewer::dessine(Ventilateur & obj) {cout<<obj<<endl;}
