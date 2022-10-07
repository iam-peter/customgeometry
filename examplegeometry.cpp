#include "examplegeometry.h"
#include <QRandomGenerator>
#include <QVector3D>

ExampleTriangleGeometry::ExampleTriangleGeometry()
{
    updateData();
}

void ExampleTriangleGeometry::updateData()
{
    clear();

    // PositionSemantic: The attribute is a position. 3 components: x, y, and z
    // ColorSemantic: The attribute is a vertex color vector. 4 components: r, g, b, and a
    int stride = 7 * sizeof(float);

    // 3 vertices in total for the triangle
    QByteArray vertexData(3 * stride, Qt::Initialization::Uninitialized);
    float *p = reinterpret_cast<float *>(vertexData.data());

    // a triangle, front face = counter-clockwise
    *p++ = -1.0f; // x
    *p++ = -1.0f; // y
    *p++ = 0.0f;  // z

    *p++ = 1.0f; // r
    *p++ = 0.0f; // g
    *p++ = 0.0f; // b
    *p++ = 1.0f; // a

    *p++ = 1.0f;
    *p++ = -1.0f;
    *p++ = 0.0f;

    *p++ = 0.0f;
    *p++ = 1.0f;
    *p++ = 0.0f;
    *p++ = 1.0f;

    *p++ = 0.0f;
    *p++ = 1.0f;
    *p++ = 0.0f;

    *p++ = 0.0f;
    *p++ = 0.0f;
    *p++ = 1.0f;
    *p++ = 1.0f;

    setVertexData(vertexData);
    setStride(stride);
    setBounds(QVector3D(-1.0f, -1.0f, 0.0f), QVector3D(+1.0f, +1.0f, 0.0f));

    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Triangles);

    addAttribute(QQuick3DGeometry::Attribute::PositionSemantic,
                 0,
                 QQuick3DGeometry::Attribute::F32Type);

    addAttribute(QQuick3DGeometry::Attribute::ColorSemantic,
                 3 * sizeof(float),
                 QQuick3DGeometry::Attribute::F32Type);
}
