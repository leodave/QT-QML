import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle {
        width: 400
        height: 300
        color: "lightblue";

        Text {
            anchors.horizontalCenter: parent.horizontalCenter;
            y:40;
            height: parent.height/2
            text: "press me"
            font.pixelSize: 48
            color: mouseArea.pressed ? "green" : "black"

            MouseArea {
                anchors.fill: parent;
              id:mouseArea;

            }
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter;
            y: parent.height/2 +40;
            height:parent.height/2
            text: "click me";
            font.pixelSize: 48

            MouseArea {
                anchors.fill : parent;
                onClicked: parent.font.bold = !parent.font.bold;
            }
        }
    }



}
