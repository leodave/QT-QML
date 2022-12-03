import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        width: 640
        height: 480

        gradient: Gradient {
            GradientStop {
                position: -0.0; color: "green"
            }
            GradientStop {
                position: 1.0; color:"blue";
            }
        }
    }
}
