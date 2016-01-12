#ifndef MIDI_CONTROLLER
#define MIDI_CONTROLLER

#include <midi_structure.h>
#include <QList>
#include <QHash>
#include <QStringList>
#include <QString>

class midi_controller
{
public:
    midi_controller();
    midi_controller(int numBanks, int numSwitches);

    QStringList get_bank_str_list();
    QStringList get_switch_str_list();

    midi_structure *ms;

    bool process_received_data(QString data_in); //return true if successful
    bool process_ms_data(QString data_in);
    bool process_info_data(QString data_in);

    int get_memory_position(int inBank, int inSwitch);
    int get_patch_name_size();

    const QStringList switch_name = (QStringList() << "A" << "B" << "C" << "D" << "E" << "F");
    const QStringList bank_name = (QStringList() << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10");

private:

    QList<int> MIDI_bank;
    QList<int> switch_number;
    QList<int> EEPROM_address;

    int _model_number;
    int _version_number;
    int _number_of_banks;
    int _number_of_switches;
    int _version_number_2;
    int _patch_name_size;
    int _struct_size;

    void set_number_of_banks(int numBanks);
    void set_number_of_switches(int numSwitches);

};

#endif // MIDI_CONTROLLER

