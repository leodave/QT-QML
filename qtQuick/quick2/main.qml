import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 400; height: 200;
    visible: true
    title: qsTr("Hello World")

        Rectangle
        {
             x: 100; y: 50;
             width: height * 2;  height: 100;
             color: "lightblue";
        }



}
