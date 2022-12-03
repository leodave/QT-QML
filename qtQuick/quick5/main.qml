import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 400; height: 400;
    visible: true
    title: qsTr("Hello World");


     Image {
            x:150; y: 150;
             source:"images/rocket.png"
             width: sourceSize.width /2; height: sourceSize.height/2;
             Component.onCompleted: console.log(height,width, sourceSize)
        }

}
