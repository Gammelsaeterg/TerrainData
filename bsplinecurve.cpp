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
    controlPoints.push_back(gsl::Vector3D(-3 * scaleNum, 0, -3 * scaleNum));

    //trophy coordinates
    controlPoints.push_back(gsl::Vector3D(18, 0, -19));
    controlPoints.push_back(gsl::Vector3D(18, 0, 18));
    controlPoints.push_back(gsl::Vector3D(-19, 0, -19));
//    18, 19.7f, -19

//    18, 8.12f, 18

//    -19, 3.9f, -19

    controlPoints.push_back(gsl::Vector3D( -3 * scaleNum, 0,  3 * scaleNum));
    controlPoints.push_back(gsl::Vector3D( -4 * scaleNum, 0,  4 * scaleNum));


    createClampedKnots(2, controlPoints.size());
}

void BSplineCurve::addCurveToVertices(int subdivisions)
{
    gsl::Vector3D temp;
    Vertex tempVertex;



    for (int i = 0; i < subdivisions; ++i)
    {
        temp = gsl::bSpline(controlPoints, knots, i/static_cast<float>(subdivisions), degree);
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
        mVertices[i].set_xyz(mVertices[i].get_xyz().getX(), inFloats[i], mVertices[i].get_xyz().getZ());
    }
}

gsl::Vector3D BSplineCurve::getCurrentSplineLocation(float t)
{
     auto tempFloat = gsl::bSpline(controlPoints, knots, t, degree);
     return tempFloat;
}

void BSplineCurve::createClampedKnots(int degree, int numberOfControlPoints)
{
    knots.clear();

    for (int i = 0; i < degree + 1; ++i)
    {
        knots.push_back(0);
    }

    if (numberOfControlPoints > 2)
    {
        for (int i = 0; i < numberOfControlPoints - 3; ++i)
        {
            float tempPiece = 1.f / (numberOfControlPoints - 2);
            knots.push_back(tempPiece * ((i+1)));
        }
    }

    for (int i = 0; i < degree + 1; ++i)
    {
        knots.push_back(1);
    }

//    for (auto knot : knots)
//    {
//        qDebug() << knot;
//    }
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
