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

class qrcode
{
public:
    char type;
    int version;

    int set_version(int version);

    int get_size()
    {
        return get_size(get_version());
    }

    int get_size(int version)
    {
        return (17 + (version * 4));
    }

    int get_version()
    {
        return version;
    }

    
};






int main(int argc, char const *argv[])
{

    if (argc == 1){
        printf("You have not supplied enougth arguments!");
        return 0;
    }
    printf("Message: %s\n", argv[1]);
    return 0;
}
