import QtQuick
import QtQuick3D
import CustomGeometryExample

Window {
    width: 640
    height: 480
    visible: true

    View3D {
        anchors.fill: parent
        camera: PerspectiveCamera {
            position: Qt.vector3d(0, 0, 200)
        }

        DirectionalLight {
            position: Qt.vector3d(-500, 500, -100)
        }

        Model {
            scale: Qt.vector3d(100, 100, 100)
            geometry: ExampleTriangleGeometry {}
            materials: [
                DefaultMaterial {
                    cullMode: DefaultMaterial.NoCulling
                    specularAmount: 0.5
                }
            ]
        }
    }
}
