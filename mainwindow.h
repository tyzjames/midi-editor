#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <midi_controller.h>
#include <conn_mgr.h>
#include <QString>
#include <QLabel>
#include <debug_log.h>

//#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void write_to_console(QString text);

private slots:
    void on_actionConnect_triggered();

    void on_comboBox_bank_currentIndexChanged(int index);
    void on_comboBox_switch_currentIndexChanged(int index);

    void on_pushButton_save_released();

    void on_pushButton_reset_released();

    void on_actionClose_triggered();

    void on_actionExpression_Input_triggered();

    void on_comboBox_type_currentIndexChanged(int index);

    void on_comboBox_type_2_currentIndexChanged(int index);

    void on_comboBox_type_3_currentIndexChanged(int index);

    void on_comboBox_type_4_currentIndexChanged(int index);

    void on_comboBox_type_5_currentIndexChanged(int index);

private:
    QLabel *statLabel;

    Ui::MainWindow *ui;
    conn_mgr *cm;
    midi_controller *mc;
    debug_log *dLog;

    bool read_data_from_device();
    bool _load_complete;
    bool _info_received;
    void load_form_details();
    void enable_form(bool inStatus);

    bool _bank_changed;

    const QStringList MIDI_type = (QStringList() << "Empty" << "Program Change" << "Control Change"
                                   << "CC Toggle Value" << "CC Toggle Hold" << "CC Toggle Number"
                                   << "sendNoteOn" << "sendNoteOff" << "Midi Clock"
                                   << "Strymon Bank Up" << "Strymon Bank Down" << "Strymon Scroll Up" << "Strymon Scroll Down");

};

#endif // MAINWINDOW_H
