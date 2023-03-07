import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.LocalStorage 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var db;

    Rectangle {
        id:rectangl
        width:100
        height:100

        color:"purple"
        radius:5

        Text {
            id:recText
            anchors.centerIn: parent
            text: parent.x + "," + parent.y
            font.pointSize: 20
        }

        MouseArea {
            id: recMouse
            anchors.fill:parent
            drag.target: parent
        }


    }
    Component.onCompleted: {
        startDB()
        readPosition()
    }
    Component.onDestruction: {
        savePosition()
    }
    function startDB() {
        db = LocalStorage.openDatabaseSync("C:\\Users\\34722\Documents\\SQLpositions","1.0","DataBase to save position of rectangle",20)
        db.transaction(function(trans) {
           console.log("tble creating")
           trans.executeSql("CREATE TABLE IF NOT EXISTS data(name TEXT, value TEXT)");
        }
            )
    }
    function savePosition(){

        if(!db) {
            return
        }
        db.transaction(function(trans) {
            console.log("saving Data");
            var result = trans.executeSql("SELECT * FROM data where name = 'posRect'");
            var object = {
                    x:rectangl.x,
                    y: rectangl.y
            };
            //{ "x":"400","y":"400"}

            if (result.rows.length === 1) {
                console.log("data updating");
                result = trans.executeSql("UPDATE data set value = ? where name = 'posRect'", [JSON.stringify(object)]);

            }else {
                console.log("no data exist So inserting");
                result = trans.executeSql("INSERT into data VALUES (?,?)",["posRect", JSON.stringify(object)] )
            }
        }
            )
    }
    function readPosition() {
        console.log("reading position")

        if(!db){
            return
        }
        db.transaction(function (trans) {
            console.log("reading from table");
            var result = trans.executeSql("SELECT * from data where name = 'posRect'");
            if(result.rows.length === 1) {
                var valor  = result.rows[0].value;
                var object = JSON.parse(valor);

                rectangl.x = object.x;
                rectangl.y = object.y;
            }
        }
            )
    }

}
