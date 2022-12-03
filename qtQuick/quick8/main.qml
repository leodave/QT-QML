import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    color:"lightgreen"
    width: 500;
    height: 500;
    visible: true
    title: qsTr("Hello World")

    Item {
        property int _minside: Math.min(root.width, root.height)
        x: 10 + (root.width - _minside)/2
        y: 10 + (root.height - _minside)/2
        width: _minside -20;
        height: _minside -20;

        scale: Math.min(width / background.sourceSize.width, height /background.sourceSize.height)
        transformOrigin: Item.TopLeft

        Image {
            id: background;
            source: "quick5/images/clock.png"
        }
        Image {
            id: smallArm
            source: "quick5/images/secondHand.png"
            x: background.width/2 -width/2;
            y: background.height/2 - 914;

            transform: Rotation {
                origin.x : smallArm.width /2;
                origin.y :914;

                RotationAnimation on angle {
                    from: 0;
                    to: 360*2
                    duration:60000
                    loops:Animation.Infinite;
                }
            }


        }

    }


}
