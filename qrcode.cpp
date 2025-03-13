//////////////////////////////////////////////////////////
//                                                      //
// Program name:        qrcode                          //
//                                                      //
// Description:         QRCode Datatype and Functions   //
//                                                      //
// Name:                Gerard Kuriger                  //
//                                                      //
//////////////////////////////////////////////////////////

#include <stdio.h>

// #ifndef __QRCODE_H__
// #define __QRCODE_H__

using namespace std;

// struct qrcode
// {
//     int version;
//     char type;
//     char[][] qrcode_data; 
// };


int main(int argc, char const *argv[])
{

    if (argc == 1){
        printf("You have not supplied enougth arguments!");
        return 0;
    }
    printf("Message: %s\n", argv[1]);
    return 0;
}


int get_size(int version)
{
    return (17 + (version * 4));
}

int get_version();
void ser_version(int p);

char get_typr();
void set_type();

