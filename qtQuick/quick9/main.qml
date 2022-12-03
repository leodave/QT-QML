import QtQuick 2.12
import QtQuick.Window 2.12

Window {

    width: 300
    height: 100
    visible: true
    title: qsTr("Hello World")


    Rectangle {
         id:background
         width: 300
         height: 100
         color: "lightblue"

        Image {
             id: ball
             source: "quick5/images/bas.jpg"
             anchors {
             left:background.left;
             leftMargin: background.width/16
             verticalCenter: background.verticalCenter
             top: background.top;
             bottom:  background.bottom;
             right: background.right;
             rightMargin: background.width/2
             }
        }

        Text {
            text:"Writing"; font.pixelSize:32;
            anchors.left:ball.right;
            anchors.leftMargin:32;
            anchors.baseline: ball.verticalCenter;

        }
    }


}
