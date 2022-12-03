import QtQuick 2.12
import QtQuick.Window 2.12
import "https://gist.githubusercontent.com/marianocossio/3566cc0346678383335594dd2e0fccc2/raw/506b08a94d9b0e0f449527b6b3cf79963bc67ecb/" as BotonExterna
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: mark
        anchors.fill:parent
        //        Image {
        //            id:image
        //            source: "quick5/images/rocket.png"
        //            anchors.centerIn: parent
        //            fillMode: Image.PreserveAspectFit
        //        }
//        Loader {
//            id: elementExternal
//            source: "https://gist.github.com/marianocossio/3566cc0346678383335594dd2e0fccc2"
//             anchors.centerIn: parent
//        }
//        BotonExterna.Boton {
//            id:boton
//            texto:"salir"
//            onClicked: {
//                Qt.quit()
//            }
//        }
        ListView {
            id: list
            spacing: 5
            clip:true
            anchors.fill:parent
            delegate: Rectangle {
                width: 300
                height: 200
                anchors.horizontalCenter:  parent.horizontalCenter
                border.width: 2
                border.color: "gray"
               // color:"gray"

                Image {
                    id :birdImage
                    source: modelData.link
                    anchors.fill: parent
                    anchors.margins:  20
                    fillMode: Image.PreserveAspectFit
                }
                Text {
                    id: birdText
                    anchors.top : birdImage.bottom
                   // anchors.topMargin:  5;
                    text:modelData.title;
                    font.pixelSize: 15
                    anchors.horizontalCenter:  parent.horizontalCenter

                }
            }




        }

        Component.onCompleted: {
            add();
           // console.log(objectJson.title);
        }

        function add() {
            var httpRequest = new XMLHttpRequest();

            httpRequest.onreadystatechange = function () {

                if(httpRequest.readyState === httpRequest.HEADERS_RECEIVED ){

                    console.log("header recieved");

                }else if (httpRequest.readyState === httpRequest.DONE) {

                    var objectJson = JSON.parse(httpRequest.responseText.toString());

                    console.log("hello")

                    console.log(httpRequest.responseText);

                    list.model = objectJson.items;
                }
            }

            httpRequest.open("GET","https://gist.githubusercontent.com/marianocossio/9ac38eae535b5734811bff1df7922b01/raw/94ad54e689623f3c65cc8e0fc162287642550eaf")
            httpRequest.send();

        }
    }
}
