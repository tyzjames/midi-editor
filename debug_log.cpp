#include <debug_log.h>
#include <QDateTime>
#include <QDir>

debug_log::debug_log(bool newFile) {

    if (!QDir("logfile").exists()) {
        QDir().mkdir("logfile");
    }

    this->filename = "logfile/data_log.txt";

    if (newFile) {
        QFile logFile(filename);
        if (logFile.exists()) {
            logFile.open(QFile::WriteOnly | QFile::Truncate);
        }

        logFile.close();

        this->writeLog("Creating log file...");
    };
}

void debug_log::writeLog(QString text) {
   QFile logFile(filename);
   logFile.open(QFile::WriteOnly | QFile::Text | QFile::Append);
   QTextStream out(&logFile);
   out << QDateTime::currentDateTime().toString() << " : " << text << "\n";
   logFile.close();

}
