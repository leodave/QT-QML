import QtQuick 2.0

Item {
    id:campo
    property alias color : rectangleCampo.color
     property alias label : labelRectangle.text
     property alias input : name.text

    Rectangle {
                  id:rectangleCampo
                  width: agenda.width
                   height: 40
                   anchors.margins:5
                   anchors.top:parent.top
                   anchors.left:parent.left
                   anchors.right: parent.right
                   border.color:"black"
                   radius:5
                  // label: labelRectangle.text;

                   Text {
                    id: labelRectangle
                    text:"name"
                    anchors.top:parent.top
                    verticalAlignment: TextInput.AlignVCenter
                  //  anchors.margins: 5
                    width:parent.width
                    height: 20
                   minimumPixelSize: 50

                   }

                TextInput {
                   id: name
                   anchors.top: labelName.bottom
                   anchors.fill: parent
                   anchors.leftMargin: 5
                   anchors.topMargin: 20
                   verticalAlignment: TextInput.AlignVCenter

                 }
    }

            }


