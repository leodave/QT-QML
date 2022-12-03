import QtQuick 2.12
import QtQuick.Window 2.12
//import FileRecieverGraphic.File
import FileReciever.File
import QtMultimedia

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
     //property list<real> datas;

    FileReciever {
        id: fileGraphic
        property real numb;
        onDataRecieved:(data)=> {
            for(var i = 0; i < data.length; i++){
                              canvaDraw.updated = (data[i] * 300);
                               print(canvaDraw.updated);
                              // time.running = true;

                                canvaDraw.requestPaint();
                               if(data[i] > 0.15){
                                   beep.play();
                               }
                           }
        }


    }
    SoundEffect {
        id: beep
        source:":/../../Users/34722/Downloads/beep-02.wav";
    }

    Component.onCompleted: {
        fileGraphic.start("COM2",115200);

        //print(fileGraphic.numb);





    }

    Rectangle {
        id:bigRec
        anchors.fill:parent;

         color:"gray"
         Canvas {
            id: canvaDraw
            anchors.fill: parent

            property real lastX : 20;
            property real lastY;
            property real updated



            onPaint: {
                var ctx = getContext('2d');
                ctx.lineWidth = 2;
                ctx.strokeStyle = "red";
                ctx.beginPath();
                ctx.moveTo(lastX,lastY);
                lastY = updated;
                ctx.lineTo(++lastX,updated);

                //lastX = areaDrawing.mouseX
                //lastY = areaDrawing.mouseY
                ctx.stroke();
            }
         }
        /* MouseArea {
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

         }*/
        /* Timer {
             id: time;
             interval: 25
             running: false;
             repeat: true
             onTriggered: {
                 canvaDraw.requestPaint();
             }

         }*/
    }

}
