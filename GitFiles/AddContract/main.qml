import QtQuick 2.12
import QtQuick.Window 2.12
import templateinterface.interface
import QtQuick.Dialogs
import QtQuick.Controls 2.12

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title:"Contract PDF generator"

     property list<string> allText;
     property list<string> recievedText;
     property int num: 0;

    Templatehandler {
        id: templatehandler;
    }
    menuBar: MenuBar {
        Menu {
            id:menu
            title:"&File"

            MenuItem {
                id:menuDoors
                text:"&Open File"
                width:80

                MouseArea {
                    id:menuMouse
                    anchors.fill: parent;
                    onClicked: {
                         loadFileDialog.open();
                         menu.close();
                    }
                }
            }
            MenuSeparator {}

            MenuItem {
                text:"&Exit"

                onTriggered: {
                    Qt.quit();
                }
            }
        }
    }

    FileDialog {
        id: saveFileDialog;
        fileMode: FileDialog.SaveFile;
        onAccepted: {
            var url = saveFileDialog.selectedFile.toString();
            url = url.split("///")[1];
        }
   }
    FileDialog {
        id: loadFileDialog;
        onAccepted: {
            var url = loadFileDialog.selectedFile.toString();
            url = url.split("///")[1];

            templatehandler.addTemplate(url);

           allText = templatehandler.obtainLayer();
            print(allText.length);

        }
   }

    ListView {
        id: list
        spacing: 10
        clip:true
        anchors.fill:parent
        model:allText;
        delegate: Rectangle {

            id:recDelegate
            width: 500
            height: 50
            anchors.horizontalCenter:  parent.horizontalCenter
            border.width: 2
            border.color: "gray"
            color:"gray"

             required property var index;
             required property var modelData;

            Text {
                id:txtDelegate
                text: modelData;
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.top:parent.top;
            }
            Rectangle {
                id:recInput
                anchors.bottom: parent.bottom;
                anchors.left: parent.left;
                height:25;
                width: parent.width;
                border.color:"gray";

                TextInput {
                    id: inputrec
                    anchors.fill: parent;
                    focus:true;
                    anchors.leftMargin:30;
                    font.bold: true;
                    font.pixelSize: 20;

                    onTextChanged:  {
                              console.log( index);
                              recievedText[index] = inputrec.text
                    }

                }

            }

        }
    }
    Rectangle {
        id:btnSave
        height:50
        width:100;
        anchors.bottom: parent.bottom;
        anchors.right: parent.right;
        anchors.margins: 10;
        color:"lightblue";

        Text {
            id:btnText
            text:"Save";
            anchors.centerIn: parent;
            font.pixelSize: 20;

        }
        MouseArea {
            id:btnMouse;
            anchors.fill: parent;
            onClicked: {
                 console.log(recievedText);
                for( var i = 0; i < allText.length; i++){
                    if(allText.length == recievedText.length){
                         templatehandler.completeLayer(allText[i],recievedText[i]);
                    }else {
                        console.log(allText[i]+ " --- "+recievedText[i]);
                    }

                }

                templatehandler.savePDF(saveFileDialog.url);


            }
        }
    }
}
