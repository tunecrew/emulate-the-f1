
/*
TriggerFingerToF1
version 0.1

part of:

emulate-the-f1

Version 1.0
Christopher Albin Edmonds - christopher@tunecrew.com - http://www.tunecrew.com/

Copyright (C) 2014 Christopher Albin Edmonds where applicable. See license.txt for further details on copyright, licensing and distribution of emulate-the-f1.
*/

// include the serial library so we can read MIDI
#include <SoftwareSerial.h>

#define MIDI_BAUD_RATE 31250
#define SERIAL_BAUD_RATE 38400
#define ANALOG1 A0
#define ANALOG2 A1
#define RX 4
#define TX 5
#define MIDI_NOTE_ON 0x99
#define MIDI_NOTE_OFF 0x89
#define MIDI_CC 0xB9
#define MIDI_PAD_01 0x24
#define MIDI_PAD_02 0x26
#define MIDI_PAD_03 0x28
#define MIDI_PAD_04 0x25
#define MIDI_PAD_05 0x32
#define MIDI_PAD_06 0x30
#define MIDI_PAD_07 0x2D
#define MIDI_PAD_08 0x29
#define MIDI_PAD_09 0x38
#define MIDI_PAD_10 0x27
#define MIDI_PAD_11 0x2A
#define MIDI_PAD_12 0x2E
#define MIDI_PAD_13 0x31
#define MIDI_PAD_14 0x39
#define MIDI_PAD_15 0x33
#define MIDI_PAD_16 0x35
#define MIDI_POT_1 0x0A
#define MIDI_POT_2 0x5B
#define MIDI_POT_3 0x0C
#define MIDI_POT_4 0x5D
#define MIDI_POT_5 0x05
#define MIDI_POT_6 0x47
#define MIDI_POT_7 0x54
#define MIDI_POT_8 0x48
#define MIDI_FADER_1 0x07
#define MIDI_FADER_2 0x01
#define MIDI_FADER_3 0x46
#define MIDI_FADER_4 0x4A
#define MESSAGE_NOTE_OTHER 0x00
#define MESSAGE_NOTE_ON 0x01
#define MESSAGE_NOTE_OFF 0x02
#define MESSAGE_CC 0x03
#define F1_PAD_00 B00000000
#define F1_PAD_01 B10000000
#define F1_PAD_02 B01000000
#define F1_PAD_03 B00100000
#define F1_PAD_04 B00010000
#define F1_PAD_05 B00001000
#define F1_PAD_06 B00000100
#define F1_PAD_07 B00000010
#define F1_PAD_08 B00000001
#define F1_PAD_09 B10000000
#define F1_PAD_10 B01000000
#define F1_PAD_11 B00100000
#define F1_PAD_12 B00010000
#define F1_PAD_13 B00001000
#define F1_PAD_14 B00000100
#define F1_PAD_15 B00000010
#define F1_PAD_16 B00000001
#define F1_FADER_1 0x0E
#define F1_FADER_2 0x10
#define F1_FADER_3 0x12
#define F1_FADER_4 0x14
#define F1_POT_1 0x06
#define F1_POT_2 0x08
#define F1_POT_3 0x0A
#define F1_POT_4 0x0C

int message_type;
int last_message_type;
int midi_byte;
int note_byte;
int value_byte;
int message[3];
boolean pads[16];
int pots[8];
int faders[4];
byte report[22];

SoftwareSerial MIDISerial(RX, TX);

void setup()
{
  MIDISerial.begin(MIDI_BAUD_RATE);
  Serial.begin(SERIAL_BAUD_RATE);
  last_message_type = MESSAGE_NOTE_OTHER;
  for (int i = 0; i < 16; i++) { pads[i] = 0x00; }
  for (int i = 0; i < 8; i++) { pots[i] = 0x00; }
  for (int i = 0; i < 4; i++) { faders[i] = 0x00; }
  for (int i = 0; i < 22; i++) { report[i] = 0x00; }
  report[0] = 0x01;
}

void loop()
{
  if (MIDISerial.available())
  {
    midi_byte = MIDISerial.read();

    if (midi_byte == MIDI_NOTE_ON || midi_byte == MIDI_NOTE_OFF || midi_byte == MIDI_CC)
    {
      note_byte = MIDISerial.read();
      value_byte = MIDISerial.read();

      switch (midi_byte)
      {
        case MIDI_NOTE_ON:
          message[0] = MESSAGE_NOTE_ON;
          break;
        case MIDI_NOTE_OFF:
          message[0] = MESSAGE_NOTE_OFF;
          break;
        case MIDI_CC:
          message[0] = MESSAGE_CC;
          break;
      }

      last_message_type = message[0];
    }
    else
    {
      note_byte = midi_byte;
      value_byte = MIDISerial.read();
    }

    message[1] = note_byte;
    message[2] = value_byte;

    if (value_byte == 0x00 && message[0] != MESSAGE_CC) { message[0] = MESSAGE_NOTE_OFF; }
    else { message[0] = last_message_type; }

    if (message[0] == MESSAGE_NOTE_ON)
    {
      if      (message[1] == MIDI_PAD_01) { pads[0]  = 1; report[2] = report[2] | F1_PAD_13; }
      else if (message[1] == MIDI_PAD_02) { pads[1]  = 1; report[2] = report[2] | F1_PAD_14; }
      else if (message[1] == MIDI_PAD_03) { pads[2]  = 1; report[2] = report[2] | F1_PAD_15; }
      else if (message[1] == MIDI_PAD_04) { pads[3]  = 1; report[2] = report[2] | F1_PAD_16; }

      else if (message[1] == MIDI_PAD_05) { pads[4]  = 1; report[2] = report[2] | F1_PAD_09; }
      else if (message[1] == MIDI_PAD_06) { pads[5]  = 1; report[2] = report[2] | F1_PAD_10; }
      else if (message[1] == MIDI_PAD_07) { pads[6]  = 1; report[2] = report[2] | F1_PAD_11; }
      else if (message[1] == MIDI_PAD_08) { pads[7]  = 1; report[2] = report[2] | F1_PAD_12; }

      else if (message[1] == MIDI_PAD_09) { pads[8]  = 1; report[1] = report[1] | F1_PAD_05; }
      else if (message[1] == MIDI_PAD_10) { pads[9]  = 1; report[1] = report[1] | F1_PAD_06; }
      else if (message[1] == MIDI_PAD_11) { pads[10] = 1; report[1] = report[1] | F1_PAD_07; }
      else if (message[1] == MIDI_PAD_12) { pads[11] = 1; report[1] = report[1] | F1_PAD_08; }

      else if (message[1] == MIDI_PAD_13) { pads[12] = 1; report[1] = report[1] | F1_PAD_01; }
      else if (message[1] == MIDI_PAD_14) { pads[13] = 1; report[1] = report[1] | F1_PAD_02; }
      else if (message[1] == MIDI_PAD_15) { pads[14] = 1; report[1] = report[1] | F1_PAD_03; }
      else if (message[1] == MIDI_PAD_16) { pads[15] = 1; report[1] = report[1] | F1_PAD_04; }
    }
    else if (message[0] == MESSAGE_NOTE_OFF)
    {
      if      (message[1] == MIDI_PAD_01) { pads[0]  = 0; report[2] = report[2] ^ F1_PAD_13; }
      else if (message[1] == MIDI_PAD_02) { pads[1]  = 0; report[2] = report[2] ^ F1_PAD_14; }
      else if (message[1] == MIDI_PAD_03) { pads[2]  = 0; report[2] = report[2] ^ F1_PAD_15; }
      else if (message[1] == MIDI_PAD_04) { pads[3]  = 0; report[2] = report[2] ^ F1_PAD_16; }

      else if (message[1] == MIDI_PAD_05) { pads[4]  = 0; report[2] = report[2] ^ F1_PAD_09; }
      else if (message[1] == MIDI_PAD_06) { pads[5]  = 0; report[2] = report[2] ^ F1_PAD_10; }
      else if (message[1] == MIDI_PAD_07) { pads[6]  = 0; report[2] = report[2] ^ F1_PAD_11; }
      else if (message[1] == MIDI_PAD_08) { pads[7]  = 0; report[2] = report[2] ^ F1_PAD_12; }

      else if (message[1] == MIDI_PAD_09) { pads[8]  = 0; report[1] = report[1] ^ F1_PAD_05; }
      else if (message[1] == MIDI_PAD_10) { pads[9]  = 0; report[1] = report[1] ^ F1_PAD_06; }
      else if (message[1] == MIDI_PAD_11) { pads[10] = 0; report[1] = report[1] ^ F1_PAD_07; }
      else if (message[1] == MIDI_PAD_12) { pads[11] = 0; report[1] = report[1] ^ F1_PAD_08; }

      else if (message[1] == MIDI_PAD_13) { pads[12] = 0; report[1] = report[1] ^ F1_PAD_01; }
      else if (message[1] == MIDI_PAD_14) { pads[13] = 0; report[1] = report[1] ^ F1_PAD_02; }
      else if (message[1] == MIDI_PAD_15) { pads[14] = 0; report[1] = report[1] ^ F1_PAD_03; }
      else if (message[1] == MIDI_PAD_16) { pads[15] = 0; report[1] = report[1] ^ F1_PAD_04; }
    }
    else if (message[0] == MESSAGE_CC)
    {
      int new_val = map(message[2], 0x00, 0x7F, 0, 4095);
      byte byte_l = lowByte(new_val);
      byte byte_h = highByte(new_val);
      
      if      (message[1] == MIDI_POT_1)   { pots[0] = message[2]; report[F1_FADER_1] = byte_l; report[F1_FADER_1 + 1] = byte_h; }
      else if (message[1] == MIDI_POT_2)   { pots[1] = message[2]; report[F1_POT_1] =  byte_l;  report[F1_POT_1 + 1]   = byte_h; }
      else if (message[1] == MIDI_POT_3)   { pots[2] = message[2]; report[F1_FADER_2] = byte_l; report[F1_FADER_2 + 1] = byte_h; }
      else if (message[1] == MIDI_POT_4)   { pots[3] = message[2]; report[F1_POT_2] = byte_l;   report[F1_POT_2 + 1]   = byte_h; }
      else if (message[1] == MIDI_POT_5)   { pots[4] = message[2]; report[F1_FADER_3] = byte_l; report[F1_FADER_3 + 1] = byte_h; }
      else if (message[1] == MIDI_POT_6)   { pots[5] = message[2]; report[F1_POT_3] = byte_l;   report[F1_POT_3 + 1]   = byte_h; }
      else if (message[1] == MIDI_POT_7)   { pots[6] = message[2]; report[F1_FADER_4] = byte_l; report[F1_FADER_4 + 1] = byte_h; }
      else if (message[1] == MIDI_POT_8)   { pots[7] = message[2]; report[F1_POT_4] = byte_l;   report[F1_POT_4 + 1]   = byte_h; }
      else if (message[1] == MIDI_FADER_1) { faders[0] = message[2]; }
      else if (message[1] == MIDI_FADER_2) { faders[1] = message[2]; }
      else if (message[1] == MIDI_FADER_3) { faders[2] = message[2]; }
      else if (message[1] == MIDI_FADER_4) { faders[3] = message[2]; }
    }

    // send HID message
    Serial.write(report, 22);
  }
}

