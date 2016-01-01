#ifndef DEBUG_LOG
#define DEBUG_LOG

#include <QTextStream>
#include <QFile>
#include <QCoreApplication>

class debug_log {
public:
    debug_log(bool newFile);
    void writeLog(QString text);
private:

    QString filename;

};

#endif // DEBUG_LOG

