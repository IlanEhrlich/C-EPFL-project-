QMAKE_CXXFLAGS += -std=c++11

TARGET = launch_text

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc \
    TextViewer.cc \
	../general/Balle.cc \
	../general/Brique.cc \
	../general/ChampForces.cc \
	../general/constantes.cc \
	../general/Gravite.cc \
	../general/Integrateur.cc \
	../general/IntegrateurEulerCromer.cc \
	../general/IntegrateurNewmark.cc \
	../general/IntegrateurRungeKutta.cc \ 
	../general/ObjetMobile.cc \
	../general/Obstacle.cc \
	../general/Pendule.cc \
	../general/Plan.cc \
	../general/PortionPlan.cc \
	../general/Systeme.cc \
	../general/Vecteur.cc \
	../general/Vent.cc \
	../general/Ventilateur.cc 




HEADERS += \
    ../general/Balle.h \
	../general/Brique.h \
	../general/ChampForces.h \
	../general/constantes.h \
	../general/Dessinable.h \
	../general/Gravite.h \
	../general/Integrateur.h \
	../general/IntegrateurEulerCromer.h \
	../general/IntegrateurNewmark.h \
	../general/IntegrateurRungeKutta.h \ 
	../general/ObjetMobile.h \
	../general/Obstacle.h \
	../general/Pendule.h \
	../general/Plan.h \
	../general/PortionPlan.h \
	../general/SupportADessin.h \
	../general/Systeme.h \
	../general/Vecteur.h \
	../general/Vent.h \
	../general/Ventilateur.h 
