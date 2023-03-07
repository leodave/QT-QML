import QtQuick 2.12

Item {
    id:calanderContainer
    property alias color:rectangleSelected.color
    property bool monthShown: true;
    width:parent.width
    height:parent.height/7
    property var month: ["January","February","March","April","May","June","July","August","September","October","November","December"]
    property int currentMonth;
    property int year;
    signal dateSelected(int day,int mon, int yea)

    Component.onCompleted: {
        var dateNow = new Date();
        currentMonth = dateNow.getMonth();
        year = dateNow.getFullYear()
        console.log(year)
        populateModel();
       // print(dateNow)

    }

      Rectangle {
        id:rectangleSelected
        //anchors.fill: parent
        width:parent.width
        height:parent.height/7

        Boton {
        id: increase
        texto: ">"
        anchors.right: parent.right
       anchors.verticalCenter: parent.verticalCenter
       anchors.margins: 10
       color:Qt.darker(rectangleSelected.color)
       radius: radius/2
       onClicked: {
           if(monthShown){
               if(currentMonth < 11){
               currentMonth++
               }else {
                   year++
                   currentMonth = 0;
               }
           }else {
               year++
           }
            populateModel();

       }

    }
        Boton {
        id: decrease
        texto:"<"
        anchors.left:parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: 10
        color:Qt.darker(rectangleSelected.color)
         radius: radius/2
         onClicked: {
             if(monthShown) {
                 if(currentMonth > 0){
                 currentMonth--
                 }else{
                     currentMonth = 11;
                     year--
                 }
             }else {
                 year--
             }
            populateModel();

         }

    }
        Rectangle {
            id:recTextMonthYear
            height: parent.height
            color:parent.color

            anchors.right: increase.left
            anchors.left: decrease.right
            anchors.margins: 5
            Text {
               id: textMonthYear
               text:monthShown ? month[currentMonth]: year
               anchors.centerIn: parent
               font.pixelSize: parent.height/3
                }
            Text {
                id:textYear
                text:monthShown ? year: month[currentMonth]
                anchors.left:textMonthYear.right
                anchors.bottom: parent.bottom
                font.pixelSize: parent.height/5
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                       monthShown =! monthShown
                }
            }

        }

    }
      Rectangle {
          id: rectangleCalendar
          color:parent.color
          anchors {
              left: parent.left
              right:parent.right
              bottom:parent.bottom
              top:rectangleSelected.bottom
            }


              GridView {
                  anchors.fill: parent
                  id:listCalander
                  cellWidth: rectangleCalendar.width/7
                  cellHeight: rectangleCalendar.height/6
                  model:42
                  delegate: Rectangle {
                      id:recDelg
                      color:"blue"
                      width: listCalander.cellWidth
                      height: listCalander.cellHeight
                      border.color: Qt.darker("blue");
                   // required property int mode1Data
                    //  required
                      property int index

                      Rectangle {
                        id:recIntero
                        anchors.fill:parent
                        color:"red"
                        anchors.margins: 5

                        Text {
                            id:dateText
                            text:modelData
                           // text:"1"
                            anchors.centerIn: parent
                            color:"yellow"


                        }
                        MouseArea {
                            id:recInternoMouse
                            anchors.fill:parent
                            onClicked: {
                               // print(modelData + "/" + currentMonth+ "/" + year);
                                console.log(index)
                                if(modelData > 15 && index < 6){
                                   calanderContainer.dateSelected(modelData,currentMonth,year);
                                }else if (modelData < 15 && index > 28){
                                    calanderContainer.dateSelected(modelData,currentMonth+2,year);
                                }else{
                                     calanderContainer.dateSelected(modelData,currentMonth+1,year);
                                }


                            }
                        }
                    }
                  }
              }

      }
      function populateModel(){
          var modelLocal = [];
          var fechaLocal = new Date(year,currentMonth,1);
          fechaLocal.setDate(1)
          if(fechaLocal.getDay() > 1){
              fechaLocal.setTime(fechaLocal.getTime()- 24 *3600 *1000 *(fechaLocal.getDay()-1));
          }else if (fechaLocal.getDay() < 1){
              fechaLocal.setTime(fechaLocal.getTime()-24 *3600 *1000*6);
          }
            for(var i = 0; i < 42; i++){
                modelLocal.push(fechaLocal.getDate());
                fechaLocal.setTime(fechaLocal.getTime()+ 24 *3600000);

            }
            listCalander.model = modelLocal

          //print(fechaLocal)
      }
}
