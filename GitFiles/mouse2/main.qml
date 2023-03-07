import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 240
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        width: 640;
        height: 240;
        color:"lightblue";

        Rectangle {
            id: focusBox;
            anchors {
                verticalCenter: parent.verticalCenter;
                left: parent.left;
                leftMargin: 20;
                    }
            width: 200; height: 200;
            color: focusArea.containsMouse ? "green" : "cyan"
            Text {
                anchors.centerIn: parent;
                text:"Observe my color";
            }
        }

        Rectangle {
            id: focusBox2;
            anchors.centerIn: parent;
            anchors.leftMargin: 20;
            width: 200; height: 200;
            color: "yellow"
            Text {
                anchors.centerIn: parent;
                text:"Move into me";
            }
            MouseArea {
                id: focusArea;
                anchors.fill: parent;
                hoverEnabled: true;
            }
        }
        Rectangle {
            id: focusBox3;
            anchors {
                verticalCenter: parent.verticalCenter;
                 rightMargin: 20;
                 right:parent.right
            }
             width: 200; height: 200;
            color: "black"
            Text {
                color:"white"
                anchors.centerIn: parent;
                text:"click\nme";
            }
            MouseArea {
                id: focusArea2;
                anchors.fill: parent;
                hoverEnabled: true;
                onClicked: focusBox.color = "red";
            }
        }
    }
}
