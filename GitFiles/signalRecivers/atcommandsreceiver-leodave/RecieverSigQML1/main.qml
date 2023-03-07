import QtQuick 2.12
import QtQuick.Window 2.12
import fileRecieverProject.project

Window {
    id:window;
    width: 700
    height: 480
    visible: true
    title: qsTr("Hello World")
    property list<string> result;
    property list<string> result1;
    property list<var> resultnumbers;
    property string type;

   FileReciever {
       id: fileReciever;

       onDataReciever: (data) => {
                          // console.log(data);
                           result = data.split("\r\n");
                           result1 = result.pop();
                       }
       onDataRecievedNumber: (data) => {

                                  canva.update = (data*50);
                                  canva.requestPaint();
                             }
   }



   Rectangle {
       id: mainWindow
       anchors.fill: parent;
       color:"lightgray";

       Rectangle {
           id:drawRectangle
           width: (mainWindow.width *2)/3
           height: mainWindow.height - 80;
           color: "#868889";
           anchors.left: parent.left;
           anchors.top:parent.top;
           anchors.leftMargin: 10;
           anchors.topMargin: 10;

           Canvas {
               id: canva
               anchors.fill: parent;

               property real xValue : 0;
               property real yValue : 20;
               property real update;


               onPaint: {
                   var ctx = getContext('2d');
                   ctx.lineWidth =0.5;

                   ctx.setTransform(1,0,0,1,0,0 );
                   ctx.scale(3,1);
                   ctx.strokeStyle = "green";
                   ctx.beginPath;
                   ctx.translate(10,120);
                   ctx.moveTo(xValue,yValue);
                   yValue = update;
                   ctx.lineTo(++xValue,update);
                   ctx.stroke();

                   if(xValue >= 155){
                       xValue = 0;
                      ctx.reset();
                   }

               }
           }

       }
       Button {
           id: openPort
           anchors.top: drawRectangle.bottom
           anchors.left: parent.left
           anchors.topMargin: 5;
           anchors.leftMargin: 20
           botonColor: "blue";
           botonText: "Open Port";

           onClicked: {
              com1.visible = true;
              com2.visible = true;
           }
       }

       Button {
           id: com1
           anchors.bottom: parent.bottom
           anchors.left: drawRectangle.right
           anchors.bottomMargin: 120;
           anchors.leftMargin: 20
           botonColor: "blue";
           botonText: "COM1";
           visible: false;

           onClicked: {
              fileReciever.start("COM1",112500);
               com1.visible = false;
               com2.visible = false;
               openPort.visible = false;
               atStart.visible = true;
               atStop.visible = true;
               atSignal.visible = true;
               atCurr.visible = true;
               atMin.visible = true;
               atMax.visible= true;
           }
       }

       Button {
           id: com2
           anchors.top: com1.bottom
           anchors.left: drawRectangle.right
           anchors.topMargin: 10;
           anchors.leftMargin: 20
           botonColor: "blue";
           botonText: "COM2";
           visible: false;

           onClicked: {
              fileReciever.start("COM2",112500);
               com1.visible = false;
               com2.visible = false;
               openPort.visible = false;
               atStart.visible = true;
               atStop.visible = true;
               atSignal.visible = true;
               atCurr.visible = true;
               atMin.visible = true;
               atMax.visible = true;
           }
       }
       Button {
           id: atSignal
           anchors.top: drawRectangle.bottom
           anchors.left: openPort.right
           anchors.topMargin: 5;
           anchors.leftMargin: 20
           botonColor: "brown";
           botonText: "AT+SIGNALS";
           visible: false;

           onClicked: {
              fileReciever.clickReciever("AT+SIGNALS=?");
               typeOfSignals.visible = true;

           }
       }
       Button {
           id: atStart
           anchors.top: drawRectangle.bottom
           anchors.left: atSignal.right
           anchors.topMargin: 5;
           anchors.leftMargin: 20
           botonColor: "brown";
           botonText: "AT+START";
           visible: false;

           onClicked: {

              fileReciever.clickReciever("AT+START");
           }
       }
       Button {
           id: atStop
           anchors.top: drawRectangle.bottom
           anchors.left: atStart.right
           anchors.topMargin: 5;
           anchors.leftMargin: 20
           botonColor: "brown";
           botonText: "AT+STOP";
           visible: false;

           onClicked: {
              fileReciever.clickReciever("AT+STOP");

           }
       }
       Button {
           id: atMax
           anchors.top: atMin.bottom
           anchors.left: typeOfSignals.right
           anchors.topMargin: 10;
           anchors.leftMargin: 30
           botonColor: "blue";
           botonText: "AT+MAX";
           visible: false;

           onClicked: {
              fileReciever.clickReciever("AT+MAX");
           }
       }
       Button {
           id: atMin
           anchors.top: atCurr.bottom
           anchors.left: typeOfSignals.right
           anchors.topMargin: 10;
           anchors.leftMargin: 30
           botonColor: "blue";
           botonText: "AT+MIN";
           visible: false;

           onClicked: {
              fileReciever.clickReciever("AT+MIN");
           }
       }
       Button {
           id: atCurr
           anchors.top: parent.top
           anchors.left: typeOfSignals.right
           anchors.topMargin: 10;
           anchors.leftMargin: 30
           botonColor: "blue";
           botonText: "AT+CURR";
           visible: false;

           onClicked: {
             fileReciever.clickReciever("AT+CURR");
           }
       }
       ListView {
           id: typeOfSignals
           spacing: 10;
           model:window.result
           width: 80;
           anchors.left: drawRectangle.right;
           anchors.bottom: parent.bottom;
           anchors.top: parent.top;
           anchors.topMargin: 10;
           anchors.leftMargin: 5;
           anchors.rightMargin: 5;
           visible : false;
           delegate: Rectangle {

               height: 50;
               width:80;
               required property var index;
               required property var modelData;

                Button {

                    botonText: modelData;
                    onClicked: {
                        type = modelData
                        fileReciever.mixMaxStopTypes(modelData);

                    }
                }

           }
       }

   }

}
