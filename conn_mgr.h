#ifndef CONN_MGR
#define CONN_MGR

#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <debug_log.h>

class conn_mgr
{

public:
    conn_mgr();

    bool debug;

    void get_usb_info_all();
    bool check_if_device_available();
    bool is_connected();
    bool get_write_success();
    void connect(int baudRate);
    void close();
    QByteArray wait_for_system_serial(int inTime);
    QByteArray wait_for_ms_serial(int inTime, int inPos);
    void write(QByteArray inData);

private:
    bool device_available;
    bool deviced_connected;
    QString device_port_name;
    QSerialPort *device;
    debug_log *dLog;

    const QList<int> vendor_id = QList<int>() << 1027 << 6790 << 9025;
    const QList<int> product_id = QList<int>() << 24577 << 29987 << 67;
    const QList<QString> board_name = QList<QString>() << "Funduino nano" << "Funduino uno" << "Arduino Uno";
    const QList<QString> device_name = QList<QString>() << "MorningstarFX MC6" << "Error" << "Error";

};

#endif // CONN_MGR
