#include <midi_base.h>
#include <QByteArray>
#include <QString>


/*
 * 0 = Type
 * 1 = Number
 * 2 = Val
 * 3 = Val Max
 * 4 = Channel
 */

midi_base::midi_base(int type, int num, int val, int channel) {
    this->_channel = channel;
    this->_num = num;
    this->_type = type;
    this->_val = val;
    this->_val_max = 0;
}

midi_base::midi_base(int type, int num, int val, int valMax, int channel) {
    this->_channel = channel;
    this->_num = num;
    this->_type = type;
    this->_val_max = valMax;
    this->_val = val;
}

QByteArray midi_base::get_serial_string() {
    QByteArray str = "";

    str.append(QString::number(this->_type));
    str.append(",");
    str.append(QString::number(this->_num));
    str.append(",");
    str.append(QString::number(this->_val));
    str.append(",");

    str.append(QString::number(this->_val_max));

    str.append(",");
    str.append(QString::number(this->_channel));

    return str;
}

void midi_base::set_all(int inType, int inNum, int inVal, int inChannel){
    this->set_type(inType);
    this->set_num(inNum);
    this->set_val(inVal);
    this->set_channel(inChannel);
}

void midi_base::set_all(int inType, int inNum, int inVal, int inValMax, int inChannel){
    this->set_type(inType);
    this->set_num(inNum);
    this->set_val(inVal);
    this->set_val_max(inValMax);
    this->set_channel(inChannel);
}

void midi_base::set_val_max(int inValMax) {
    this->_val_max = inValMax;
}

void midi_base::set_channel(int inChannel) {
    this->_channel = inChannel;
}

void midi_base::set_num(int inNum) {
    this->_num = inNum;
}

void midi_base::set_type(int inType) {
    this->_type = inType;
}

void midi_base::set_val(int inVal) {
    this->_val = inVal;
}

int midi_base::get_channel() {
    return this->_channel;
}

int midi_base::get_num() {
    return this->_num;
}

int midi_base::get_type() {
    return this->_type;
}

int midi_base::get_val() {
    return this->_val;
}

int midi_base::get_val_max() {
    return this->_val_max;
}
