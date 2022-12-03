import QtQuick 2.12
import QtQuick.Window 2.12
import SignalProject.FileManager 2.0

Window {
    width: 500
    height: 480
    visible: true
    title: qsTr("Hello World")


    Rectangle {
        anchors.fill: parent;
        anchors.centerIn: parent
        id:ventana
        Rectangle {
            id:horLayout
            anchors.horizontalCenter: ventana.horizontalCenter
            width: ventana.width/2
            height: ventana.height/6

            ListView {
                id: colors
                width:ventana.width
                height:ventana.height/6
              //  anchors.top: ventana.top
                //anchors.centerIn:  ventana.center
                spacing: 5
                orientation:ListView.Horizontal

                property color coloring : "red";

                model: ["red","yellow","blue","green"]
                clip:true
                delegate: Rectangle {
                          id:recColor
                          width:colors.height
                          height:colors.height
                          required property  color modelData
                          color:modelData
                          border.color:Qt.darker(color)
                          border.width:2

                          MouseArea {
                              id: selectColor
                              anchors.fill: parent
                              onClicked: {
                                  colors.coloring = modelData;


                              }
                          }

                        }



            }

        }
        Rectangle {
            id:bigRec
            anchors {
                top: horLayout.bottom
                right:ventana.right
                left:ventana.left
                bottom:saveBoton.top
                margins: 10


            }

             color:"gray"
            /*for drawing inside manually
                    Canvas {
                id: canvaDraw
                anchors.fill: parent
                property color clr: colors.coloring
                property real lastX;
                property real lastY;

                onPaint: {
                    var ctx = getContext('2d');
                    ctx.lineWidth = 2;
                    ctx.strokeStyle = canvaDraw.clr;
                    ctx.beginPath();
                    ctx.moveTo(lastX,lastY);
                    ctx.lineTo(areaDrawing.mouseX,areaDrawing.mouseY);

                    lastX = areaDrawing.mouseX
                    lastY = areaDrawing.mouseY
                    ctx.stroke();
                }
             }*/
             Canvas {
                id: canvaDraw
                anchors.fill: parent
                property color clr: colors.coloring
                property real lastX : 20;
                property real lastY;

                onPaint: {
                    var ctx = getContext('2d');
                    ctx.lineWidth = 2;
                    ctx.strokeStyle = canvaDraw.clr;
                    ctx.beginPath();
                   // ctx.moveTo(lastX,lastY);
                    //ctx.lineTo(areaDrawing.mouseX,areaDrawing.mouseY);
                    ctx.moveTo(lastX,200);
                    ctx.lineTo(lastX++,fileManager.read()* 30);

                    //lastX = areaDrawing.mouseX
                    //lastY = areaDrawing.mouseY
                    ctx.stroke();
                    console.log("timer")
                }
             }
             MouseArea {
                 id: areaDrawing
                 anchors.fill:parent

                 onPressed: {
                            canvaDraw.lastX = mouseX
                            canvaDraw.lastY = mouseY
                     console.log( canvaDraw.lastX, canvaDraw.lastY);
                 }
                 onPositionChanged: {
                       canvaDraw.requestPaint()
                     console.log( canvaDraw.lastX, canvaDraw.lastY);
                 }

             }
        }

        Rectangle {
            id: saveBoton
            color:"pink"
            width:100
            height:50


            anchors.bottom: ventana.bottom
            anchors.horizontalCenter: ventana.horizontalCenter
            anchors.margins: 10

            Text {

                text: "Save"
                anchors.centerIn: parent
                font.pixelSize: 30
            }

            MouseArea {
                id: botonmouse
                anchors.fill:parent
                onClicked: {
                    canvaDraw.grabToImage
                            (
                                (result)=> {
                                        result.saveToFile("draw.png");
                                }
                             );
                }
            }
//            HoverHandler {
//                id:hover
//                acceptedDevices: PointerDevice.Mouse
//                onHoveredChanged: {
//                    saveBoton.color= "blue"
//                }


//            }

        }
        Rectangle {
            id: drawBoton
            color:"green"
            width:100
            height:50


            anchors.bottom: ventana.bottom
            anchors.left: saveBoton.right
            anchors.margins: 10

            Text {

                text: "Signal"
                anchors.centerIn: parent
                font.pixelSize: 30
            }

            MouseArea {
                id: drawmouse
                anchors.fill:parent
                onClicked: {
                 fileManager.open(":/signal.txt");

                  timer.running = true;
                }
            }
//            HoverHandler {
//                id:hover
//                acceptedDevices: PointerDevice.Mouse
//                onHoveredChanged: {
//                    saveBoton.color= "blue"
//                }


//            }

        }
        Timer {
            id: timer
            interval:25
            running:false
            repeat:true

            onTriggered: {
                canvaDraw.requestPaint();
            }
        }
        FileManager {
            id: fileManager
        }




    }


}
