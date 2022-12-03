import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: "Tennis Game"

    Rectangle {
        id: cancha
        color:"gray"
        anchors.fill:parent;

        Rectangle{
            id:player1;

           x:0
           y:0;
            Raquet {
                anchors.fill: parent;
                color: "red";
            }
        }



        Rectangle{
            id:player2;

           anchors.right: parent.right;
           anchors.rightMargin: 25;
           y:0;
            Raquet {
                anchors.fill: parent;
                   color:"yellow";
            }
        }
        focus:true;
        Keys.onPressed: (event) => {
                            switch(event.key){
                                case Qt.Key_W:
                                player1.y -= 5;

                                break;
                                case Qt.Key_S:
                                player1.y += 5;
                                break;
                                case Qt.Key_Down:
                                player2.y += 5;

                                break;
                                case Qt.Key_Up:
                                player2.y -= 5;
                                break;
                                case Qt.Key_H:
                                ball.x +=5

                            }
                        }
        Rectangle{
            id: ball;
            height: parent.height/10;
            width: parent.width/10;
            anchors.topMargin: 50;
            x:player1.x + 25;
            Image {

                source:"quick5/images/ten.jpg"
                anchors.fill:parent;
            }
        }



    }
}
