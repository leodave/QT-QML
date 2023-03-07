import QtQuick 2.12

Item {
    id: botonContainer
    height: 50;
    width:100;
    property  alias botonColor: btnRectangle.color
    property alias botonText: btnText.text
    signal clicked();

    Rectangle {
        id: btnRectangle
        anchors.fill: parent;
        color:"green"

        Text {
            id: btnText
            text: "hello"
            anchors.centerIn: parent

        }
        MouseArea {
            id: btnMouse
            anchors.fill: parent;

            onClicked: {
                botonContainer.clicked();
            }
        }
    }

}
