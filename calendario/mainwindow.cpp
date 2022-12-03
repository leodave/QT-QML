#include "mainwindow.h"
#include "ui_mainwindow.h"

#define DIMENSION_DIAS 100
#define PADDING 20

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{
    ui->setupUi(this);

  //  QDate fechaActual = QDate::currentDate();

   // qDebug() << fechaActual.;
    QDate incioDeMes(QDate::currentDate().year(),QDate::currentDate().month(),01);
    QDate finalDeMes(QDate::currentDate().year(),
                     QDate::currentDate().month(),
                     QDate::currentDate().daysInMonth());
    qDebug() << incioDeMes.dayOfWeek();
    incioDeMes = incioDeMes.addDays(-5);
    qDebug() << incioDeMes;
    finalDeMes = finalDeMes.addDays(7 - finalDeMes.dayOfWeek());
    qDebug() << finalDeMes;

    ui->tableWidget->resize(7* DIMENSION_DIAS,
                            ((incioDeMes.daysTo(finalDeMes) +1)/7) * DIMENSION_DIAS);

    resize(ui->tableWidget->width() + 150, ui->tableWidget->height() +  ui->statusbar->height() + 10);
    setMinimumSize(ui->tableWidget->width() + 250, ui->tableWidget->height() +  ui->statusbar->height() + 10);
     setMaximumSize(ui->tableWidget->width() + 250, ui->tableWidget->height() +  ui->statusbar->height() +  10);
     setWindowTitle("Calendario");

    for(int dia = 0; dia < (incioDeMes.daysTo(finalDeMes) + 1); dia ++){
//         graphicRepesentation.append(new QFrame(ui->tableWidget));
//         numerosDias.append(new QLabel(QString::number(incioDeMes.addDays(dia).day()), graphicRepesentation[dia]));
//         graphicRepesentation[dia]->setFrameStyle(QFrame::Box);
//         graphicRepesentation[dia]->resize(DIMENSION_DIAS,DIMENSION_DIAS);
//         graphicRepesentation[dia]->move((dia % 7)*DIMENSION_DIAS,(dia / 7)*DIMENSION_DIAS);
//        qDebug() << incioDeMes.addDays(dia);

        days.append(new diaCalendario(ui->tableWidget));
        connect(days[dia],SIGNAL(diaClickeado(int)),this,
                 SLOT(diaSeleccionado(int)));
//        connect(days[dia], SIGNAL(diaHovered(QVector<QString>,int)),this,
//                SLOT(actualizarLabelEventos(int,int)));
        days[dia]->resize(100,100);
        days[dia]->setFecha(incioDeMes.addDays(dia).day());
        days[dia]->move((dia%7) * DIMENSION_DIAS, (dia/7) * DIMENSION_DIAS);
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::diaSeleccionado(int daySelected)
{
    qDebug() << daySelected;
    dialog.show();

}

void MainWindow::saveEvent(const QVector<QString> &evs, int fecha)
{
    QString texto = QString::number(fecha);

}






//void MainWindow::actualizarLabelEventos(const QVector<QString> &evs, int fecha){
//    QString texto = QString::number(fecha);
//    //eventosLabel->setText(QString::number(fecha) + "")
//            if(evs.size()<0){
//    for( int i = 0; i < evs.size(); i++ ){
//        texto.append("\n" + evs[i]);
//    }
//    }else{
//        texto.append("\n sin texto");
//    }

////    ui->eventosLabel->setTexto(texto);
////     ui->eventosLabel->adjustSize();
//}
