#ifndef TROPHY_H
#define TROPHY_H

#include "visualobject.h"

class Trophy : public VisualObject
{
public:
    Trophy();

public slots:
    void OnOverlapEvent(VisualObject *object);
};

#endif // TROPHY_H
