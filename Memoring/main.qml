import QtQuick 2.12
import QtQuick.Window 2.12
import Qt.labs.folderlistmodel

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    id:vent;

   /*  Column {
        spacing: 5;

       Repeater {
            model:100;
            delegate: Rectangle {
                id: delegate

               required property int index

                width: 50;
                height:20;
                color:"lightblue";
                border.color: Qt.darker(color)
                border.width: 2

                Text {
                    id:txtDelegate
                    text: parent.index;
                    anchors.centerIn: parent

                }
            }
      }

    }

    Column {
        spacing: 5;

        Repeater {
            model: ["monday", "tuesday","wednsday","thursday", "friday","saturday", "sunday"]

            delegate: Rectangle {
                id:delgated
                width:100
                height:50;
                color:"lightblue"
                border.color:Qt.darker(color)
                border.width:2

                required property int index
                required property string modelData

                Text {
                    id:textdelegate
                    anchors.centerIn: parent
                    text: index + "-" + modelData
                }
                MouseArea {
                    anchors.fill: parent;

                    onClicked: {
                        console.log(index + "-" + modelData)
                    }
                }


            }
        }


    }

    Column {
        spacing:5
        Repeater {
            model: ListModel {
                id:listo
                ListElement {
                    nombre: "Lunes"
                    colorElemnt:"yellow"
                }
                ListElement {
                    nombre: "Martes"
                    colorElemnt:"lightblue"
                }
                ListElement {
                    nombre: "Meircoles"
                    colorElemnt:"lightgreen"
                }
                ListElement {
                    nombre: "jueves"
                    colorElemnt:"steelblue"
                }
                ListElement {
                    nombre: "Viernes"
                    colorElemnt:"pink"
                }
                ListElement {
                    nombre: "Sabado"
                    colorElemnt:"brown"
                }
                ListElement {
                    nombre: "Domingo"
                    colorElemnt:"orange"
                }
            }

            delegate: Rectangle {
                id: delgad
                required property var colorElemnt
                required property var nombre
                 required property var index
                width:100
                height:50
                color: colorElemnt
                border.color: Qt.darker(color)
                border.width: 2

                Text {
                    id:txt
                    anchors.centerIn: parent;

                    text:delgad.nombre;
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log(index + "-" + delgad.nombre );
                    }
                }
            }
        }


    ListView{
        id: listo
        anchors.fill: parent
        anchors.margins: 20;
        spacing: 5
        clip:true
        focus:true
        hightlightFollowsCurrent


        model: 100;
        delegate:delg
        highlight:result
//        delegate: Rectangle {
//            id:delg
//            width:100
//            height:50
//            color:"lightblue"
//            border.color: Qt.darker(color)
//            border.width: 2
//            required property int index;

//            Text {
//                id: txt
//                text:delg.index
//                anchors.centerIn: parent
//            }
//        }
        Component {
            id: delg

            Item{
                id: itemdelg
                width: listo.width
                height: 50;
               // anchors.horizontalCenter: parent.horizontalCenter
                required property int index;
                Rectangle {
                    id:recdelg

                    width:100
                    height:parent.height
                    color:"lightblue"
                    border.color: Qt.darker(color)
                    border.width: 2
                    anchors.centerIn: parent

                    Text {
                               id: txt
                               text:itemdelg.index
                               anchors.centerIn: parent
                          }
                }
                MouseArea {
                    id:mouse
                    anchors.fill:parent
                    onClicked:{
                       listo.currentIndex = itemdelg.index
                    }
                }
            }


        }

        Component {
            id: result

            Rectangle {
                width: listo.width
                color:"lightgreen"
                height:50;
               y:listo.currentItem.y

               Behavior on y {
                   SpringAnimation {
                       spring:2;
                       damping:0.5

                   }
               }


            }
        }
    }

    ListView{
        id: listo
        anchors.fill: parent
        anchors.margins: 20;
        spacing: 5
        clip:true
        focus:true
       // hightlightFollowsCurrent


        model: ListModel {
            id:listo2
            ListElement {
                nombre: "Lunes"
                colorElemnt:"yellow"
            }
            ListElement {
                nombre: "Martes"
                colorElemnt:"lightblue"
            }
            ListElement {
                nombre: "Meircoles"
                colorElemnt:"lightgreen"
            }
            ListElement {
                nombre: "jueves"
                colorElemnt:"steelblue"
            }
            ListElement {
                nombre: "Viernes"
                colorElemnt:"pink"
            }
            ListElement {
                nombre: "Sabado"
                colorElemnt:"brown"
            }
            ListElement {
                nombre: "Domingo"
                colorElemnt:"orange"
            }
        }
        delegate:delg
        highlight:result
//        delegate: Rectangle {
//            id:delg
//            width:100
//            height:50
//            color:"lightblue"
//            border.color: Qt.darker(color)
//            border.width: 2
//            required property int index;

//            Text {
//                id: txt
//                text:delg.index
//                anchors.centerIn: parent
//            }
//        }
        Component {
            id: delg

            Item{
                id: itemdelg
                width: listo.width
                height: 50;
               // anchors.horizontalCenter: parent.horizontalCenter
                required property int index;
                required property var nombre;
                required property var colorElemnt;
                Rectangle {
                    id:recdelg

                    width:100
                    height:parent.height
                    color:itemdelg.colorElemnt
                    border.color: Qt.darker(color)
                    border.width: 2
                    anchors.centerIn: parent

                    Text {
                               id: txt
                               text:itemdelg.nombre
                               anchors.centerIn: parent
                          }
                }
                MouseArea {
                    id:mouse
                    anchors.fill:parent
                    onClicked:{
                       listo.currentIndex = itemdelg.index
                    }
                }
            }


        }

        Component {
            id: result

            Rectangle {
                width: listo.width
                color:"lightgreen"
                height:50;
               y:listo.currentItem.y

               Behavior on y {
                   SpringAnimation {
                       spring:2;
                       damping:0.5

                   }
               }


            }
        }
    }*/
    ListView{
        id: listo
        anchors.fill: parent
        anchors.margins: 20;
        spacing: 5
        clip:true
        focus:true
      //  hightlightFollowsCurrentItem: false


        model: FolderListModel {
            id: modelo
            nameFilters:["*.jpg","*.jpeg",,"*.png"]
            showDirs:false
        }

        delegate:delg
        highlight:result
//        delegate: Rectangle {
//            id:delg
//            width:100
//            height:50
//            color:"lightblue"
//            border.color: Qt.darker(color)
//            border.width: 2
//            required property int index;

//            Text {
//                id: txt
//                text:delg.index
//                anchors.centerIn: parent
//            }
//        }
        Component {
            id: delg

            Item{
                id: itemdelg
                width: listo.width
                height: 50;
               // anchors.horizontalCenter: parent.horizontalCenter
                required property int index;
                required property var fileName;
                Rectangle {
                    id:recdelg

                    width:500
                    height:parent.height
                   // color:itemdelg.colorElemnt
                    border.color: Qt.darker(color)
                    border.width: 2
                    anchors.centerIn: parent

                   /* Text {
                               id: txt
                               text:itemdelg.fileName
                               anchors.centerIn: parent
                          }*/
                    Image {
                        id: img
                        source: "image://imageProvider/" + itemdelg.fileName
                        anchors.fill: parent;
                        fillMode: Image.PreserveAspectFit

                    }
                }
                MouseArea {
                    id:mouse
                    anchors.fill:parent
                    onClicked:{
                       listo.currentIndex = itemdelg.index
                        //create object
                       parent.state = "expand"
                    }
                }
                states: [
                    State {
                        name: "expand"
                        PropertyChanges {
                            target: itemdelg
                            height: vent.height

                        }
                    }
                ]
            }


        }

        Component {
            id: result

            Rectangle {
                width: listo.width
                color:"lightgreen"
                height:50;
               y:listo.currentItem.y

               Behavior on y {
                   SpringAnimation {
                       spring:2;
                       damping:0.5

                   }
               }


            }
        }
    }
















}





















