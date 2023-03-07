import QtQuick 2.12

Item {
    id: celdacontainer
    width:40
    height:25
    property alias colorCelda: celdaRectangle.color
    signal clicked(colorCelda: color)
    Rectangle {
        id:celdaRectangle
        border.color: Qt.darker(color)
        anchors.fill:parent
        border.width: 2

    }
    MouseArea {
        anchors.fill:parent
        onClicked:
            celdacontainer.clicked(celdacontainer.colorCelda)
    }

}
