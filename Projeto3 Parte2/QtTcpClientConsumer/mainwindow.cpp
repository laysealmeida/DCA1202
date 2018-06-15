#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QLabel>
#include <QLineEdit>
#include <QDateTime>
#include <QListWidget>
#include <QWidget>
#include <QSlider>
#include <vector>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  idTimer =0;

  connect(ui->pushButtonGet,
          SIGNAL(clicked(bool)),
          this,
          SLOT(getData()));
  connect(ui-> Button_Stop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpConnect());
  connect(ui->Button_Disconnect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpDisconnect()));
  connect(ui->Button_Update,
          SIGNAL(clicked(bool)),
          this,
          SLOT(updateIp()));
}

void MainWindow::tcpConnect(){
  socket->connectToHost(ui->lineEdit_Host->text(), 1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}

void MainWindow::tcpDisconnect(){
    socket->disconnectFromHost();
}


void MainWindow::getData(){
  QString str;
  QByteArray array;
  QStringList list;
  qint64 thetime;
  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      socket->write("get 127.0.0.1 5\r\n");
      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << socket->bytesAvailable();
      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2){
          bool ok;
          str = list.at(0);
          thetime = str.toLongLong(&ok);
          str = list.at(1);
          qDebug() << thetime << ": " << str;
        }
      }
    }
  }
}

void MainWindow::updateIp(void){
    QString str;

    ui->listWidget_ListaDeClients->clear();
    if(socket->state() == QAbstractSocket::ConnectedState){
        socket->write("list\r\n");
        socket->waitForBytesWritten(3000);
        socket->waitForReadyRead();
        while(socket->bytesAvailable()){
            str = socket->readLine().replace("\n","").replace("\r","");
            ui->listWidget_ListaDeClients->addItem(str);
        }
    }
    else{
        ui->listWidget_ListaDeClients->addItem("Não tem nada");
    }

}

void MainWindow::stopData(void){
    if(idTimer){
        killTimer(idTimer);
    }
}


MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
