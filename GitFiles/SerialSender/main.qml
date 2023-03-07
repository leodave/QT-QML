import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import my.classes

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    color: "lightgray"

    property var availablePorts;

    menuBar: MenuBar {
        Menu {
            title:"&File"

            Menu {
                id:menuDoors
                title:"&Doors"
                width:80

                ListView {
                    id:doorLists
                    width:80

                    model: availablePorts

                    delegate: Rectangle {
                        id:delegateRectangle
                        width:parent.width
                        height:30

                        CheckBox {
                            id: checkBox
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 5
                        }
                        Text {
                               id: nameDoor
                               text: modelData
                               anchors.verticalCenter: parent.verticalCenter
                               anchors.left: checkBox.right
                             }
                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true

                            onClicked: {
                                //serialSender.portName = modelData

                                checkBox.toggle();

                                if(checkBox.checked){
                                    serialSender.openPort();
                                }else{
                                    serialSender.closePort();
                                }
                            }
                            onEntered: {
                                delegateRectangle.color ="steelblue";
                            }
                            onExited: {
                                delegateRectangle.color = "white";
                            }

                        }
                    }
                }
            }

            MenuSeparator {}

            MenuItem {
                text:"&Exit"

                onTriggered: {
                    Qt.quit();
                }
            }
        }
    }

    SerialSender {
        id:serialSender

        onPortNameChanged: (nameDoor) => {
            print("From on PortNameChanged: " + nameDoor);
        }
        onValueRecieved: (value)=> {
                             dataDoorSerial.text += String.fromCharCode(value);
                         }
    }
    Component.onCompleted: {
        availablePorts = serialSender.listAvailablePorts();
        console.log(availablePorts);


        doorLists.height = 30 * availablePorts.length;


          /*  for(var i = 0; i < availablePorts.length; i++){
            menuDoors.addItem(MenuItem.createObject(
            menuDoors, {text:availablePorts[i], onTriggered: Qt.quit()}));*/

    }
    Component.onDestruction: {
        serialSender.closePort();
    }

    Rectangle {
        id: container

        anchors.top: parent.top
        anchors.bottom: containerSender.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20

        color: "white"
        radius: 10

        Text {
                 id: dataDoorSerial
                 text: ""

                 anchors.fill: parent
                 anchors.margins: 10
             }
    }
    Rectangle {
        id: containerSender

        anchors.bottom: botonSend.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20

        height: 40

        color: "white"
        radius: 10

        TextInput {
            id: datasSent

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10

            MouseArea {
                   anchors.fill: parent
                   hoverEnabled: true
                   cursorShape: Qt.IBeamCursor

                   onClicked: {
                              datasSent.focus = true;
                          }
            }
        }

    }

    Boton {
           id: botonSend

           text: "Send"

           anchors.right: parent.right
           anchors.bottom: parent.bottom
           anchors.margins: 20

           onClicked: {
               serialSender.sendString(datasSent.text);

           }
       }
}
