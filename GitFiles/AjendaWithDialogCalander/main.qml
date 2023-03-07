import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls

import QtQuick.LocalStorage 2.12
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var db;

    Rectangle {
        id: agenda

        anchors.fill: parent
        anchors.margins:5
        border.color:"black"
        radius:5
        color:"lightgray"

        Rectangle {
            id:forname
              width: agenda.width
               height: 40
               anchors.margins:5
               anchors.top:parent.top
               anchors.left:parent.left
               anchors.right: parent.right
               border.color:"black"
               radius:5

               Text {
                id: labelName
                text:"name"
                anchors.top:parent.top
                verticalAlignment: TextInput.AlignVCenter
              //  anchors.margins: 5
                width:parent.width
                height: 20
               minimumPixelSize: 50

               }

            TextInput {
               id: name
               anchors.top: labelName.bottom
               anchors.fill: parent
               anchors.leftMargin: 5
               anchors.topMargin: 20
               verticalAlignment: TextInput.AlignVCenter

             }

        }

        CampoInput {
           // id:forname
        }


       Boton {
        id: readBoton
        texto:"Search"
        anchors.top : forname.bottom
       // anchors.left : labelName.right;
       // anchors.leftMargin : 20;

        color: "gray"
        onClicked: {
            dialogCalander.open()
        }

    }

        Dialog {
            id:dialogCalander
            width:400
            height:400
            anchors.centerIn: parent

            Calander{
                id:calander
                color: "lightgreen"
                anchors.fill:parent;
               // height:500


                onDateSelected: (day,mon,yea) =>{
                       print(day,mon,yea);
                       dialogCalander.close();


                }
            }
        }
    }


}
