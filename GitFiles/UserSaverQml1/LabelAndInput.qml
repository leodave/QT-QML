import QtQuick 2.12
import QtQuick.Controls

Item {
    id: labAndInp
    height: 120
    width: 300
    property alias label: labeler.text
    property alias input: inputer.text
    property alias inputecho: inputer.echoMode;

    Rectangle {
        anchors.topMargin: 60;
        anchors.fill: parent
        id:recLabAndInp
        border.color: Qt.darker(color)
        color:"lightGray"

        Text {
            id:labeler;
            anchors.top:parent.top
            anchors.horizontalCenter: parent.horizontalCenter;
            font.bold: true;
            font.pixelSize: 20;
        }
    Rectangle{
        id:inputRec
        anchors.top:labeler.bottom
        border.color: "black"
        height: 35
        width: parent.width;
        anchors.topMargin: 5

        TextInput {
            id:inputer
            anchors.fill: parent;
            anchors.leftMargin: 30;
            anchors.topMargin: 10;
            focus: true;
            text:"";
            echoMode: TextInput.Normal

           // echoMode: TextInput.Normal;
            //border.color: "black"
            //anchors.left: parent.left
           // anchors.margins: 150;
        }
    }


    }

}
