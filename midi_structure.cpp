#include <midi_structure.h>
#include <QDebug>
#include <QByteArray>
#include <QString>

midi_structure::midi_structure(int inEEPROMaddress, QStringList list, int inPatchNameSize) {

    qDebug() << "in midi structure: " << list;

    this->_EEPROM_address = inEEPROMaddress;
    this->_patch_name_size = inPatchNameSize;
    this->STRUCT_SIZE = list.size();

    int counter = 0;

    this->_mb1 = new midi_base(list.at(counter).toInt(), list.at(counter + 1).toInt(), list.at(counter + 2).toInt(), list.at(counter + 3).toInt(), list.at(counter + 4).toInt()); //0-4
    counter += 5;
    this->_mb2 = new midi_base(list.at(counter).toInt(), list.at(counter + 1).toInt(), list.at(counter + 2).toInt(), list.at(counter + 3).toInt(), list.at(counter + 4).toInt()); //5-9
    counter += 5;
    this->_mb3 = new midi_base(list.at(counter).toInt(), list.at(counter + 1).toInt(), list.at(counter + 2).toInt(), list.at(counter + 3).toInt(), list.at(counter + 4).toInt()); //10-14
    counter += 5;
    this->_mb4 = new midi_base(list.at(counter).toInt(), list.at(counter + 1).toInt(), list.at(counter + 2).toInt(), list.at(counter + 3).toInt(), list.at(counter + 4).toInt()); //15-19
    counter += 5;
    this->_mb5 = new midi_base(list.at(counter).toInt(), list.at(counter + 1).toInt(), list.at(counter + 2).toInt(), list.at(counter + 3).toInt(), list.at(counter + 4).toInt()); //20-24
    counter += 5;

    qDebug() << "counter: " << counter;

    //TODO: Preset Name should be a variable length
    QByteArray pNameShort = ""; // 25-28
    for (int j = 0; j < inPatchNameSize; j++) {
        QString str = list.at(counter++);
        qDebug() << "str: " << str;
        int c = str.toInt();
        pNameShort.append(QChar(c));
    }

    this->set_patch_name_short(pNameShort);
}

QByteArray midi_structure::get_serial_string() {

     QByteArray str = "";

    str.append(QString::number(this->_EEPROM_address));
    str.append(",");
    str.append(this->_mb1->get_serial_string());
    str.append(",");
    str.append(this->_mb2->get_serial_string());
    str.append(",");
    str.append(this->_mb3->get_serial_string());
    str.append(",");
    str.append(this->_mb4->get_serial_string());
    str.append(",");
    str.append(this->_mb5->get_serial_string());
    str.append(",");

    QString temp_patch_name_short = this->get_patch_name_short_4();
    for (int i = 0; i < this->_patch_name_size; i++) {
        int c = temp_patch_name_short.at(i).toLatin1();
        str.append(QString::number(c));
        if (i < this->_patch_name_size - 1) {
            str.append(",");
        }
    }

    qDebug() << "Get Serial String: " << str;

    return str;
}

QString midi_structure::get_patch_name_short(){
    return this->_patch_name_short;
}

void midi_structure::set_patch_name_short(QString inPatchNameShort){
    if (inPatchNameShort.length() > this->_patch_name_size) {
        this->_patch_name_short = inPatchNameShort.mid(0,this->_patch_name_size);
    }
    //this->_patch_name_short = inPatchNameShort.trimmed();
    this->_patch_name_short = inPatchNameShort;
}

/* Return patch name in 4 characters */
QString midi_structure::get_patch_name_short_4(){
    QString str = this->_patch_name_short;
    while (str.length() < this->_patch_name_size) {
        str.append(" ");
    }
    return str;
}

int midi_structure::get_checkSum_val() {
    int checkSum_val = this->_mb1->get_checkSum_val() + this->_mb2->get_checkSum_val() + this->_mb3->get_checkSum_val()
            + this->_mb4->get_checkSum_val() + this->_mb5->get_checkSum_val();
    return checkSum_val;
}

int midi_structure::get_patch_name_size() {
    return this->_patch_name_size;
}
