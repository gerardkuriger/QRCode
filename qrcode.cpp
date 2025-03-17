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

    void set_version(int version)
    {
        if (0 < version < 41){
            this->version = version;
        } else {
            printf("The version is invalid, enter number between 1 and 40");
        }
    }

    int get_size(){ return get_size(this->version); }

    int get_size(int version){ return (17 + (version * 4)); }

    int get_version(){ return version; }

    qrcode(string Message, int version, string type, int err_level){

    }



private:
    char type;
    int version;


    
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
