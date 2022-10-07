#ifndef EXAMPLEGEOMETRY_H
#define EXAMPLEGEOMETRY_H

#include <QQuick3DGeometry>

class ExampleTriangleGeometry : public QQuick3DGeometry
{
    Q_OBJECT
    QML_NAMED_ELEMENT(ExampleTriangleGeometry)

public:
    ExampleTriangleGeometry();

private:
    void updateData();
};

#endif
