#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <midi_controller.h>
#include <conn_mgr.h>
#include <QLabel>
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

private slots:
    void on_actionConnect_triggered();

    void on_comboBox_bank_currentIndexChanged(int index);
    void on_comboBox_switch_currentIndexChanged(int index);

    void on_pushButton_save_released();

    void on_pushButton_reset_released();

    void on_actionClose_triggered();

    void on_comboBox_type_currentIndexChanged(int index);

    void on_comboBox_type_2_currentIndexChanged(int index);

    void on_comboBox_type_3_currentIndexChanged(int index);

    void on_comboBox_type_4_currentIndexChanged(int index);

    void on_comboBox_type_5_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    QLabel *statLabel;

    conn_mgr *cm;
    midi_controller *mc;

    bool read_data_from_device();
    bool _load_complete;
    bool _info_received;
    void load_form_details();
    void enable_form(bool inStatus);

    bool _bank_changed;

    const QStringList MIDI_type = (QStringList() << "Empty" << "Program Change" << "Control Change"
                                   << "Strymon Bank Up" << "Strymon Bank Down");
    const QStringList MIDI_type_toggle = (QStringList() << "Empty" << "Program Change" << "Control Change"
                                        << "Strymon Bank Up" << "Strymon Bank Down" << "CC Toggle" << "CC Toggle Hold");

};

#endif // MAINWINDOW_H
