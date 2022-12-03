import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 400
    height: 400
    visible: true
    title: qsTr("Hello World")

   Image {
           x: 100; y: 100;

            source:"quick5/images/rocket.png"
            height: sourceSize.height/4;
             width: sourceSize.width/4;
            rotation: 45.0
            transformOrigin: Item.TopLeft;
        }

}
