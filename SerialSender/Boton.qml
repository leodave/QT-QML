import QtQuick 2.12

Item {
    id: boton
    width:100
    height:50

    property alias text: textBoton.text
    property color color: "blue"
    property alias colorText: textBoton.text
    property alias tamText: textBoton.font.pixelSize
    property alias radius: rectangleBoton.radius

    signal clicked();

    Rectangle {
        id:rectangleBoton
        color: boton.color
        radius: height/5
        anchors.fill : parent

        Text {
            id: textBoton
            text: "Boton"
            font.pixelSize: boton.height/4
            anchors.centerIn: parent
        }
    }

    MouseArea {
        id: mouseAreaBoton
        anchors.fill: parent
        onPressed: {
            rectangleBoton.color =Qt.darker(boton.color)
        }
        onReleased: {
            rectangleBoton.color = boton.color
        }
        onClicked: {
            boton.clicked();
        }
    }

}
