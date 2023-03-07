import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls
import QtQuick.LocalStorage 2.12
import QtQuick.Dialogs
import QtQuick.Shapes

Window {
    id:window
    width: 400
    height: 600
    visible: true
    title: qsTr("Hello World")
    property var db;
    property var namePersonal;
    property var passwordPersonal;
    property var photoPersonal;
    property list<string> productName;
    property list<int> productPrice;



    StackView {
        id: stackView
        anchors.fill:parent
        initialItem: firstPage;

    }

    Component {
        id: firstPage
        Rectangle {

            id: nameAndPassword
            color:"lightblue"


            LabelAndInput {
                id:nameInp
                label: "Name";
                anchors.horizontalCenter: parent.horizontalCenter;
                input:""
            }
            LabelAndInput {
                id:password
                label: "Password"
                anchors.top: nameInp.bottom
                anchors.horizontalCenter: parent.horizontalCenter;
                input:""
                inputecho: TextInput.Password
            }

            Row {
                spacing:20
                anchors.top: password.bottom;
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.topMargin: 50

                Boton {
                    id:newUser
                    btnTexter: "New User"
                    onClicked:  {
                        stackView.push(secondPage);
                    }
                }
                Boton {
                    id:logIn
                    btnTexter: "LogIn"
                   onClicked:  {
                       startDB();
                       dataReader(nameInp.input,password.input);
                       productReader()


                    }
                }

          }

     }
 }
    Component {

        id: secondPage

        Rectangle {

            id: addNew
            color:"lightblue"


            LabelAndInput {
                id:nameInputNew
                label: "Name";
                anchors.horizontalCenter: parent.horizontalCenter;
                input:""
            }
            LabelAndInput {
                id:passwordNew
                label: "Password"
                anchors.top: nameInputNew.bottom
                anchors.horizontalCenter: parent.horizontalCenter;
                input:""
                inputecho: TextInput.Password
            }

            LabelAndInput {
                id:repPassword
                label: "Repeat Password"
                anchors.top: passwordNew.bottom
                anchors.horizontalCenter: parent.horizontalCenter;
                input:""
                inputecho: TextInput.Password
            }

            FileDialog {
                id: imageDialog;

           }
            Row {
                id: imgRow
                spacing: 10
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 20;
                anchors.top: repPassword.bottom;

                Rectangle {
                    id: imageRec
                    height: 120
                    width:150
                    radius:200

                    color: "blue"

                    Image {
                        id: imageInsert
                        anchors.fill: parent

                        source: imageDialog.selectedFile;
                    }
                    Shape {

                    }

                }
                Boton {
                    id:btnImage
                    btnTexter: "Select Image"
                    onClicked:  {

                            imageDialog.open();

                        }
                }
            }



            Row {
                spacing:20
                anchors.top: imgRow.bottom;
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.topMargin: 30

                Boton {
                    id:cancel
                    btnTexter: "Cancel"
                    onClicked:  {
                        stackView.push(firstPage);
                    }
                }
                Boton {
                    id:accep
                    btnTexter: "Accept"
                   onClicked:  {
                        startDB();
                       saveData(nameInputNew.input,passwordNew.input,repPassword.input,nameInputNew.input + ".png");
                       imageInsert.grabToImage
                               ((result)=> {
                                           result.saveToFile(nameInputNew.input +".png");
                                   }
                                );
                       stackView.push(firstPage);
                       dialoglogin.open();
                    }
                }
            }

        }
    }
    Dialog {

        id:dialogLogin
        width:400
        height:400
        anchors.centerIn: parent
        Rectangle {
            id: recDialog
            anchors.fill: parent;
            color:"gray";

            Text {
                color:"black"
                id:nameText
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                text:""
                anchors.topMargin: 80
                font.bold: true;
                font.pixelSize: 50;

            }
            Text {

                id:passwordText
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: nameText.bottom
                font.bold: true;
                font.pixelSize: 25;
                text:""
            }

            Boton {
                id:close
                btnTexter: "Close"
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                anchors.margins: 10

                onClicked:  {
                    dialogLogin.close();
                }
            }

        }
    }

    Component {
        id:thirdPage
        Rectangle {
            id: userProfile
            color:"lightblue"


            ComboBox {
                id:comboProduct;
                editable: false

                width: 200;
                height: 30;
                anchors.left: parent.left
                anchors.leftMargin: 30;
                anchors.top: parent.top;
                anchors.topMargin:80;

                model:productName
               onActivated: (index) => {
                    console.log(index);
                                           }

            }

            SpinBox {
                id:spinProduct
                value: 0;
                anchors.left:comboProduct.right
                anchors.leftMargin: 20;
                anchors.top: parent.top;
                anchors.topMargin:80;
                height:30

            }

            Boton {
                id:sellBtn
                btnTexter: "Sell"
                anchors.top:comboProduct.bottom
                anchors.topMargin:30;
                anchors.horizontalCenter:parent.horizontalCenter;
                onClicked: {

                   sellItem(comboProduct.currentValue,spinProduct.value)
                }

            }



            Drawer {
                id:profileDrawer
                width:170
                height: window.height

               Rectangle {
                   id: drawerRec;
                   anchors.fill:parent;
                   color:"blue"

                   Rectangle {
                       id: proPic;
                       height: 120
                       width:150
                       anchors.top: parent.top
                       anchors.left: parent.left
                       anchors.leftMargin: 10;
                       anchors.topMargin: 50;

                       color: "lightblue"

                       Image {
                           id: imageproPic
                           anchors.fill: parent
                           fillMode: Image.PreserveAspectFit;
                           source:"/../build-UserSaverQml1-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/" + photoPersonal;
                       }

                   }
                   Text {
                       id: personalName
                       anchors.top: proPic.bottom;
                       anchors.left: parent.left
                       anchors.margins: 20
                       text:namePersonal;
                       font.bold: true;
                       font.pixelSize: 20;
                       color:"white";
                   }
                   Boton {
                       id: changePasswordbtn
                       anchors.bottom:exitBtn.top;
                       width:130
                       btnColor: "lightgreen";
                       btnTexter: "Change Password";
                       anchors.margins: 20;
                       anchors.left: parent.left
                   }
                   Boton {
                       id: exitBtn
                       anchors.bottom:parent.bottom;
                       btnColor: "red";
                       btnTexter: "Exit";
                       width:130;
                       anchors.margins: 20;
                       anchors.left: parent.left

                       onClicked: {
                           profileDrawer.close();
                           namePersonal ="";
                           passwordPersonal = "";
                           photoPersonal = "";
                           stackView.push(firstPage);

                       }
                   }
               }

            }
        }
    }


    function startDB() {
        db = LocalStorage.openDatabaseSync("C:\\Users\\34722\Documents\\SQLpositions","1.0","DataBase to save name and password",20)
        db.transaction(function(trans) {
           console.log("tble creating")
          trans.executeSql("CREATE TABLE IF NOT EXISTS data(name TEXT,password TEXT,image TEXT)");
          trans.executeSql("CREATE TABLE IF NOT EXISTS products(name TEXT,price int)");
         trans.executeSql("CREATE TABLE IF NOT EXISTS solditems(seller TEXT,productName Text,Quantity Int)");

           /* trans.executeSql("Insert into products values ('Coke',2)");
            trans.executeSql("Insert into products values ('Fanta',2)");
            trans.executeSql("Insert into products values ('Tea',1)");
            trans.executeSql("Insert into products values ('Coffee',3)");
            trans.executeSql("Insert into products values ('Sandwich',5)");*/

        }
            )
    }
    function saveData(namer,passworder,repPassworder, image){
        if(!db) {
            return
        }
        if(namer!== "" && passworder !== "" && repPassworder !== "" && image !== ""){
            db.transaction(function(trans) {
                console.log("saving Data");


                  var result = trans.executeSql("SELECT * FROM data where name = ?",namer);

                if(passworder === repPassworder){

                    if (result.rows.length === 1) {
                        console.log("data already exists");
                        nameText.text = "Data Already \nExists";
                       }else {
                         console.log("no data exist So inserting");
                        result = trans.executeSql("INSERT INTO data (name,password,image)
                                                      VALUES (?, ?, ?)", [namer,repPassworder,image]);

                       nameText.text = "new Data \nCreated";


                    }
                }else if(passworder !== repPassworder){
                    console.log("Password do not match");
                    nameText.text = "Password do not match!!!";
                }



            })
        }
        else {
           nameText.text = "Insert Data";
        }
        dialogLogin.open();


    }

   function dataReader(naming,passwording){
        console.log("reading data")
       nameText.text = "no way"

       if(!db){
           return
       }

       if(naming !== "" && passwording !== ""){
           db.transaction(function (trans) {
               console.log("reading from table");


             var result = trans.executeSql("SELECT * from data where name = ?", naming);

               if(result.rows.length === 1) {

                  if(passwording === result.rows[0].password){

                     // nameText.text = result.rows[0].name;
                      namePersonal = result.rows[0].name;
                     // passwordText.text = result.rows[0].password
                      passwordPersonal = result.rows[0].password
                      //console.log((result.rows[0].image));
                      photoPersonal = result.rows[0].image;
                      stackView.push(thirdPage);
                   }else {
                       console.log("password Dont Match");
                      nameText.text = "Incorrect \nPasswords \nOr Name"
                      dialogLogin.open();
                   }

               }
               else if(result.rows.length === 0){

                   nameText.text = "User Does \nnot Exist ";
                   dialogLogin.open();
               }
           });
       }else {
           nameText.text = "Empty user \n or password";
           dialogLogin.open();
       }

   }

   function productReader() {
       console.log("reading Products");
       if(!db){
           return
       }

       db.transaction(function (trans) {
           console.log("reading from table");

            var result = trans.executeSql("SELECT * from products");
                //console.log(result.rows.length);

                for(var i= 0; i < result.rows.length; i++){
                  productName.push(result.rows[i].name);
                    productPrice.push(result.rows[i].price);
                }
                ;

       })
   }

   function sellItem(sellerNamee,quantity){
       console.log("sellingItem")
       if(!db){
           return
       }
       db.transaction(function (trans) {

          var result = trans.executeSql("INSERT INTO solditems (seller,productName,Quantity)
                                         VALUES (?, ?, ?)", [namePersonal,sellerNamee,quantity]);
           console.log("Product Sold");

       })
   }


}
