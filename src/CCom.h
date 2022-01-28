#include <Arduino.h>
#include "CComSettings.h"
#include <Wire.h>

class CCom
{
    private:
    
        boolean _newData = false;
        const byte _numChars = 32;
        char _receivedChars[32];
        char _tempChars[32];
        int _sendData[SEND_MOTOR_DATA_COUNT];
        int _dataCount = RADIO_DATA_COUNT;

    public:
        
        CCom();
        ~CCom();
        
        void parseData(int dataCount, int dataIn[]);
        void reveiceDataI2C(int howMany);
        void sendDataI2C();
        void sendDataUART(Stream &stream, int dataCount, int sendData[]);
        
        void logData(const char *logHeader, int dataCount, int dataIn[]);

        inline bool getIsNewData() {return _newData;}

        void setSendData(int dataCount, int dataToSend[]);
    

};

CCom::CCom(){}
CCom::~CCom(){}

void CCom::reveiceDataI2C(int howMany)
{
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char rc;
    int index = 0;

    while (Wire.available()) 
    {
        rc = Wire.read();
        //Serial.print(rc);
        
        if (recvInProgress == true) 
        {
            if (rc != END_MARKER) 
            {
                _receivedChars[ndx] = rc;
                index++;
                ndx++;
                if (ndx >= _numChars) 
                {
                ndx = _numChars - 1;
                }
            }
            else 
            {
                _receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                _newData = true;
            }
        }
        else if (rc == START_MARKER) 
        {
        recvInProgress = true;
        }
    }

    
}

void CCom::parseData(int dataCount, int dataIn[])
{
    strcpy(_tempChars, _receivedChars);

    char * strtokIndx;                       // this is used by strtok() as an index
    strtokIndx = strtok(_tempChars, SEPERATOR);     // get the first part - the string
    dataIn[0] = atoi(strtokIndx);

    for(int i = 1; i < dataCount; i++)
    {
        strtokIndx = strtok(NULL, SEPERATOR);
        dataIn[i] = atoi(strtokIndx);
    }

    _newData = false;
}


void CCom::sendDataUART(Stream &stream, int dataCount, int sendData[])
{
    stream.print(START_MARKER);
    stream.print(SEPERATOR);
    
    for (int i = 1; i < dataCount-1; i++)
    {
        stream.print(sendData[i]);
        stream.print(SEPERATOR);
    }
    stream.print(sendData[dataCount-1]);
    stream.println(END_MARKER);
}


void CCom::logData(const char *logHeader, int dataCount, int dataIn[])
{
    Serial.print(logHeader);
    for(int i = 0; i < dataCount; i++)
    {
      Serial.print(dataIn[i]);
      Serial.print(":");
    }

    Serial.println();
}

void CCom::sendDataI2C()
{
    Wire.print(START_MARKER);
    
    for (int i = 0; i < _dataCount-1; i++)
    {
        Wire.print(_sendData[i]);
        Wire.print(SEPERATOR);
    }
    Wire.print(_sendData[_dataCount-1]);
    Wire.print(SEPERATOR);
    Wire.println(END_MARKER);

}

void CCom::setSendData(int dataCount, int dataToSend[])
{
    for (int i = 0; i < dataCount; i++)
        _sendData[i] = dataToSend[i]; 
}