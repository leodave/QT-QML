import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 1000
    height: 1000
    visible: true
    title: qsTr("Hello World")

    Rectangle{
        color: "red";
        width: im.width +5;
        height: im.height +5;
        x:150; y:150;

        Image {
            id: im;
            source:"quick5/images/rocket.png"
            scale:2.0
        }
    }
}
