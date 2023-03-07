import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    StackView {
        id: stackView
        anchors.fill:parent
        initialItem: firstPage;
    }

    Component {
        id: firstPage

        Rectangle {
            Text {
                id:name;
                text: "First Page"
            }
            Button {
                id:btn1
                anchors.centerIn: parent;
                text: "Second Page"

                onClicked: {
                    stackView.push(secondPage);
                }

            }
        }
    }
    Component {

        id: secondPage

        Rectangle {
            Text {
                id:name2;
                text: "Second Page"
            }
            Button {
                id:btn2
               anchors.centerIn: parent;
                text: "First Page"

                onClicked: {
                    stackView.pop();
                }

            }
            Button {
                id:btn3
               anchors.left: btn2.right;
                text: "next Page"

                onClicked: {
                    stackView.push(thirdPage);
                }

            }
        }
    }

    Component {

        id: thirdPage

        Rectangle {
            Text {
                id:name3;
                text: "Third Page"
            }
            Button {
                id:btn3
               anchors.centerIn: parent;
                text: "Last Page"

                onClicked: {
                    stackView.pop();
                }

            }
        }
    }

}
