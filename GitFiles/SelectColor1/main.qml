import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: wind
    width: 640
    height: 480
    visible: true
    title: "Change Text color"

Rectangle{
    anchors.fill: parent

    Rectangle {
        width:wind.width/10

        height: wind.height/10
           id:hombrecito

        Image {
             id:imagine
            source:"quick5/images/bas.jpg"
            scale: wind.width/(10*width)
            anchors.fill: parent
             }
    }
    focus:true
    Keys.onPressed: (event)=> {
                        switch(event.key){
                            case Qt.Key_Left:
                            hombrecito.x -=5
                            imagine.mirror = true
                            textToChange.text = hombrecito.x +","+ hombrecito.y
                           // textToChange.text = hombrecito.mapToItem(colorPicker,hombrecito.x,hombrecito.y+
                             //                                        ""+ )
                            break;
                            case Qt.Key_Right:
                            hombrecito.x +=5
                             imagine.mirror = false
                             textToChange.text = hombrecito.x +","+ hombrecito.y
                            break;
                            case Qt.Key_Up:
                            hombrecito.y -=5
                             textToChange.text = hombrecito.x +","+ hombrecito.y
                            break;
                            case Qt.Key_Down:
                            hombrecito.y +=5
                             textToChange.text = hombrecito.x +","+ hombrecito.y
                            break;
                        }
                    }


    Text {
        text: "Selected color"
        id: textToChange
        anchors.centerIn: parent
        font.pointSize: 30
        font.bold: true
    }

    Grid {
        id: colorPicker
        x: 10;
        anchors.bottom: parent.bottom
       anchors.left: parent.left
        anchors.bottomMargin: 10
         anchors.leftMargin: 10
         rows: 2
        columns:3
        spacing:2

        Celda {
            colorCelda: "darkblue"
            onClicked: (colorRecieved)=> {
                           textToChange.color = colorRecieved
                       }
        }
        Celda {
            colorCelda: "yellow"
            onClicked: (colorRecieved)=> {
                           textToChange.color = colorRecieved
                       }
        }
        Celda {
            colorCelda: "lightcoral"
            onClicked: (colorRecieved)=> {
                           textToChange.color = colorRecieved
                       }
        }
        Celda {
            colorCelda: "maroon"
            onClicked: (colorRecieved)=> {
                           textToChange.color = colorRecieved
                       }
        }
        Celda {
            colorCelda: "orange"
            onClicked: (colorRecieved)=> {
                           textToChange.color = colorRecieved
                       }
        }
        Celda {
            colorCelda: "red"
            onClicked: (colorRecieved)=> {
                           textToChange.color = colorRecieved
                       }
        }

    }

}

}
