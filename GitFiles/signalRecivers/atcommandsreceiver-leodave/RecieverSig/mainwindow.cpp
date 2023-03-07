#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {background-color: #33ACFF}");
    ui->ATCURR->hide();
    ui->ATMAX->hide();
    ui->ATMIN->hide();
    ui->ATSIGNALS->hide();
    ui->ATSTART->hide();
    ui->ATSTOP->hide();
    ui->COM1->hide();
    ui->COM2->hide();

    openGl.setParent(this);
    connect(&fileReciever,SIGNAL(dataReciever(QString)),this,SLOT(recievedData(QString)));
    connect(this,SIGNAL(arraySent(QList<QString>)),this,SLOT(generateButtons(QList<QString>)));


   /* for( int i = 0; i < 10; i++){
        groupButton.append(new Button(ui->widget_2));
        groupButton[i]->setButtonName("hello");
        groupButton[i]->resize(100,50);
        groupButton[i]->move(10,i*30);
        ui->widget_2->setFixedHeight(i * 30);
        qDebug() << groupButton;
        //.setButtonName(newData[i]));


                    // days[dia]->move((dia%7) * DIMENSION_DIAS, (dia/7) * DIMENSION_DIAS);)


       // button.setButtonName(newData[i]);
        //button.setButtonSize(100,50);
        //button.move(10,100)
    }*/
    //button.setParent(this);
   /* button.setText("AT+SIGNALS=?");
    button.adjustSize();
    button.setMinimumHeight(50);
    button.setMinimumWidth(100);
    button.move(10,500);*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateButtons(QList<QString> datas)
{

    for( int i = 0; i < newData.length(); i++){
       // qDebug() << "rightt";
            groupButton.append(new Button(ui->widget_2));
            groupButton[i]->setButtonName(newData[i]);
            groupButton[i]->resize(ui->widget_2->width(),ui->widget_2->height());
            groupButton[i]->move(10,(10)+i*50);
            ui->widget_2->setFixedHeight(i * 50);
            groupButton[i]->show();
            //ui->widget_2->setFixedWidth(200);
           connect(groupButton[i],SIGNAL(onClicked(QString)),this,SLOT(buttonNameReciever(QString)));


            //groupButton[i].
    }

}

void MainWindow::buttonNameReciever(QString name)
{
   // qDebug() << name;
    fileReciever.mixMaxStopTypes(name);
}
void MainWindow::resizeEvent(QResizeEvent *event)
{
    openGl.resize(width() - (ui->widget_2->width() + ui->ATSIGNALS->width()+ 50),height() - 100);
    openGl.move(5,5);
   // button.resize(ui->widget_2->width(),height());
   // button.move(openGl.width()+ 10,10);
    ui->widget_2->move(openGl.width() +10,10);
    ui->OpenPort->move(20,openGl.height()+10);
    ui->ATSIGNALS->move(ui->OpenPort->width()+ 40,openGl.height()+10);
    ui->ATSTART->move(ui->OpenPort->width()+ ui->ATSIGNALS->width()+60,openGl.height()+10);
    ui->ATSTOP->move(ui->OpenPort->width()+ ui->ATSIGNALS->width()+ui->ATSTART->width()+80,openGl.height()+10);
    ui->ATCURR->move(openGl.width()+20,openGl.height()-50);
    ui->ATMAX->move(ui->ATCURR->x(),ui->ATCURR->y()-50);
    ui->ATMIN->move(ui->ATMAX->x(),ui->ATMAX->y()-50);
    ui->COM2->move(ui->ATMIN->x(),ui->ATMIN->y()-50);
    ui->COM1->move(ui->COM2->x(),ui->COM2->y()-50);
   // resize(openGl.width()+ui->widget_2->width(),openGl.height()+ui->OpenPort->height()+30);


}

void MainWindow::recievedData(QString data)
{

         newData = data.split("\r\n");

        // qDebug() <<  newData;
         emit arraySent(newData);


    for(int i = 0; i < newData.length(); i++){
        if(newData[i].contains("AT+VALUE=")){
           // newestData.append(newData[i].split("AT+VALUE=")[1]);
            newestData2.append(newData[i].split("AT+VALUE=")[1].toFloat());
            //openGl.newestData3.append(newData[i].split("AT+VALUE=")[1].toFloat());
        }


    }
   //qDebug() << data;
   // newData.pop_back();
   // qDebug() << newestData;
    // qDebug() << newestData2;

    //emit dataSent(newestData2);
    openGl.recievedNewData(newestData2);

    //openGL
   // int blue = data.toInt();
    //qDebug() << blue;


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}




void MainWindow::on_OpenPort_clicked()
{
    ui->COM1->show();
    ui->COM2->show();

}


void MainWindow::on_ATSIGNALS_clicked()
{
    fileReciever.clickReciever("AT+SIGNALS=?");


}

void MainWindow::on_ATSTART_clicked()
{
    fileReciever.clickReciever("AT+START");
}


void MainWindow::on_ATSTOP_clicked()
{
  fileReciever.clickReciever("AT+STOP");
}


void MainWindow::on_ATMAX_clicked()
{
   fileReciever.clickReciever("AT+MAX");
}


void MainWindow::on_ATMIN_clicked()
{
    fileReciever.clickReciever("AT+MIN");
}


void MainWindow::on_ATCURR_clicked()
{
    fileReciever.clickReciever("AT+CURR");
}


void MainWindow::on_COM1_clicked()
{
    fileReciever.start("COM1",QSerialPort::Baud115200);
    ui->ATCURR->show();
    ui->ATMAX->show();
    ui->ATMIN->show();
    ui->ATSIGNALS->show();
    ui->ATSTART->show();
    ui->ATSTOP->show();

    ui->COM1->hide();
    ui->COM2->hide();
}


void MainWindow::on_COM2_clicked()
{
    fileReciever.start("COM2",QSerialPort::Baud115200);
    ui->ATCURR->show();
    ui->ATMAX->show();
    ui->ATMIN->show();
    ui->ATSIGNALS->show();
    ui->ATSTART->show();
    ui->ATSTOP->show();

    ui->COM1->hide();
    ui->COM2->hide();
}

