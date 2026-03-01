#include "BluetoothManager.h"
#include <QDebug>

BluetoothManager::BluetoothManager(QObject *parent)
    :QObject (parent)
{
    serial = new QSerialPort(this);

    connect(serial, &QSerialPort::readyRead,
            this, &BluetoothManager::readData);
}

bool BluetoothManager::connectToDevice(const QString &portName)
{
    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if(serial->open(QIODevice::ReadWrite)){
        emit connected(true);
        return true;
    } else{
        connected(false);
        return false;
    }
}

void BluetoothManager::readData()
{
    QByteArray data = serial->readAll();
    emit dataReceived(data);
}

void BluetoothManager::sendData(const QByteArray &data)
{
    if(serial->isOpen())
        serial->write(data);
}
