#include "bsplinecurve.h"
#include "gsl_math.h"

BSplineCurve::BSplineCurve()
{
    createDefaultSplineCurve();
    addCurveToVertices(20);
}

void BSplineCurve::createDefaultSplineCurve()
{
    controlPoints.push_back(gsl::Vector3D(-4, 0, -4));
    controlPoints.push_back(gsl::Vector3D(-2, 0,  4));
    controlPoints.push_back(gsl::Vector3D( 2, 0, -4));
    controlPoints.push_back(gsl::Vector3D( 4, 0,  4));

    knots.push_back(0);
    knots.push_back(0);
    knots.push_back(0);
    knots.push_back(0);
    knots.push_back(1);
    knots.push_back(1);
    knots.push_back(1);
    knots.push_back(1);
}

void BSplineCurve::addCurveToVertices(int subdivisions)
{
    gsl::Vector3D temp;
    Vertex tempVertex;
    for (int i = 0; i < subdivisions; ++i)
    {
        temp = gsl::bSpline(controlPoints, knots, i/static_cast<float>(subdivisions), 3);
        tempVertex.set_xyz(temp);
        mVertices.push_back(tempVertex);

        qDebug() << tempVertex.get_xyz();
    }
}

void BSplineCurve::init()
{
    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW );

    // glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE,sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex),  (GLvoid*)(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    glLineWidth(3);
    glPointSize(5);
}

void BSplineCurve::draw()
{
    glBindVertexArray( mVAO );
    glDrawArrays(GL_LINE_STRIP, 0, mVertices.size());
}
