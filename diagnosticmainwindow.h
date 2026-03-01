#ifndef DIAGNOSTICMAINWINDOW_H
#define DIAGNOSTICMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class diagnosticMainWindow; }
QT_END_NAMESPACE

class diagnosticMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    diagnosticMainWindow(QWidget *parent = nullptr);
    ~diagnosticMainWindow();
    bool isConnected = false;

private slots:
    void on_actionExit_triggered();
    void on_ConnectButton_clicked();
    void on_ScanButton_clicked();

private:
    Ui::diagnosticMainWindow *ui;
};
#endif // DIAGNOSTICMAINWINDOW_H
