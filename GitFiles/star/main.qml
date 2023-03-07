import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Shapes
import QtQuick.Path 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Rectangle {
        width: 300
        height: 300

        Path {
            id: starPath
            startX: 150
            startY: 50

            PathMovement {
                x: 150
                y: 250
            }

            PathQuad {
                x: 50
                y: 150
            }

            PathQuad {
                x: 250
                y: 150
            }

            PathLine {
                x: 100
                y: 50
            }

            PathLine {
                x: 200
                y: 50
            }
        }

        Color: "yellow"
        Stroke {
            color: "black"
            width: 2
            path: starPath
        }
    }

}
