CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 # C++11, ou autre suivant vos préférences

CXXFLAGS += -pedantic -Wall # pour les purs et durs

all: testChocs testBalle testChampForces testIntegrateur1 testIntegrateur2 testObstacle testObjetMobile testPendule testSysteme testVecteur testVentilateur


testBalle: testBalle.o Balle.o Vecteur.o ObjetMobile.o constantes.o SupportADessin.o Integrateur.o
testChampForces: testChampForces.o ChampForces.o Gravite.o Vent.o constantes.o ObjetMobile.o Vecteur.o SupportADessin.o PortionPlan.o Obstacle.o Plan.o Balle.o Systeme.o
testChocs : testChocs.o Obstacle.o Vecteur.o constantes.o Brique.o Balle.o ObjetMobile.o Plan.o PortionPlan.o Pendule.o Integrateur.o  IntegrateurEulerCromer.o Systeme.o Gravite.o ChampForces.o
testIntegrateur1: testIntegrateur1.o Integrateur.o Vecteur.o IntegrateurEulerCromer.o ObjetMobile.o Balle.o constantes.o Pendule.o 
testIntegrateur2: testIntegrateur2.o Integrateur.o Vecteur.o IntegrateurRungeKutta.o ObjetMobile.o Balle.o constantes.o Pendule.o 
testObstacle: testObstacle.o Obstacle.o Vecteur.o constantes.o Brique.o Balle.o ObjetMobile.o Plan.o PortionPlan.o Pendule.o Dessinable.o ObjetSimple.o SupportADessin.o Systeme.o
testObjetMobile: testObjetMobile.o ObjetMobile.o Vecteur.o constantes.o Balle.o SupportADessin.o Pendule.o Gravite.o ChampForces.o IntegrateurEulerCromer.o Integrateur.o
testPendule:testPendule.o Pendule.o ObjetMobile.o Vecteur.o constantes.o SupportADessin.o Balle.o Integrateur.o
testSysteme: testSysteme.o Systeme.o Dessinable.o Pendule.o Vecteur.o constantes.o ObjetMobile.o Balle.o SupportADessin.o Plan.o PortionPlan.o Brique.o Obstacle.o ChampForces.o Vent.o Gravite.o Integrateur.o  IntegrateurEulerCromer.o Ventilateur.o 
testVecteur: testVecteur.o Vecteur.o constantes.o 
testVentilateur: testVentilateur.o Vent.o Brique.o ChampForces.o ObjetMobile.o SupportADessin.o Dessinable.o PortionPlan.o constantes.o Vecteur.o constantes.o Obstacle.o Plan.o Balle.o Ventilateur.o Systeme.o


Balle.o: Balle.cc Vecteur.h Balle.h ObjetMobile.h constantes.h SupportADessin.h Systeme.h 
Brique.o: Brique.cc Brique.h Systeme.h Vecteur.h ObjetMobile.h constantes.h Obstacle.h PortionPlan.h Plan.h SupportADessin.h
ChampForces.o: ChampForces.cc Vecteur.h ChampForces.h ObjetMobile.h constantes.h ObjetSimple.h
constantes.o: constantes.cc constantes.h Vecteur.h
Dessinable.o: Dessinable.cc Dessinable.h SupportADessin.h
Gravite.o: Gravite.h Gravite.cc ChampForces.h Systeme.h ObjetMobile.h SupportADessin.h 
Integrateur.o: Integrateur.cc Integrateur.h Vecteur.h ObjetMobile.h constantes.h
IntegrateurEulerCromer.o: IntegrateurEulerCromer.cc IntegrateurEulerCromer.h Vecteur.h Integrateur.h ObjetMobile.h constantes.h
IntegrateurNewmark.o: IntegrateurNewmark.cc IntegrateurNewmark.h Vecteur.h Integrateur.h ObjetMobile.h constantes.h
IntegrateurRungeKutta.o: IntegrateurRungeKutta.cc IntegrateurRungeKutta.h Vecteur.h Integrateur.h ObjetMobile.h constantes.h
ObjetMobile.o: ObjetMobile.cc Vecteur.h ObjetMobile.h constantes.h ObjetSimple.h Integrateur.h 
ObjetCompose.o: ObjetCompose.cc ObjetCompose.h Dessinable.h
ObjetSimple.o: ObjetSimple.h ObjetSimple.cc Dessinable.h
Obstacle.o: Obstacle.cc Obstacle.h Vecteur.h ObjetMobile.h constantes.h ObjetSimple.h
Pendule.o: Pendule.cc Pendule.h Vecteur.h ObjetMobile.h constantes.h SupportADessin.h Balle.h Systeme.h 
Plan.o: Plan.cc Plan.h Systeme.h Obstacle.h Vecteur.h ObjetMobile.h constantes.h SupportADessin.h 
PortionPlan.o: PortionPlan.cc PortionPlan.h Vecteur.h Systeme.h Obstacle.h ObjetMobile.h constantes.h Plan.h SupportADessin.h 
SupportADessin.o: SupportADessin.h SupportADessin.cc
Systeme.o: Systeme.cc Systeme.h SupportADessin.h Integrateur.h IntegrateurEulerCromer.h ObjetMobile.h Obstacle.h ChampForces.h Dessinable.h
Vecteur.o: Vecteur.cc Vecteur.h
Vent.o: Vent.h Vent.cc ChampForces.h ObjetMobile.h SupportADessin.h PortionPlan.h Systeme.h
Ventilateur.o: Ventilateur.h Ventilateur.cc Vent.h Brique.h ChampForces.h ObjetMobile.h SupportADessin.h PortionPlan.h Vecteur.h constantes.h Obstacle.h Plan.h Systeme.h




testBalle.o: testBalle.cc Balle.h Vecteur.h ObjetMobile.h constantes.h SupportADessin.h
testChampForces.o: testChampForces.cc Vecteur.h ChampForces.h ObjetMobile.h constantes.h Gravite.h Vent.h PortionPlan.h Balle.h
testIntegrateur1.o: testIntegrateur1.cc Integrateur.h Vecteur.h ObjetMobile.h constantes.h IntegrateurEulerCromer.h Pendule.h
testObjetMobile.o: testObjetMobile.cc ObjetMobile.h Vecteur.h constantes.h 
testObstacle.o: testObstacle.cc Vecteur.h Obstacle.h constantes.h Plan.h PortionPlan.h Brique.h Balle.h SupportADessin.h 
testPendule.o: testPendule.cc Pendule.h Vecteur.h ObjetMobile.h constantes.h Balle.h
testSysteme.o: Systeme.h Systeme.cc testSysteme.cc Dessinable.h Pendule.h Balle.h SupportADessin.h ObjetMobile.h Plan.h PortionPlan.h Brique.h Vent.h Integrateur.h IntegrateurEulerCromer.h Obstacle.h ChampForces.h Ventilateur.h
testVecteur.o: testVecteur.cc Vecteur.h
testChocs.o: testChocs.cc Vecteur.h Obstacle.h constantes.h Plan.h PortionPlan.h Brique.h Balle.h Integrateur.h  IntegrateurEulerCromer.h Systeme.h Gravite.h ChampForces.h
testVentilateur.o: testVentilateur.cc  Ventilateur.h Ventilateur.cc Vent.h Brique.h ChampForces.h ObjetMobile.h SupportADessin.h PortionPlan.h Vecteur.h constantes.h Obstacle.h Plan.h Balle.h
testIntegrateur2.o : testIntegrateur2.cc Integrateur.h IntegrateurRungeKutta.h ObjetMobile.h Balle.h Pendule.h constantes.h Vecteur.h



clean:
	rm -rf  *.o testVecteur Vecteur 
