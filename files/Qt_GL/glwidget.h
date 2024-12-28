#pragma once

#include <QOpenGLWidget>    
#include "vue_opengl.h"
#include <QTime> 
#include "Systeme.h"

class GLWidget : public QOpenGLWidget

{
public:
	GLWidget(Systeme const& sys, QWidget* parent = nullptr)
		: QOpenGLWidget(parent), systeme(sys)
		{}
	virtual ~GLWidget() = default;

private:

	virtual void initializeGL()                  override;
	virtual void resizeGL(int width, int height) override;
	virtual void paintGL()                       override;

	virtual void keyPressEvent(QKeyEvent* event) override;
	virtual void timerEvent(QTimerEvent* event)  override;

	void pause();

	VueOpenGL vue;

	int timerId;
	// pour faire évoluer les objets avec le bon "dt"

	QTime chronometre;
	Systeme systeme; //système remplace contenu comme attribut fondamental de glwidget: c'est ainsi que le pont s'effectuera entre les obets et leur représentation graphique
	//on aurait aussi pu envisager un pointeur sur un système
  
};
