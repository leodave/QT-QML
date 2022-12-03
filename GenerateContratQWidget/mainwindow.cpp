#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wid = new widget();
    ui->scrollArea->setWidget(wid);

    connect(ui->actionOpen_Folder,SIGNAL(triggered()),this,SLOT(openTemplate()));
    connect(ui->pushButton,SIGNAL(clicked()),SLOT(generatePDF()));
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->scrollArea->resize(width() - 20,
                           height() - (ui->menubar->height()+
                                       ui->statusbar->height() +
                                       ui->pushButton->height()));
    ui->scrollArea->move(10,10);
    ui->pushButton->move(width() - (ui->pushButton->width() + 10),
                         ui->scrollArea->height() + 20);
}

void MainWindow::openTemplate()
{
    QFile templateFile;

    templateFile.setFileName(QFileDialog::getOpenFileName(this,"Open","*.cont"));

    if(templateFile.open(QIODevice::ReadOnly)) {
        QString text(templateFile.readAll());
        templateFile.close();

        templateParts = text.split("###");

        int layerToComplete = 1;

        if(text.startsWith("###")){
            layerToComplete = 0;
        }
        for(;layerToComplete < templateParts.size(); layerToComplete +=2) {

            int layerIndicator = wid->find(templateParts[layerToComplete]);

            if(layerIndicator >= 0){
                layersIndicators[layerIndicator].append(layerToComplete);
            }else {
                wid->addLayer(templateParts[layerToComplete]);

                QVector<int> newVector;
                newVector.append(layerToComplete);
                layersIndicators.append(newVector);
            }
        }
        ui->statusbar->showMessage("Templete uploaded Succesfully", 3000);
    }
    else {
        ui->statusbar->showMessage("Template not Specified", 3000);
    }
}

void MainWindow::generatePDF()
{
    for (int lay = 0; lay < layersIndicators.size(); lay++){
        for( int index = 0; index < layersIndicators[lay].size(); lay++){
            templateParts[layersIndicators[lay][index]] = wid->lineEditAt(lay);
        }
    }
    templateParts.replaceInStrings("\n", "<br>");
    templateParts.replaceInStrings("\r", "<br>");

    QString html = "";

    for(int i = 0; i < templateParts.size(); i++){
        html += templateParts[i];
    }

    QTextDocument document;

    QPrinter filePrinter(QPrinter::HighResolution);
    filePrinter.setOutputFormat(QPrinter::PdfFormat);
    filePrinter.setOutputFileName(
                QFileDialog::getSaveFileName(this,"Export PDF","file:///C:/Users/34722/Desktop","*.pdf"));
    filePrinter.setPageMargins(QMargins(10,20,10,15));

    if(filePrinter.outputFileName().endsWith(".cont")){
        document.setHtml(html);
        document.print(&filePrinter);
        ui->statusbar->showMessage("File expoerted correctly", 3000);

    }else {
        ui->statusbar->showMessage("Specify the File name", 3000);
    }


}

