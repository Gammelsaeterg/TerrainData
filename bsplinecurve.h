#ifndef BSPLINECURVE_H
#define BSPLINECURVE_H
#include "visualobject.h"
#include "vector3d.h"

class BSplineCurve : public VisualObject
{
public:
    BSplineCurve();

    void createDefaultSplineCurve();
    void addCurveToVertices(int subdivisions);
    std::vector<gsl::Vector3D> getSplineVerticeLocations();
    void setNewHeights(std::vector<float> inFloats);
    gsl::Vector3D getCurrentSplineLocation(float t);

    void createClampedKnots(int degree, int numberOfControlPoints);

    virtual void init() override;
    virtual void draw() override;

private:
    std::vector<gsl::Vector3D> controlPoints;      // control points
    std::vector<GLfloat> knots;                    // knots
    unsigned long long degree{2};                                         //d = degree

};

#endif // BSPLINECURVE_H
