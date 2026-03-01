#ifndef BLUETOOTHMANAGER_H
#define BLUETOOTHMANAGER_H

#include <QObject>
#include <QSerialPort>

class BluetoothManager : public QObject
{
    Q_OBJECT

public:
    explicit BluetoothManager(QObject *parent = nullptr);
    bool connectToDevice(const QString &portName);
    void disconnectDevice();
    void sendData(const QByteArray &data);

signals:
    void dataReceived(const QByteArray &data);
    void connected(bool estado);

private slots:
    void readData();

private:
    QSerialPort *serial;
};

#endif // BLUETOOTHMANAGER_H
