// Copyright YummyCarrot(huyuzhe)

// My Github Location:
// https://github.com/CRThu

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "serial.h"

int main()
{
    int status;
    Serial dev;
    string BufIn;
    char BufOut[1024] = {};

    string COM; // dev/ttyS$COM$
    int BaudRate;   // E.g. 115200
    int DataSize;   // E.g. 8
    int ParityBit;  // E.g. 0
    int StopBit;    // E.g. 1

    //cout << "list all device now : " << endl;
    //system("ls /dev");
    //cout << endl;
    //cout << "enter COM : ";
    //cin >> COM;
    //cout << "enter BaudRate : ";
    //cin >> BaudRate;
    //cout << "enter DataSize : ";
    //cin >> DataSize;
    //cout << "enter ParityBit : ";
    //cin >> ParityBit;
    //cout << "enter StopBit : ";
    //cin >> StopBit;

    dev.SetPort("ttyUSB0", 921600, 8, 0, 1);

    status = dev.SetPortConfig();
    cout << "dev.SetPortConfig() status : " << status << endl;
    status = dev.SetPortOpen();
    cout << "dev.SetPortOpen() status : " << status << endl;


    status = dev.SetPortWrite("C", sizeof("C"));
    cout << "dev.SetPortWrite() data : " << "C" << " , status : " << status << endl;
    usleep(5000000);
    status = dev.SetPortRead(BufOut, sizeof(BufOut));
    cout << "dev.SetPortRead() data : " << BufOut << " , status : " << status << endl;

    dev.SetPortReadRefresh(BufOut);
    status = dev.SetPortWrite("$voltage\n", sizeof("$voltage\n"));
    cout << "dev.SetPortWrite() data : " << "$voltage\n" << " , status : " << status << endl;
    usleep(50000);
    status = dev.SetPortRead(BufOut, sizeof(BufOut));
    cout << "dev.SetPortRead() data : " << BufOut << " , status : " << status << endl;

    dev.SetPortReadRefresh(BufOut);
    status = dev.SetPortWrite("$date,get\n", sizeof("$date,get\n"));
    cout << "dev.SetPortWrite() data : " << "$date,get\n" << " , status : " << status << endl;
    usleep(50000);
    status = dev.SetPortRead(BufOut, sizeof(BufOut));
    cout << "dev.SetPortRead() data : " << BufOut << " , status : " << status << endl;


    //while (1)
    //{    
    //    if (BufIn == "#exit#")      // exit command
    //        break;
    //    if (BufIn == "#exit#\n")      // exit command
    //        break;
    //    cout << "input : ";
    //    cin >> BufIn;
    //    //const char NewLine[2] = { 0x0a,'\0' };
    //    BufIn += "\n";
    //    //dev.SetChangeString(BufIn);      // change "\\n" to newline
    //    dev.SetPortReadRefresh(BufOut);
    //    status = dev.SetPortWrite(BufIn, sizeof(BufIn.c_str()));
    //    cout << "dev.SetPortWrite() data : " << BufIn << " , status : " << status << endl;
    //    status = dev.SetPortRead(BufOut, sizeof(BufOut));
    //    cout << "dev.SetPortRead() data : " << BufOut << " , status : " << status << endl;
    //}
    //cout << "found input : " << BufIn << " . close ! " << endl;

    status = dev.SetPortClose();
    cout << "dev.SetPortClose() status : " << status << endl;

}
