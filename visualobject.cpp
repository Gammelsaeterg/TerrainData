#include "visualobject.h"
#include "shader.h"

VisualObject::VisualObject()
{
    mMatrix.setToIdentity();
}

VisualObject::~VisualObject()
{
   glDeleteVertexArrays( 1, &mVAO );
   glDeleteBuffers( 1, &mVBO );
}

void VisualObject::init()
{
}

void VisualObject::move(float deltaTime)
{

}

void VisualObject::update(float time)
{

}
