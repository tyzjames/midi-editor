#ifndef MIDI_STRUCTURE
#define MIDI_STRUCTURE

#endif // MIDI_STRUCTURE

#include <QString>
#include <QStringList>
#include <midi_base.h>

class midi_structure{
public:

    midi_structure(int inEEPROMaddress, QStringList inData, int inPatchNameSize);

    QString get_patch_name_short();
    QString get_patch_name_short_4();
    QByteArray get_serial_string();

    int get_checkSum_val();
    int get_patch_name_size();

    void set_patch_name_short(QString inPatchName);

    int STRUCT_SIZE;
    const QStringList MIDI_type_toggle = (QStringList() << "Empty" << "Program Change" << "Control Change"
                                        << "Strymon Bank Up" << "Strymon Bank Down" << "CC Toggle Value" << "CC Toggle Hold"
                                          << "CC Toggle Number");

    midi_base *_mb1;
    midi_base *_mb2;
    midi_base *_mb3;
    midi_base *_mb4;
    midi_base *_mb5;

private:

    int _EEPROM_address;
    QString _patch_name_short;
    int _patch_name_size;

    int _patch_name_checkSum;



};
