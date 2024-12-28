#pragma once

#include <QGLBuffer>
#include <QOpenGLShaderProgram>

//Cette classe n'a pas été modifiée

class GLSphere
{
public:
 GLSphere()
   : vbo(QGLBuffer::VertexBuffer), ibo(QGLBuffer::IndexBuffer)
 {}

  void initialize(GLuint slices = 25, GLuint stacks = 25);

  void draw(QOpenGLShaderProgram& program, int attributeLocation);

  void bind();
  void release();

private:
  QGLBuffer vbo, ibo;
  GLuint vbo_sz;
  GLuint ibo_sz[3];
};
