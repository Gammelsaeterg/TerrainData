#include "bsplinecurve.h"
#include "gsl_math.h"

BSplineCurve::BSplineCurve()
{
    createDefaultSplineCurve();
    addCurveToVertices(50);
}

void BSplineCurve::createDefaultSplineCurve()
{
    int scaleNum = 5;

    controlPoints.push_back(gsl::Vector3D(-4 * scaleNum, 0, -4 * scaleNum));
    controlPoints.push_back(gsl::Vector3D(-2 * scaleNum, 0,  4 * scaleNum));
    controlPoints.push_back(gsl::Vector3D( 2 * scaleNum, 0, -4 * scaleNum));
    controlPoints.push_back(gsl::Vector3D( 4 * scaleNum, 0,  4 * scaleNum));

    knots.push_back(0);
    knots.push_back(0);
    knots.push_back(0);
    knots.push_back(0);
    knots.push_back(1);
    knots.push_back(1);
    knots.push_back(1);
    knots.push_back(1);

    //temporariliy hard coded
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

        //qDebug() << tempVertex.get_xyz();
    }

}

std::vector<gsl::Vector3D> BSplineCurve::getSplineVerticeLocations()
{
    std::vector<gsl::Vector3D> temp;

    for (auto vertex : mVertices)
    {
        temp.push_back(vertex.get_xyz());
    }
    return temp;
}

void BSplineCurve::setNewHeights(std::vector<float> inFloats)
{

    for (int i = 0; i < mVertices.size(); ++i)
    {
        mVertices[i].set_xyz(mVertices[i].get_xyz().getX(), inFloats[i], mVertices[i].get_xyz().getY());
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

    //glLineWidth(3);
    glPointSize(5);
}

void BSplineCurve::draw()
{
    glBindVertexArray( mVAO );
    glDrawArrays(GL_LINE_STRIP, 0, mVertices.size());
}
