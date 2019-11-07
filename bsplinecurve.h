#ifndef BSPLINECURVE_H
#define BSPLINECURVE_H
#include "visualobject.h"
#include "vector3d.h"

class Trophy;
class BSplineCurve : public VisualObject
{
public:
    BSplineCurve();
    ~BSplineCurve() override;

    void createDefaultSplineCurve();
    void addCurveToVertices(int subdivisions);
    std::vector<gsl::Vector3D> getSplineVerticeLocations();
    void setNewHeights(std::vector<float> inFloats);
    gsl::Vector3D getCurrentSplineLocation(float t);

    void createTrophies();

    void createClampedKnots(int degree, int numberOfControlPoints);
    void eventEndOfSpline();

    virtual void init() override;
    virtual void draw() override;

    std::vector<Trophy*> trophies;
    std::vector<gsl::Vector3D> trophyPoints;

private:
    std::vector<gsl::Vector3D> controlPoints;      // control points
    std::vector<GLfloat> knots;                    // knots
    unsigned long long degree{3};                                         //d = degree

};

#endif // BSPLINECURVE_H
