import QtQuick 2.12
import QtQuick.Window 2.12
import "https://gist.githubusercontent.com/marianocossio/3566cc0346678383335594dd2e0fccc2/raw/506b08a94d9b0e0f449527b6b3cf79963bc67ecb/" as BotonExterna
import QtQuick.LocalStorage 2.12
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var db;

    Rectangle {
        id: agenda

        anchors.fill: parent
        anchors.margins:5
        border.color:"black"
        radius:5
        color:"lightgray"

        Rectangle {
            id:forname
              width: agenda.width/2
               height: 60
              // anchors.margins:5
               //anchors.top:parent.top
               //anchors.left:parent.left
              // anchors.right: parent.right
               border.color:"black"
               radius:5

               //color:"blue"


               MouseArea {
                   id: fornameMouse
                   anchors.fill:parent
                   drag.target: parent
               }

               Text {
                id: labelName
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
               color:"gray"

             }



        }



    Rectangle {
        id:phone
          width: agenda.width
           height: 40
           anchors.margins:5
           anchors.top:forname.bottom
           anchors.left:parent.left
           anchors.right: parent.right
           border.color:"black"
           radius:5
           visible:false;

           Text {
            id: phoneNumber
            text:"phone"
            anchors.top:parent.top
            verticalAlignment: TextInput.AlignVCenter
          //  anchors.margins: 5
            width:parent.width
            height: 20

           }

        TextInput {
           id: phoneInput
           anchors.top: phoneNumber.bottom
           anchors.fill: parent
           anchors.leftMargin: 5
           anchors.topMargin: 20
           verticalAlignment: TextInput.AlignVCenter
            visible:false;

         }

    }



    Rectangle {
        id:adressInfo
          width: agenda.width
           height: 40
           anchors.margins:5
           anchors.top:phone.bottom
           anchors.left:parent.left
           anchors.right: parent.right
           border.color:"black"
           radius:5
           visible: false;

           Text {
            id: adress
            text:"adress"
            anchors.top:parent.top
            verticalAlignment: TextInput.AlignVCenter
            width:parent.width
            height: 20

           }

        TextInput {
           id: adressInput
           anchors.top: adress.bottom
           anchors.fill: parent
           anchors.leftMargin: 5
           anchors.topMargin: 20
           verticalAlignment: TextInput.AlignVCenter
           visible:false;

         }

    }

    BotonExterna.Boton {
        id: readBoton
        texto:"Search"
        anchors.top : adressInfo.bottom
        anchors.topMargin : 30;
        anchors.leftMargin : 20;

        color: "gray"
        onClicked: {
             startDB()
            readPosition();
        }
    }

    BotonExterna.Boton {
        id: saveBoton
        texto:"Save"

        anchors.top: adressInfo.bottom
        anchors.left: readBoton.right
        anchors.topMargin : 30;
        anchors.leftMargin: 15;

        onClicked: {
            startDB()
            savePosition()
        }
    }
    BotonExterna.Boton {
        id: updateBoton
        texto:"Update"

        anchors.top: adressInfo.bottom
        anchors.left: saveBoton.right
        anchors.topMargin : 30;
        anchors.leftMargin: 15;

        onClicked: {
            phone.visible =true
            phoneInput.visible = true
            adressInfo.visible = true
            adressInput.visible = true

        }
    }
    Rectangle {
        anchors.top: saveBoton.bottom


        Text {
            id: resPhone
             text: ""
             font.pixelSize: 30
             font.weight: 100
        }
        Text {
            id: resAdress
             text: ""
             font.pixelSize: 40
             font.weight: 100
             anchors.top: resPhone.bottom
             anchors.topMargin: 10
        }
    }



    }
    Component.onCompleted: {
        startDB()
        positionReader()
    }
    Component.onDestruction: {
        positionSaver()
    }
    function positionSaver(){
        db = LocalStorage.openDatabaseSync("C:\\Users\\34722\Documents\\SQLpositions","1.0","DataBase to save position",20)
        db.transaction(function(trans) {
           console.log("tble creating")
          trans.executeSql("CREATE TABLE IF NOT EXISTS dataPosition(name TEXT, value TEXT)");

        }
            )

        if(!db) {
            return
        }
        db.transaction(function(trans) {
            console.log("saving Data");
             var nombre = name.text
            var result = trans.executeSql("SELECT * FROM dataPosition where name = 'forname'");
            var object = {
                    x:forname.x,
                    y: forname.y
            };
            //{ "x":"400","y":"400"}

            if (result.rows.length === 1) {
                console.log("data updating");
                result = trans.executeSql("UPDATE dataPosition set value = ? where name = 'forname'", [JSON.stringify(object)]);

            }else {
                console.log("no data exist So inserting");
                result = trans.executeSql("INSERT into dataPosition VALUES (?,?)",["forname", JSON.stringify(object)] )
            }
        }
            )
    }
    function positionReader(){
        console.log("reading position")

        if(!db){
            return
        }
        db.transaction(function (trans) {
            console.log("reading from table");
            var result = trans.executeSql("SELECT * from dataPosition where name = 'forname'");
            if(result.rows.length === 1) {
                var valor  = result.rows[0].value;
                var object = JSON.parse(valor);

                forname.x = object.x;
                forname.y = object.y;
            }
        }
            )

    }


    function startDB() {
        db = LocalStorage.openDatabaseSync("C:\\Users\\34722\Documents\\SQLpositions","1.0","DataBase to save name,phone and adress",20)
        db.transaction(function(trans) {
           console.log("tble creating")
          trans.executeSql("CREATE TABLE IF NOT EXISTS data(name TEXT, phone TEXT, adress TEXT)");

        }
            )
    }
    function savePosition(){

        if(!db) {
            return
        }
        db.transaction(function(trans) {
            console.log("saving Data");

            var nombre = name.text
              var result = trans.executeSql("SELECT * FROM data where name = ?",nombre);
           // console.log(result.rows[0].name);
          /* var object = {
                     name : name.text,
                     phone : phoneInput.text,
                     adress : adressInput.text
            };*/
              if (result.rows.length === 1) {
                  console.log("data updating");
                 // result = trans.executeSql("UPDATE data set value = ? where name = ?", [JSON.stringify(object),nombre]);
                result = trans.executeSql("UPDATE data
                                             SET name = ?, phone = ?, adress = ?
                                              WHERE name = ?",[name.text,phoneInput.text,adressInput.text,name.text])
               }else {
            console.log("no data exist So inserting");
            //console.log(object)
           // result = trans.executeSql("INSERT into data VALUES (?,?,?)",[JSON.stringify(object)]);
                  result = trans.executeSql("INSERT INTO data (name, phone, adress)
                                                VALUES (?, ?, ?)", [name.text,phoneInput.text,adressInput.text])
        }
        })
        phone.visible =false
        phoneInput.visible = false
        adressInfo.visible = false
        adressInput.visible = false
        resPhone.text = "";
        resAdress.text = "";


    }
    function readPosition() {
        console.log("reading position")

        if(!db){
            return
        }
        db.transaction(function (trans) {
            console.log("reading from table");
              var nombre = name.text
            var result = trans.executeSql("SELECT * from data where name = ?", nombre);
            if(result.rows.length === 1) {

                //var valor  = result.rows[0].phone;
              //  console.log(valor)
                //var object = JSON.parse(valor);
               // console.log(valor)
                resPhone.text = result.rows[0].phone;
                resAdress.text = result.rows[0].adress;
            }else if(result.rows.length === 0){
                resPhone.text = "Name unknown Please Save it in the form above!!";
                phone.visible =true
                phoneInput.visible = true
                adressInfo.visible = true
                adressInput.visible = true
            }
        }
            )
    }

}
