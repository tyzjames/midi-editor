#ifndef MIDI_BASE
#define MIDI_BASE

#endif // MIDI_BASE

#include <QByteArray>

class midi_base{
public:
    midi_base(int type, int num, int val, int channel);
    midi_base(int type, int num, int val, int val_max, int channel);
    int get_type();
    int get_num();
    int get_val();
    int get_val_max();
    int get_channel();
    int get_checkSum_val();
    QByteArray get_serial_string();

    void set_type(int inType);
    void set_num(int inNum);
    void set_val(int inVal);
    void set_val_max(int inValMax);
    void set_channel(int inChannel);
    void set_all(int inType, int inNum, int inVal, int inChannel);
    void set_all(int inType, int inNum, int inVal, int inValMx, int inChannel);


private:
    int _type;
    int _num;
    int _val;
    int _val_max;
    int _channel;

};
