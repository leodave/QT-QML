import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root;
    width: 400
    height: 400
    visible: true
    title: qsTr("Hello World")
    color:grey;

    Rectangle {
        id:lightblue;
        x: 50; y: 50 ;
        height: (root.height -50)/2; width: root.width-100;
        color: "lightblue";

        Rectangle {
            x: lightblue.x; y: lightblue.y;
            height: 50; width: 50;
            color: "white";
        }
    }


    Rectangle {
        x: lightblue.x; y: (lightblue.y)*4;
        height: 150; width: 300;
        color: "green";

        Rectangle {
            x: 100; y: 50;
            height: 50; width: 150;
            color: "blue";

        }

    }
}
