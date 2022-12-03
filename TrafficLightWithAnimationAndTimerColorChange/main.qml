import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: traficLight
        property int estado: 0;
        width: height/2
        height:parent.height/2
        anchors.horizontalCenter: parent.horizontalCenter;

        anchors.top: parent.top;
        anchors.topMargin: 10;
        border.color:"black"
        border.width:2;
        color:"gray"
        state: "redUpGreenDown"

        states: [
            State {
                name: "redUpGreenDown"
                PropertyChanges {
                    target: luz1
                    color:"red"

                }
                PropertyChanges {
                    target: luz2
                    color:"green"

                }
            },
            State {
                name: "redDownGreenUp"
                PropertyChanges {
                    target: luz1
                    color:"green"

                }
                PropertyChanges {
                    target: luz2
                    color:"red"

                }
            }
        ]


            transitions: [
            Transition {
                    from: "redUpGreenDown"
                    to:"redDownGreenUp"


                    ColorAnimation {
                        target: luz1
                        properties:"color"
                        duration:500;


                    }
                    ColorAnimation {
                        target: luz2
                        properties:"color"
                        duration:5000;


                    }

                },

                Transition {
                        from: "redDownGreenUp"
                        to:"redUpGreenDown"


                        ColorAnimation {
                            target: luz1
                            properties:"color"
                            duration:800;


                        }
                        ColorAnimation {
                            target: luz2
                            properties:"color"
                            duration:800;


                        }

                    }
            ]
        Rectangle {
            id:luz1
            width: parent.width/1.5
            height:parent.width/1.5
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;
            anchors.topMargin: 10;
            color:"red"
            radius: width/2;
            border.color: "black"
            border.width: 2;


        }
        Rectangle {
            id:luz2
            width: parent.width/1.5
            height:parent.width/1.5
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 10;
            color:"green"
            radius: width/2;
            border.color: "black"
            border.width: 2;


        }

    }
    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: traficLight.bottom;
        anchors.topMargin: 50;
        color:"blue"
        width: traficLight.width
        height: luz1.height;
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    //label.text = "changed"
                   // timing.start()();
                    if(traficLight.state === "redUpGreenDown"){

                        traficLight.state = "redDownGreenUp"
                    }
                    else{
                         traficLight.state = "redUpGreenDown"
                    }
                }
              }

            Text {
                id: label
                text: ""
                anchors.bottom: parent.bottom;
                }
    }


          //onClicked:



         Timer {
             id: timing
             running:false
             repeat:false
             interval:2000
             onTriggered: {
                 label.text ="";
             }
         }


}
