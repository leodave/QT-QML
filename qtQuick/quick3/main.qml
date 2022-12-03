import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300
    height:115
    visible: true
    title: qsTr("Hello World")

    TextInput {
        id: textElement
        x:50;
        y:25;
        text: "qt quick"
        font.family: "Helvetica"; font.pixelSize: 50;
    }

    Rectangle {
        x: 50; y: 75;
        height: 5;
        width: textElement.width;
        color: "green";
    }

}
