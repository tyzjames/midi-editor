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

    // Check the last character. If it ends eith E means full string received
    //------------------------------------------------------------------------------------
    if (!data_in.endsWith("E")) {
        qDebug() << "Data error in process_ms_data. End byte not received. Last byte received: " << data_in.right(1);
        return false;
    } else {
        qDebug() << "Received data is correct. End byte received.";
        // Remove first and last character
        //-----------------------------------
        data_in.remove(data_in.length()-1,1);
    }

    qDebug() << "MS data: " << data_in;

    QRegExp rx("[,]");
    QStringList list = data_in.split(rx, QString::SkipEmptyParts);

    qDebug() << "MS List: " << list;

    // Store incoming string in midi_structure format
    //----------------------------------------------------------------------
    this->ms = new midi_structure(list.at(0).toInt(), list.mid(1, list.size()), this->_patch_name_size);

    return true;
}

// Process the incoming system info data
//-------------------------------------------
bool midi_controller::process_info_data(QString data_in){

    // Check the last character. If it ends eith E means full string received
    //------------------------------------------------------------------------------------
    if (!data_in.endsWith("E")) {
        qDebug() << "Data error in process_bank_Data. End byte not received for system data. Last byte received: " << data_in.right(1);
        return false;
    } else {
        qDebug() << "System info data is correct. End byte received.";
        // Remove first and last character
        //-----------------------------------
        data_in.remove(data_in.length()-1,1);
    }

    qDebug() << "System info data: " << data_in;

    // Split the string into list
    //-----------------------------------------
    QRegExp rx("[,]");
    QStringList list = data_in.split(rx, QString::SkipEmptyParts);
    int list_size = list.size();

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
