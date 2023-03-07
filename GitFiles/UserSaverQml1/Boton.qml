import QtQuick 2.12
import QtQuick.Controls

Item {

        id: btnContainer
        height:50
        width: 100
        signal clicked()
        property alias btnTexter: btnText.text
        property alias btnColor: boton.color

        Rectangle {
            id: boton
            anchors.fill: parent
            color: "blue"
            Text {
                id: btnText
                text:""
                anchors.centerIn: parent
                font.bold: true;
                font.pixelSize: 15;
            }
            MouseArea {
                id:mouseBoton
                anchors.fill: parent

                onClicked: {
                    btnContainer.clicked();
                }
            }
        }



}
