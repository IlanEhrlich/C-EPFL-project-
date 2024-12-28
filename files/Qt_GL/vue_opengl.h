#pragma once

#include <QOpenGLShaderProgram> 
#include <QMatrix4x4>
#include "glsphere.h"
#include "SupportADessin.h"

#include "Vecteur.h"


//aucune nécessité de les inclure, on se contente d'une forward declaration
class Balle;
class Pendule;

class Plan;
class PortionPlan;
class Brique;
class Gravite;
class Vent;
class Ventilateur;

class Obstacle;
class ObjetMobile;
class ChampForces;

class Systeme;

class VueOpenGL : public SupportADessin {
	
	public:
	
		void init();
		void initializePosition();

		void setProjection(QMatrix4x4 const& projection)
		{ prog.setUniformValue("projection", projection); }

		void translate(double x, double y, double z);
		void rotate(double angle, double dir_x, double dir_y, double dir_z);

		//Méthodes de dessins élémentaires
		void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
		void dessineCarreY(QMatrix4x4 const& point_de_vue = QMatrix4x4(), double taille=1.0, double c1=0.0, double c2=0.0, double c3=1.0);
		void dessineSol(QMatrix4x4 const& point_de_vue = QMatrix4x4());
		void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);
		void dessineSegment(double c1, double c2, double c3, double a1, double a2, double a3, double b1, double b2, double b3, QMatrix4x4 const& point_de_vue=QMatrix4x4());
		void dessineLigneZ(QMatrix4x4 const& point_de_vue=QMatrix4x4());
		void dessineLigneX(QMatrix4x4 const& point_de_vue=QMatrix4x4());
		void dessineSol2(); //autre possibilité pour une map différente 
		void dessineSphere(QMatrix4x4 const& point_de_vue, double rouge = 1.0, double vert = 1.0, double bleu = 1.0);

		void dessineMonde();
		
		//Méthodes de dessin de nos objets
		virtual void dessine(Balle &) override;
		virtual void dessine(Pendule &) override;
		
		virtual void dessine(Systeme &) override;
		
		virtual void dessine(Plan &) override;
		virtual void dessine(Brique &) override;
		virtual void dessine(PortionPlan &) override;	
		virtual void dessine(Gravite &) override;
		
		virtual void dessine(Vent &) override;	
		virtual void dessine(Ventilateur &) override;	
		
	private:
	
		QOpenGLShaderProgram prog;
		GLSphere sphere;

		// Caméra
		QMatrix4x4 matrice_vue;
};
