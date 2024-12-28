#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Pendule.h"
#include "Balle.h"
#include "Systeme.h"

#include "Pendule.h"
#include "Balle.h"
#include "PortionPlan.h"
#include "Brique.h"
#include "Gravite.h"
#include "Vent.h"
#include "Ventilateur.h"

using namespace std;


void VueOpenGL::dessine(Gravite &) {} //voir discussion sur le dessin des champs de force dans le fichier réponses
void VueOpenGL::dessine(Vent &) {}


void VueOpenGL::dessine(Ventilateur &) {} //un ventilateur n'est jamais dessiné, ce sont ses compoosantes déjà inscrites dans le système qui le sont, donc cette méthode ne s'avère pas utile
//cependant, dessine(Ventilateur &) est déclarée dans supportadessin donc il faut la définir

void VueOpenGL::dessineMonde() //dessin de la map, appelé dans l'initialisation de la page dans glwidget
{  
	
	QMatrix4x4 matrice3; 

	matrice3.translate(0.0, 0.0, -10.0);
	matrice3.rotate(35.0, 0.0, 1.0, 0.0);
	matrice3.rotate(45.0, 0.0, 0.0, 1.0); 

	dessineSol2();

	QMatrix4x4 matrice;
	matrice.translate(0.0, 5.0, -100.0);
	matrice.scale(20.0);
	dessineSphere(matrice, 1.0,1.0, 0.2); 
}


void VueOpenGL::dessine(PortionPlan & pp)
{
		
	QMatrix4x4 point_de_vue;
	point_de_vue.setToIdentity();
	
	prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

	glBegin(GL_QUADS);
		
		Vecteur p(pp.get_O()); //on dessine un quadrilatère grâce aux quatre points que l'on connaît, à la différence du dessin de plan
		prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); 
		prog.setAttributeValue(SommetId,  p.get_coord(0), p.get_coord(1), p.get_coord(2));	

		Vecteur a(pp.get_l());
		Vecteur q(p+a);
		prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); 
		prog.setAttributeValue(SommetId,  q.get_coord(0), q.get_coord(1), q.get_coord(2));
		
		
		Vecteur b(pp.get_L());
		Vecteur s(q+b);
		prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); 
		prog.setAttributeValue(SommetId,  s.get_coord(0), s.get_coord(1), s.get_coord(2));
				
		
		Vecteur r(p+b);
		prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); 
		prog.setAttributeValue(SommetId,  r.get_coord(0), r.get_coord(1), r.get_coord(2));
		
	glEnd();

	}
void VueOpenGL::dessine(Brique & obj) {
	
	for(auto pp:obj.get_Face()){this->dessine(pp);}
	
	}
void VueOpenGL::dessine(Plan & obj) 
{	
	
	QMatrix4x4 point_de_vue;
	point_de_vue.setToIdentity();
	
	prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

	Vecteur p(obj.get_O());
	Vecteur n(obj.get_normal());
	
	glBegin(GL_QUADS);
	
	double sum(n*p);
	
	//ici, on se sert de l'équation cartésienne du plan: on pose deux variables tour à tour à 100 et -100, puis on calcule la troisième
	//trois cas pour chaque possibilité où le coeffictient peut être nul. On suppose que 200x200 est suffisant pour être considéré infini.
	
	if(abs(n.get_coord(2))>1e-3){
		
		double z1(1/n.get_coord(2)*(sum-100*n.get_coord(0)-100*n.get_coord(1)));
		prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); 
		prog.setAttributeValue(SommetId,  100, 100, z1);
		
		double z2(1/n.get_coord(2)*(sum+100*n.get_coord(0)-100*n.get_coord(1)));
		prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); 
		prog.setAttributeValue(SommetId,  -100, 100, z2);	
		
		double z3(1/n.get_coord(2)*(sum+100*n.get_coord(0)+100*n.get_coord(1)));
		prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); 
		prog.setAttributeValue(SommetId,  -100, -100, z3);	
		
		double z4(1/n.get_coord(2)*(sum-100*n.get_coord(0)+100*n.get_coord(1)));
		prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); 
		prog.setAttributeValue(SommetId,  100, -100, z4);
			
		}

	else if(abs(n.get_coord(1))>1e-3){
		
		double y1(1/n.get_coord(1)*(sum-100*n.get_coord(0)));
		prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); 
		prog.setAttributeValue(SommetId,  100, y1, 100);
		
		double y2(1/n.get_coord(1)*(sum+100*n.get_coord(0)));
		prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
		prog.setAttributeValue(SommetId,  -100, y2, 100);	
		
		double y3(1/n.get_coord(1)*(sum+100*n.get_coord(0)));
		prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); 
		prog.setAttributeValue(SommetId,  -100, y3, -100);	
		
		double y4(1/n.get_coord(1)*(sum-100*n.get_coord(0)));
		prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); 
		prog.setAttributeValue(SommetId,  100, y4, -100);	
		
		}
		
	else{ //les coordonnées ne peuvent pas être les trois nulles 
		
		double x1(1/n.get_coord(1)*sum);
		prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); 
		prog.setAttributeValue(SommetId,  x1, 100, 100);
		
		prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); 
		prog.setAttributeValue(SommetId,  x1, -100, 100);	
		
		prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);
		prog.setAttributeValue(SommetId,  x1, -100, -100);	
		
		prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); 
		prog.setAttributeValue(SommetId,  x1, 100, -100);	
				
		}
				
	glEnd();
}



void VueOpenGL::dessine(Systeme & sys)
{
	sys.dessine_sur(*this); //exception du dessin
}


void VueOpenGL::dessine(Balle & bal){ //simplement le dessin d'une sphère
	
	QMatrix4x4 matrice;
	Vecteur pos(bal.get_position());
	matrice.translate(pos.get_coord(0),pos.get_coord(1), pos.get_coord(2));
	matrice.scale(bal.get_rayon());
	dessineSphere(matrice, 0.0,0.0,1.0); 
	
	}
	
void VueOpenGL::dessine(Pendule & pend){ 
	
	Vecteur ori(pend.get_position_origine());
	Vecteur pos(pend.get_position());
	
	dessineSegment(0.0,1.0,0.0,ori.get_coord(0), ori.get_coord(1), ori.get_coord(2), pos.get_coord(0), pos.get_coord(1), pos.get_coord(2)); //un segment
		
	QMatrix4x4 matrice;
	matrice.translate(pos.get_coord(0), pos.get_coord(1), pos.get_coord(2));
	matrice.scale(pend.get_rayon());
	dessineSphere(matrice,0.0,1,0.0); //une sphère
	
	
	}
	
void VueOpenGL::init()
{
	prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
	prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

	prog.bindAttributeLocation("sommet",  SommetId);
	prog.bindAttributeLocation("couleur", CouleurId);

	prog.bind();
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	sphere.initialize();                              
}

void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -4.0);
  matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
  matrice_vue.rotate(45.0, 0.0, 0.0, 1.0);
}

void VueOpenGL::translate(double x, double y, double z)
{
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}


void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  // Passe la matrice point_de_vue au shader
  prog.setUniformValue("vue_modele", point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}


void VueOpenGL::dessineCarreY(QMatrix4x4 const& point_de_vue,double taille,double c1, double c2, double c3){
	
	
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);


	double c(taille/2);
  // face coté Y = +1
  prog.setAttributeValue(CouleurId, c1, c2, c3); // bleu
  prog.setAttributeValue(SommetId, -c, 1.0, -c);
  prog.setAttributeValue(SommetId, -c, 1.0, +c);
  prog.setAttributeValue(SommetId, +c, 1.0, +c);
  prog.setAttributeValue(SommetId, +c, 1.0, -c);



  glEnd();
	
	}
	

//dessin du carrelage
void VueOpenGL::dessineSol(QMatrix4x4 const& point_de_vue){
	prog.setUniformValue("vue_modele", point_de_vue);
	glBegin(GL_QUADS);
	for(int j(0);j<10;++j){
				
		for(int i(-9);i<10;++i){
			
			QMatrix4x4 matrice1; 
			matrice1.translate(3*i, -10.0, -3*j-10);
			
			if((i+j)%2==0){
				dessineCarreY(matrice1,3.0,0.0,0.0,1.0);
				}
				
			else{
				dessineCarreY(matrice1,3.0,1.0,0.0,0.0);
				}
			}
		}
	glEnd();
	}


//dessin du sol retro
void VueOpenGL::dessineSol2(){
	
	QMatrix4x4 matrice1; 
	matrice1.translate(0.0, -4.5, 0.0);
	dessineCarreY(matrice1,150.0,0.0,0.0,0.0); //toile de fond pour empêcher de voir des objets sous le sol 
	
	for(int i(-9);i<10;++i){
		QMatrix4x4 matrice;
		matrice.translate(3*i, 0.0, 0.0);
		dessineLigneZ(matrice);
	}
	
	for(int i(0);i<30;++i){
		QMatrix4x4 matrice;
		matrice.translate(0.0, 0.0, -3*i);
		dessineLigneX(matrice);
	}
	
}

void VueOpenGL::dessineSegment(double c1, double c2, double c3, double a1, double a2, double a3, double b1, double b2, double b3, QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);
 
  prog.setAttributeValue(CouleurId, c1, c2, c3); // bleu
  prog.setAttributeValue(SommetId, a1, a2, a3);
  prog.setAttributeValue(SommetId, b1, b2, b3);

 glEnd();
}

	
void VueOpenGL::dessineLigneZ(QMatrix4x4 const& point_de_vue)
{
	prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

	glBegin(GL_LINES);

	prog.setAttributeValue(CouleurId, 0.0, 0.5, 0.5); // bleu
	prog.setAttributeValue(SommetId, 0.0, -3.0, 0.0);
	prog.setAttributeValue(SommetId, 0.0, -3.0, -100.0);

	glEnd();

}

void VueOpenGL::dessineLigneX(QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);
 
  prog.setAttributeValue(CouleurId, 0.0, 0.5, 0.5); // bleu
  prog.setAttributeValue(SommetId, -50.0, -3.0,0.0);
  prog.setAttributeValue(SommetId, 50.0, -3.0, 0.0);

 glEnd();
}


void VueOpenGL::dessineAxes (QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);


  // axe X
  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  }    
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);


  // axe Y
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);


  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

 glEnd();
}

void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue, double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}
