import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        color: "black"
        implicitWidth: child.implicitWidth;
        implicitHeight: child.implicitHeight;

        Image {
            id: child
            source: "quick5/images/bas.jpg"
            anchors.fill: parent;
            anchors.margins: 5;

        }
    }
}
