//////////////////////////////////////////////////////////
//                                                      //
// Program name:        qrcode                          //
//                                                      //
// Description:         QRCode Datatype and Functions   //
//                                                      //
// Name:                Gerard Kuriger                  //
//                                                      //
//////////////////////////////////////////////////////////


#ifndef __QRCODE_H__
#define __QRCODE_H__

int get_size(int version);

// struct qrcode
// {
//     int version;
//     char type;
//     char[][] qrcode_data; 
// };


int get_version();
void ser_version(int p);

char get_typr();
void set_type();

