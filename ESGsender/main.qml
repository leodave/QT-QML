import QtQuick 2.12
import QtQuick.Window 2.12
import SerialGraphic.File

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    SerialGraphic {
        id: fileSent

//        onStarted: {
//        timer.start();
//        }
//      onStopped: {
//      timer.stop();
//        }
}


    Rectangle {
        id:btnSave
        height:50
        width:100;
      anchors.centerIn: parent;
        anchors.margins: 10;
        color:"lightblue";

        Text {
            id:btnText
            text:"Start";
            anchors.centerIn: parent;
            font.pixelSize: 20;

        }
        MouseArea {
            id:btnMouse;
            anchors.fill: parent;
            onClicked: {
              fileSent.start("ESG.txt","COM1",500, 115200);
           }
        }
    }

    Timer {
        id: timer
        interval: 100;
        repeat: true;
        onTriggered: {
            tiempo.timepassing += 0.1
        }
    }
    Text {
        id:tiempo
        property real timepassing:0.1;
        font.pixelSize: 30
        font.bold: true;

        text:timepassing;
        width: 100
        height: 50;
        anchors.top: btnSave.bottom
        anchors.topMargin: 50;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

}
