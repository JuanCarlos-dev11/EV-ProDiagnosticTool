#include "diagnosticmainwindow.h"
#include "./ui_diagnosticmainwindow.h"

diagnosticMainWindow::diagnosticMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::diagnosticMainWindow)
{
    ui->setupUi(this);
    setWindowTitle("EV Pro Diagnostics Tool");

    connect(ui->ConnectButton, &QPushButton::clicked, this, &diagnosticMainWindow::on_ConnectButton_clicked);
    connect(ui->ScanButton, &QPushButton::clicked, this, &diagnosticMainWindow::on_ScanButton_clicked);

    ui->ledStatus->setFixedSize(14,14);
    ui->ledStatus->setStyleSheet(
        "background-color: red;"
        "border-radius: 7px;");
    ui->ScanButton->setEnabled(false);
}

diagnosticMainWindow::~diagnosticMainWindow()
{
    delete ui;
}

void diagnosticMainWindow::on_actionExit_triggered()
{
    close();
}

void diagnosticMainWindow::on_ConnectButton_clicked()
{
    ui->statusbar->showMessage(tr("Trying to connect..."));
    ui->ConnectButton->setEnabled(false);

    //Simulación temporal
    ui->ConnectButton->setText(tr("Connect"));
    ui->ledStatus->setStyleSheet(
        "background-color: green;"
        "border-radius: 7px;");
}

void diagnosticMainWindow::on_ScanButton_clicked()
{
    if(isConnected == true){
        ui->ScanButton->setEnabled(true);
    }else{
        ui->ScanButton->setEnabled(false);
    }
}
