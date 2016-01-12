#include <midi_controller.h>
#include <QRegExp>
#include <QDebug>

midi_controller::midi_controller() {

}

midi_controller::midi_controller(int numBanks, int numSwitches) {

    this->set_number_of_banks(numBanks);
    this->set_number_of_switches(numSwitches);

}

void midi_controller::set_number_of_banks(int numBanks){
    this->_number_of_banks = numBanks;

    this->MIDI_bank.clear();
    for (int i = 0; i < numBanks; i++) {
        this->MIDI_bank.append(i);
    }
}

void midi_controller::set_number_of_switches(int numSwitches){
    this->_number_of_switches = numSwitches;

    this->switch_number.clear();
    for (int i = 0; i < numSwitches; i++) {
        this->switch_number.append(i);
    }
}

QStringList midi_controller::get_bank_str_list(){

    return this->bank_name.mid(0, this->_number_of_banks);
}

QStringList midi_controller::get_switch_str_list(){

    return this->switch_name.mid(0, this->_number_of_switches);
}

// Process the incoming midi structure data
//-----------------------------------------------
bool midi_controller::process_ms_data(QString data_in){

    QString ms_data;

    // Check the last character. If it ends eith E means full string received
    //------------------------------------------------------------------------------------
    int sendByte = data_in.indexOf('S');
    int endByte = data_in.indexOf('E', sendByte + 1);
    int checkSumStart = data_in.indexOf('C', endByte + 1);
    int checkSumEnd = data_in.indexOf('V', checkSumStart + 1);

    if (endByte < 0) {
        qDebug() << "(process_ms_data) Data error. End byte not received. Last byte received: " << data_in.right(1);
        return false;
    } else if (sendByte >= 0 && endByte > 0){
        qDebug() << "Received data is correct. End byte received.";
        ms_data = data_in.mid(sendByte + 1, endByte - sendByte - 1); // Remove first and last character

    }

    QRegExp rx("[,]");
    QStringList list = ms_data.split(rx, QString::SkipEmptyParts);
    qDebug() << "MS List: " << list;


    // CheckSum
    //--------------------
    int checkSumValExpected = 0;
    int checkSumVal = 0;

    if (checkSumStart < 0 && checkSumEnd < 0) {
        qDebug() << "CheckSum value not received";
    } else {
        checkSumVal = (data_in.mid(checkSumStart + 1, checkSumEnd - checkSumStart - 1).toInt())%128;

        for (int i = 1; i < list.size(); i++) { //Ignore first in list as that is the address position number
            checkSumValExpected += list.at(i).toInt();
        }

        checkSumValExpected = checkSumValExpected%128;

        if (checkSumVal != checkSumValExpected) {
            qDebug() << "CheckSum value wrong! Expected: " << checkSumValExpected << " | Received: " << checkSumVal;
            return false;
        } else {
            qDebug() << "CheckSum value correct! Expected: " << checkSumValExpected << " | Received: " << checkSumVal;
        }
    }

    // Store incoming string in midi_structure format
    //----------------------------------------------------------------------
    if (list.at(0) < 0) {
        return false;
    } else {
        this->ms = new midi_structure(list.at(0).toInt(), list.mid(1, list.size()), this->_patch_name_size);
    }

    return true;
}

// Process the incoming system info data
//-------------------------------------------
bool midi_controller::process_info_data(QString data_in){

    // Check the last character. If it ends eith E means full string received
    //------------------------------------------------------------------------------------
    int sendByte = data_in.indexOf('S');
    int endByte = data_in.indexOf('E', sendByte + 1);
    int checkSumStart = data_in.indexOf('C', endByte + 1);
    int checkSumEnd = data_in.indexOf('V', checkSumStart + 1);

    QString system_info_data = "";
    QString checkSum_data;

    if (endByte < 0) {
        qDebug() << "Data error in process_bank_Data. End byte not received for system data. Last byte received: " << data_in.right(1);
        return false;
    } else if (sendByte >= 0 && endByte > 0){
        qDebug() << "System info data is correct. End byte received.";
        // Remove first and last character
        //-----------------------------------
        system_info_data = data_in.mid(sendByte + 1, endByte - sendByte - 1); // Remove first and last character
    }

    qDebug() << "System info data: " << system_info_data;

    // Split the string into list
    //-----------------------------------------
    QRegExp rx("[,]");
    QStringList list = system_info_data.split(rx, QString::SkipEmptyParts);

    // CheckSum
    //--------------------
    int checkSumValExpected = 0;
    int checkSumVal = 0;

    if (checkSumStart < 0 && checkSumEnd < 0) {
        qDebug() << "CheckSum value not received";
    } else {
        checkSumVal = (data_in.mid(checkSumStart + 1, checkSumEnd - checkSumStart - 1).toInt())%128;
        qDebug() << "checkSumVal: " << data_in.mid(checkSumStart + 1, checkSumEnd - checkSumStart - 1);
        for (int i = 0; i < list.size(); i++) {
            checkSumValExpected += list.at(i).toInt();
        }

        checkSumValExpected = checkSumValExpected%128;

        if (checkSumVal != checkSumValExpected) {
            qDebug() << "CheckSum value wrong! Expected: " << checkSumValExpected << " | Received: " << checkSumVal;
            return false;
        } else {
            qDebug() << "CheckSum value correct! Expected: " << checkSumValExpected << " | Received: " << checkSumVal;
        }
    }

    qDebug() << "System info list: " << list;

    this->_model_number = list.at(0).toInt();
    this->_version_number = list.at(1).toInt();
    this->_version_number_2 = list.at(2).toInt();
    this->set_number_of_switches(list.at(3).toInt());
    this->set_number_of_banks(list.at(4).toInt());
    this->_patch_name_size = list.at(5).toInt();
    this->_struct_size = list.at(6).toInt();

    return true;
}

// Get the memory position of the midi structure by bank and switch.
// If 1 bank has 5 switches, bank 1 = 1,2,3,4,5. Bank 2 =  6,7,8,9,10
int midi_controller::get_memory_position(int inBank, int inSwitch) {
    return (inBank * this->_number_of_switches) + inSwitch;
}

int midi_controller::get_patch_name_size() {
    return this->_patch_name_size;
}
