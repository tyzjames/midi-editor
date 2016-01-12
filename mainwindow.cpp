#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_Expression.h"

#include <QtCore>
#include <midi_controller.h>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create debug log file
    //-----------------------
    this->dLog = new debug_log(true);

    // Status label
    //----------------------
    this->statLabel = new QLabel(this);
    ui->statusBar->addPermanentWidget(statLabel,1);

    this->mc = new midi_controller();
    this->cm = new conn_mgr();    

    this->_load_complete = false;
    this->_info_received = false;

    // First Switch, Add toggle function
    //-------------------------------------------
    this->ui->comboBox_type->addItems(this->MIDI_type);
    this->ui->comboBox_type_2->addItems(this->MIDI_type);
    this->ui->comboBox_type_3->addItems(this->MIDI_type);
    this->ui->comboBox_type_4->addItems(this->MIDI_type);
    this->ui->comboBox_type_5->addItems(this->MIDI_type);

    this->enable_form(false);
    this->_load_complete = true;
}

MainWindow::~MainWindow()
{
    this->cm->close();
    delete ui;
}

void MainWindow::enable_form(bool inStatus) {
    if (!inStatus) {
        this->ui->groupBox_presetDetails->setEnabled(false);
        this->ui->groupBox_midi->setEnabled(false);
        this->ui->groupBox_midi_2->setEnabled(false);
        this->ui->groupBox_midi_3->setEnabled(false);
        this->ui->groupBox_midi_4->setEnabled(false);
        this->ui->groupBox_midi_5->setEnabled(false);
        this->ui->pushButton_reset->setEnabled(false);
        this->ui->pushButton_save->setEnabled(false);
    } else {
        this->ui->groupBox_presetDetails->setEnabled(true);
        this->ui->groupBox_midi->setEnabled(true);
        this->ui->groupBox_midi_2->setEnabled(true);
        this->ui->groupBox_midi_3->setEnabled(true);
        this->ui->groupBox_midi_4->setEnabled(true);
        this->ui->groupBox_midi_5->setEnabled(true);
        this->ui->pushButton_reset->setEnabled(true);
        this->ui->pushButton_save->setEnabled(true);
    }
}

void MainWindow::load_form_details() {

    int switch_number = ui->comboBox_switch->currentIndex();
    int bank_number = ui->comboBox_bank->currentIndex();

    if (switch_number >= 0 && bank_number >= 0) {
        midi_structure *temp_ms = this->mc->ms;
        this->ui->lineEdit_shortName->setText(temp_ms->get_patch_name_short());

        this->ui->comboBox_type->setCurrentIndex(temp_ms->_mb1->get_type());
        this->ui->comboBox_type_2->setCurrentIndex(temp_ms->_mb2->get_type());
        this->ui->comboBox_type_3->setCurrentIndex(temp_ms->_mb3->get_type());
        this->ui->comboBox_type_4->setCurrentIndex(temp_ms->_mb4->get_type());
        this->ui->comboBox_type_5->setCurrentIndex(temp_ms->_mb5->get_type());

        this->ui->spinBox_num->setValue(temp_ms->_mb1->get_num());
        this->ui->spinBox_num_2->setValue(temp_ms->_mb2->get_num());
        this->ui->spinBox_num_3->setValue(temp_ms->_mb3->get_num());
        this->ui->spinBox_num_4->setValue(temp_ms->_mb4->get_num());
        this->ui->spinBox_num_5->setValue(temp_ms->_mb5->get_num());

        this->ui->spinBox_val->setValue(temp_ms->_mb1->get_val());
        this->ui->spinBox_val_2->setValue(temp_ms->_mb2->get_val());
        this->ui->spinBox_val_3->setValue(temp_ms->_mb3->get_val());
        this->ui->spinBox_val_4->setValue(temp_ms->_mb4->get_val());
        this->ui->spinBox_val_5->setValue(temp_ms->_mb5->get_val());

        this->ui->spinBox_val_max->setValue(temp_ms->_mb1->get_val_max());
        this->ui->spinBox_val_max_2->setValue(temp_ms->_mb2->get_val_max());
        this->ui->spinBox_val_max_3->setValue(temp_ms->_mb3->get_val_max());
        this->ui->spinBox_val_max_4->setValue(temp_ms->_mb4->get_val_max());
        this->ui->spinBox_val_max_5->setValue(temp_ms->_mb5->get_val_max());

        this->ui->spinBox_channel->setValue(temp_ms->_mb1->get_channel());
        this->ui->spinBox_channel_2->setValue(temp_ms->_mb2->get_channel());
        this->ui->spinBox_channel_3->setValue(temp_ms->_mb3->get_channel());
        this->ui->spinBox_channel_4->setValue(temp_ms->_mb4->get_channel());
        this->ui->spinBox_channel_5->setValue(temp_ms->_mb5->get_channel());

    }

    qDebug() << "(load_form_details) Load form details complete!";
}

void MainWindow::on_actionConnect_triggered()
{
    this->dLog->writeLog("Connecting to device");

    // If devices is not connected
    //------------------------------------------------
    if (!cm->is_connected()) {
        this->cm->get_usb_info_all();

        // Check if device is connect in USB port. Connect if so.
        //---------------------------------------------------------
        if (cm->check_if_device_available()) {
            qDebug() << "(on_actionConnect_triggered) Device is available. Connecting now.";

            cm->connect(QSerialPort::Baud9600); //Works with Nano

        } else {
            QMessageBox::warning(this, "Connection error", "Device not found! Please ensure that the controller is connected to your PC/Mac via USB.");
            this->statLabel->setText("Status: Device not found");
        }

        // If device is connected
        //--------------------------------------------------------
        if (cm->is_connected()) {

            this->cm->write(">S0EC0V");
            QByteArray received_data = cm->wait_for_system_serial(2000);

            qDebug() << "Received data: " << received_data;
            // Check if device is sending data
            //---------------------------------------------------
            if (received_data.isEmpty() || received_data.isNull()) {
                QMessageBox::warning(this, "Device error", "No data received! Please ensure your device is connected.");
                this->cm->close();
            } else {
                qDebug() << "(on_actionConnect_triggered) received data: " << received_data;

                // Process the received system info data. If successful, return true
                //----------------------------------------------------------------
                if (mc->process_info_data(received_data)) {

                    qDebug() << "(on_actionClose_triggered) process_info_data correct";

                    // Adjust all the object specs
                    //------------------------------------------
                    this->_info_received = false;
                    this->ui->lineEdit_shortName->setMaxLength(this->mc->get_patch_name_size());
                    this->ui->comboBox_bank->clear();
                    this->ui->comboBox_switch->clear();
                    this->ui->comboBox_bank->addItems(mc->get_bank_str_list());
                    this->ui->comboBox_switch->addItems(mc->get_switch_str_list());
                    this->ui->comboBox_bank->setCurrentIndex(0);
                    this->ui->comboBox_switch->setCurrentIndex(0);
                    this->_info_received = true;

                    this->statLabel->setText("Status: <font color = 'green'>Connected</font>");
                    ui->actionConnect->setText("Disconnect");
                    this->enable_form(true);

                    // Once system info received, get first MS data.
                    //---------------------------------------------------
                    int switch_number = ui->comboBox_switch->currentIndex();
                    int bank_number = ui->comboBox_bank->currentIndex();

                    qDebug() << "(on_actionConnect_triggered) Retrieving first MS data... Bank: " << bank_number << " Switch: " << switch_number;

                    QByteArray ms_received_data = cm->wait_for_ms_serial(800, this->mc->get_memory_position(0, 0));
                    if (mc->process_ms_data(ms_received_data)) {
                        this->load_form_details();
                    } else {
                        QMessageBox::warning(this, "Data error", "Midi Serial Data Error. Data not in sync!");
                        ui->actionConnect->setText("Connect");
                        this->ui->actionTest_Mode->setEnabled(true);
                        this->enable_form(false);
                        this->statLabel->setText("Status: Data Error");
                        this->cm->close();
                    }


                } else {
                    QMessageBox::warning(this, "Data error", "System Info Data Error. Data not in sync!");
                    this->statLabel->setText("Status: No data received");
                }
            }

        }
    } else {
        qDebug() << "Disconnecting";
        ui->actionConnect->setText("Connect");
        this->enable_form(false);
        this->statLabel->setText("Status: <font color = 'red'>Not Connected</font>");
        this->ui->actionTest_Mode->setEnabled(true);
        this->cm->close();
    }
}


void MainWindow::on_comboBox_bank_currentIndexChanged(int index)
{
    if (this->_load_complete && _info_received) {
        this->_bank_changed = true;
        this->ui->comboBox_switch->setCurrentIndex(0);

        // Request data from the controller based on memory position
        //-------------------------------------------------------------
        QByteArray ms_received_data = this->cm->wait_for_ms_serial(800, this->mc->get_memory_position(this->ui->comboBox_bank->currentIndex(), this->ui->comboBox_switch->currentIndex()));
        if (mc->process_ms_data(ms_received_data)) {
            this->load_form_details();
        } else {
            QMessageBox::warning(this, "Transmission error", "Wrong data received! CheckSum wrong.");
        }
        this->statLabel->setText("Status: <font color = 'black'>Connected</font>");
        this->_bank_changed = false;
    }
}

void MainWindow::on_comboBox_switch_currentIndexChanged(int index)
{
    if (this->_load_complete && !this->_bank_changed && _info_received) {
        // Request data from the controller based on memory position
        //-------------------------------------------------------------
        QByteArray ms_received_data = this->cm->wait_for_ms_serial(800, this->mc->get_memory_position(this->ui->comboBox_bank->currentIndex(), this->ui->comboBox_switch->currentIndex()));
        if (mc->process_ms_data(ms_received_data)) {
            this->load_form_details();
        } else {
            QMessageBox::warning(this, "Transmission error", "Wrong data received! CheckSum wrong.");
        }
        this->statLabel->setText("Status: <font color = 'black'>Connected</font>");
    }
}

void MainWindow::on_pushButton_save_released()
{
    if (this->cm->check_if_device_available()) {
        this->statLabel->setText("Writing....");

        midi_structure *temp_ms = mc->ms;

        temp_ms->_mb1->set_all(ui->comboBox_type->currentIndex(), ui->spinBox_num->value(), ui->spinBox_val->value(), ui->spinBox_val_max->value(), ui->spinBox_channel->value());
        temp_ms->_mb2->set_all(ui->comboBox_type_2->currentIndex(), ui->spinBox_num_2->value(), ui->spinBox_val_2->value(), ui->spinBox_val_max_2->value(), ui->spinBox_channel_2->value());
        temp_ms->_mb3->set_all(ui->comboBox_type_3->currentIndex(), ui->spinBox_num_3->value(), ui->spinBox_val_3->value(), ui->spinBox_val_max_3->value(), ui->spinBox_channel_3->value());
        temp_ms->_mb4->set_all(ui->comboBox_type_4->currentIndex(), ui->spinBox_num_4->value(), ui->spinBox_val_4->value(), ui->spinBox_val_max_4->value(), ui->spinBox_channel_4->value());
        temp_ms->_mb5->set_all(ui->comboBox_type_5->currentIndex(), ui->spinBox_num_5->value(), ui->spinBox_val_5->value(), ui->spinBox_val_max_5->value(), ui->spinBox_channel_5->value());

        temp_ms->set_patch_name_short(this->ui->lineEdit_shortName->text());

        // Send the serial data to the midi pedal here
        QByteArray data_to_send = "^S" + temp_ms->get_serial_string() + "E";

        int checkSum_val = temp_ms->get_checkSum_val();

        for (int i = 0; i < temp_ms->get_patch_name_size(); i++) {
            checkSum_val += temp_ms->get_patch_name_short_4().at(i).toLatin1();
        }

        data_to_send += "C" + QByteArray::number(checkSum_val%128) + "V";


        qDebug() << "Sending Data :" << data_to_send;

        this->cm->write(data_to_send);

        //TODO: Get ack byte if update success, else fail
        if (cm->get_write_success()) {
            this->statLabel->setText("Status: <font color = 'green'>Saved</font>");
        } else {
            this->statLabel->setText("Status: <font color = 'red'>Data not updated. Error occured while uploading data.</font>");
        }
    } else {
        qDebug() << "Disconnecting";
        ui->actionConnect->setText("Connect");
        this->enable_form(false);
    }
}

void MainWindow::on_pushButton_reset_released()
{
    this->load_form_details();
}

void MainWindow::on_actionClose_triggered()
{
    if (cm->is_connected()) {
        this->_info_received = false;
    }
}

/*
void MainWindow::on_actionCheck_for_updates_triggered()
{

   QSqlDatabase db2 = QSqlDatabase::addDatabase("QMYSQL");

   db2.setHostName("localhost");
   db2.setDatabaseName("midieditor");
   db2.setUserName("root");
   db2.setPassword("System34");



   if(!db2.open()) {
       qDebug() << "Error connect" << db2.lastError().text();
   } else {
       qDebug("Connected");
   }
}*/

void MainWindow::on_actionExpression_Input_triggered()
{

}

void MainWindow::on_comboBox_type_currentIndexChanged(int index)
{
    this->ui->spinBox_channel->setValue(0);
    this->ui->spinBox_num->setValue(0);
    this->ui->spinBox_val->setValue(0);
    this->ui->spinBox_val_max->setValue(0);

    this->ui->spinBox_num->setEnabled(true);
    this->ui->spinBox_val->setEnabled(true);
    this->ui->spinBox_val_max->setEnabled(true);
    this->ui->spinBox_channel->setEnabled(true);

    // Enable forms
    switch (index) {
    case 0:
        this->ui->spinBox_num->setEnabled(false);
        this->ui->spinBox_val->setEnabled(false);
        this->ui->spinBox_val_max->setEnabled(false);
        this->ui->spinBox_channel->setEnabled(false);
        break;
    case 1:
        this->ui->spinBox_val->setEnabled(false);
        this->ui->spinBox_val_max->setEnabled(false);
        break;
    case 2:
        this->ui->spinBox_val_max->setEnabled(false);
        break;
    case 9: case 10: case 11: case 12:
        this->ui->spinBox_num->setEnabled(false);
        this->ui->spinBox_val->setEnabled(false);
        this->ui->spinBox_val_max->setEnabled(false);
        break;
    case 6: case 7:
        this->ui->spinBox_val_max->setEnabled(false);
    }

    // Change Labels
    this->ui->label_val->setText("Value 1");
    this->ui->label_val_max->setText("Value 2");
    this->ui->label_num->setText("Number 1");
    switch (index) {
    case 5:
        this->ui->label_val->setText("Number 2");
        this->ui->label_val_max->setText("Value 1");
        break;
    }
}

void MainWindow::on_comboBox_type_2_currentIndexChanged(int index)
{
    this->ui->spinBox_channel_2->setValue(0);
    this->ui->spinBox_num_2->setValue(0);
    this->ui->spinBox_val_2->setValue(0);
    this->ui->spinBox_val_max_2->setValue(0);

    this->ui->spinBox_num_2->setEnabled(true);
    this->ui->spinBox_val_2->setEnabled(true);
    this->ui->spinBox_val_max_2->setEnabled(true);
    this->ui->spinBox_channel_2->setEnabled(true);

    // Enable forms
    switch (index) {
    case 0:
        this->ui->spinBox_num_2->setEnabled(false);
        this->ui->spinBox_val_2->setEnabled(false);
        this->ui->spinBox_val_max_2->setEnabled(false);
        this->ui->spinBox_channel_2->setEnabled(false);
        break;
    case 1:
        this->ui->spinBox_val_2->setEnabled(false);
        this->ui->spinBox_val_max_2->setEnabled(false);
        break;
    case 2:
        this->ui->spinBox_val_max_2->setEnabled(false);
        break;
    case 9: case 10: case 11: case 12:
        this->ui->spinBox_num_2->setEnabled(false);
        this->ui->spinBox_val_2->setEnabled(false);
        this->ui->spinBox_val_max_2->setEnabled(false);
        break;
    case 6: case 7:
        this->ui->spinBox_val_max_2->setEnabled(false);
    }

    // Change Labels
    this->ui->label_val_2->setText("Value 1");
    this->ui->label_val_max_2->setText("Value 2");
    this->ui->label_num_2->setText("Number 1");
    switch (index) {
    case 5:
        this->ui->label_val_2->setText("Number 2");
        this->ui->label_val_max_2->setText("Value 1");
        break;
    }
}

void MainWindow::on_comboBox_type_3_currentIndexChanged(int index)
{
    this->ui->spinBox_channel_3->setValue(0);
    this->ui->spinBox_num_3->setValue(0);
    this->ui->spinBox_val_3->setValue(0);
    this->ui->spinBox_val_max_3->setValue(0);

    this->ui->spinBox_num_3->setEnabled(true);
    this->ui->spinBox_val_3->setEnabled(true);
    this->ui->spinBox_val_max_3->setEnabled(true);
    this->ui->spinBox_channel_3->setEnabled(true);

    // Enable forms
    switch (index) {
    case 0:
        this->ui->spinBox_num_3->setEnabled(false);
        this->ui->spinBox_val_3->setEnabled(false);
        this->ui->spinBox_val_max_3->setEnabled(false);
        this->ui->spinBox_channel_3->setEnabled(false);
        break;
    case 1:
        this->ui->spinBox_val_3->setEnabled(false);
        this->ui->spinBox_val_max_3->setEnabled(false);
        break;
    case 2:
        this->ui->spinBox_val_max_3->setEnabled(false);
        break;
    case 9: case 10: case 11: case 12:
        this->ui->spinBox_num_3->setEnabled(false);
        this->ui->spinBox_val_3->setEnabled(false);
        this->ui->spinBox_val_max_3->setEnabled(false);
        break;
    case 6: case 7:
        this->ui->spinBox_val_max_3->setEnabled(false);
    }

    // Change Labels
    this->ui->label_val_3->setText("Value 1");
    this->ui->label_val_max_3->setText("Value 2");
    this->ui->label_num_3->setText("Number 1");
    switch (index) {
    case 5:
        this->ui->label_val_3->setText("Number 2");
        this->ui->label_val_max_3->setText("Value 1");
        break;
    }
}

void MainWindow::on_comboBox_type_4_currentIndexChanged(int index)
{
    this->ui->spinBox_channel_4->setValue(0);
    this->ui->spinBox_num_4->setValue(0);
    this->ui->spinBox_val_4->setValue(0);
    this->ui->spinBox_val_max_4->setValue(0);

    this->ui->spinBox_num_4->setEnabled(true);
    this->ui->spinBox_val_4->setEnabled(true);
    this->ui->spinBox_val_max_4->setEnabled(true);
    this->ui->spinBox_channel_4->setEnabled(true);

    // Enable forms
    switch (index) {
    case 0:
        this->ui->spinBox_num_4->setEnabled(false);
        this->ui->spinBox_val_4->setEnabled(false);
        this->ui->spinBox_val_max_4->setEnabled(false);
        this->ui->spinBox_channel_4->setEnabled(false);
        break;
    case 1:
        this->ui->spinBox_val_4->setEnabled(false);
        this->ui->spinBox_val_max_4->setEnabled(false);
        break;
    case 2:
        this->ui->spinBox_val_max_4->setEnabled(false);
        break;
    case 9: case 10: case 11: case 12:
        this->ui->spinBox_num_4->setEnabled(false);
        this->ui->spinBox_val_4->setEnabled(false);
        this->ui->spinBox_val_max_4->setEnabled(false);
        break;
    case 6: case 7:
        this->ui->spinBox_val_max_4->setEnabled(false);
    }

    // Change Labels
    this->ui->label_val_4->setText("Value 1");
    this->ui->label_val_max_4->setText("Value 2");
    this->ui->label_num_4->setText("Number 1");
    switch (index) {
    case 5:
        this->ui->label_val_4->setText("Number 2");
        this->ui->label_val_max_4->setText("Value 1");
        break;
    }
}

void MainWindow::on_comboBox_type_5_currentIndexChanged(int index)
{
    this->ui->spinBox_channel_5->setValue(0);
    this->ui->spinBox_num_5->setValue(0);
    this->ui->spinBox_val_5->setValue(0);
    this->ui->spinBox_val_max_5->setValue(0);

    this->ui->spinBox_num_5->setEnabled(true);
    this->ui->spinBox_val_5->setEnabled(true);
    this->ui->spinBox_val_max_5->setEnabled(true);
    this->ui->spinBox_channel_5->setEnabled(true);

    // Enable forms
    switch (index) {
    case 0:
        this->ui->spinBox_num_5->setEnabled(false);
        this->ui->spinBox_val_5->setEnabled(false);
        this->ui->spinBox_val_max_5->setEnabled(false);
        this->ui->spinBox_channel_5->setEnabled(false);
        break;
    case 1:
        this->ui->spinBox_val_5->setEnabled(false);
        this->ui->spinBox_val_max_5->setEnabled(false);
        break;
    case 2:
        this->ui->spinBox_val_max_5->setEnabled(false);
        break;
    case 9: case 10: case 11: case 12:
        this->ui->spinBox_num_5->setEnabled(false);
        this->ui->spinBox_val_5->setEnabled(false);
        this->ui->spinBox_val_max_5->setEnabled(false);
        break;
    case 6: case 7:
        this->ui->spinBox_val_max_5->setEnabled(false);
    }

    // Change Labels
    this->ui->label_val_5->setText("Value 1");
    this->ui->label_val_max_5->setText("Value 2");
    this->ui->label_num_5->setText("Number 1");
    switch (index) {
    case 5:
        this->ui->label_val_5->setText("Number 2");
        this->ui->label_val_max_5->setText("Value 1");
        break;
    }
}
