#include <QDebug>
#include<conn_mgr.h>

conn_mgr::conn_mgr() {

    this->debug = true;

    this->device_available = false;
    this->deviced_connected = false;
    this->device_port_name = "";
    this->device = new QSerialPort;

    this->dLog = new debug_log(false);
}

void conn_mgr::get_usb_info_all(){
   qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();   
   foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
       qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
       if(serialPortInfo.hasVendorIdentifier()){
           qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
       }
       qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
       if(serialPortInfo.hasProductIdentifier()){
           qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
       }
   }
}

bool conn_mgr::check_if_device_available() {
    if (this->debug) {
        this->dLog->writeLog("(conn_mgr) Device available");
        return true;
    } else {
        this->dLog->writeLog(QString("(conn_mgr) NumPorts : %1").arg(QSerialPortInfo::availablePorts().length()));
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            this->dLog->writeLog(QString("(conn_mgr) VendorID/ProductID : %1 / %2").arg(serialPortInfo.vendorIdentifier()).arg(serialPortInfo.productIdentifier()));
             if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
                   if (this->vendor_id.contains(serialPortInfo.vendorIdentifier())) {
                       this->dLog->writeLog(QString("(conn_mgr) VID found "));
                       if (this->product_id.at(this->vendor_id.indexOf(serialPortInfo.vendorIdentifier())) == serialPortInfo.productIdentifier()) {
                           this->dLog->writeLog(QString("(conn_mgr) PID found. Device available. Port Name : %1").arg(serialPortInfo.portName()));
                           this->device_port_name = serialPortInfo.portName();
                           this->device_available = true;
                           return true;
                       }
                   }
            }
        }

    }

    return false;
}

void conn_mgr::connect(int baudRate) {

    if(!this->debug) {
        this->device->setPortName(this->device_port_name);
        this->device->open(QSerialPort::ReadWrite);
        this->device->setBaudRate(baudRate);
        this->device->setDataBits(QSerialPort::Data8);
        this->device->setParity(QSerialPort::NoParity);
        this->device->setStopBits(QSerialPort::OneStop);
        this->device->setFlowControl(QSerialPort::NoFlowControl);
    }

    this->deviced_connected = true;
}

void conn_mgr::close() {

    if (!this->debug) {
        if (this->device->isOpen()) {
            this->device->close();
        }

        // Restart the controller and close connection
        // -------------------------------------------
        this->device->open(QSerialPort::ReadOnly);
        this->device->clear();
        this->device->close();
    }

    this->deviced_connected = false;

    this->dLog->writeLog("(conn_mgr) Closing port");
}

bool conn_mgr::is_connected(){
    return this->deviced_connected;
}

// Checks the system info (first 10 bytes) sent after successful USB connection
//----------------------------------------------------------------------
QByteArray conn_mgr::wait_for_system_serial(int inTime) {

    QByteArray received_data = "";
    qDebug() << "(wait_for_system_serial) Receiving data...";
    this->dLog->writeLog(("(conn_mgr) Receiving system info data"));
    if (this->debug){

        //Generate test data. System information 10 bytes
        //-----------------------------------------------------
        received_data = "1,1,6,5,0,0,0,0,0,0";
        received_data.append("E");

    } else {
        //Check start of serial packet
        //-----------------------------
        bool data_start = false;
        while (this->device->waitForReadyRead(inTime)){
            if (!data_start) {

                // Start of serial
                //-----------------------
                if (this->device->read(1) == "^")
                {
                   qDebug() << "First byte received. Byte received: ^" ;
                   this->dLog->writeLog("(conn_mgr) First byte received");
                   data_start = true;
                } else {
                    this->dLog->writeLog("(conn_mgr) First byte error");
                }
            } else {
                received_data.append(this->device->readAll());
            }
        }
    }

    this->dLog->writeLog(QString("(conn_mgr) Received data: %1").arg(QString(received_data)));

    return received_data;
}

// Gets the midi structure data.
// inTime = Time to wait for serial data
// inPos = Position of data packet in memory
//----------------------------------------------------------------------
QByteArray conn_mgr::wait_for_ms_serial(int inTime, int inPos) {

    QByteArray received_data = "";
    this->dLog->writeLog(QString("(conn_mgr) Receiving MS data for POS %1").arg(inPos));
    qDebug() << "(wait_for_ms_serial) Receiving ms serial data...";
    qDebug() << "Memory position requested: " << inPos;
    if (this->debug){
        //Generate test data. MS 29 bytes. First byte in is memory position.
        //--------------------------------------------------------------------
        received_data = "1,1,2,3,4,5,2,7,8,9,10,3,12,13,14,15,4,17,18,19,20,5,22,23,24,25,60,60,60,60";
        received_data.append("E");

    } else {
        //Request MS data by position
        //-------------------------------------------------
        QByteArray data_to_send = "<S" + QByteArray::number(inPos) + "E";
        this->device->write(data_to_send);

        qDebug() << "Sending data to Controller: " << data_to_send;
        this->dLog->writeLog(QString("(conn_mgr) Requesting MS data : %1").arg(QString(data_to_send)));

        //Check start of serial packet.
        //--------------------------------------------------
        bool data_start = false;
        while (this->device->waitForReadyRead(inTime)){
            qDebug() << "Waiting for MS serial...";
            if (!data_start) {
                // Start of serial for midi structure. First number is memory position.
                //----------------------------------------------------------------------
                if (this->device->read(1) == "<")
                {
                   qDebug() << "First byte received. Byte received: <";
                   data_start = true;
                }
            }

            if (data_start) {
                received_data.append(this->device->readAll());
            }
        }
    }

    qDebug() << "Received MS data: " << received_data;
    return received_data;
}

bool conn_mgr::get_write_success() {

    if (this->debug) {
        return true;
    } else {
        QString received_data = "";
        while (this->device->waitForReadyRead(3000)){
            received_data = this->device->readAll();
            qDebug() << "Ack received: " << received_data;
            if (received_data.contains("^")) //If "^" is received, start of command
            {
               qDebug() << "Write success";
               return true;
            }
        }
        qDebug() << "Received data: " << received_data;
    }

    qDebug() << "Write failed";
    return false;
}

void conn_mgr::write(QByteArray inData) {
    if (!this->debug) {
        this->device->write(inData);
    }
}
