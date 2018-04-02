#ifndef UXFILEMAPREAD_H
#define UXFILEMAPREAD_H

#include <windows.h>
#include <stdio.h>
//#include <tchar.h>
#include <strsafe.h>
#include <QDebug>

#define BUF_SIZE 131072 // 256*256*32/16
#define ONE_LINE_DATA_SIZE 512

#include<QString>
#include<QDebug>

class UXFILEMAPREAD
{
public:
    UXFILEMAPREAD();
    ~UXFILEMAPREAD();

    void read();
    void addCurrentPos(DWORD cp);
    void setReadSize(DWORD );
    void close();
    QString readText();

private:
    QString storeText;
    HANDLE hMapFile;
    LPCTSTR pBuf;
    DWORD currentpos = 0;
    DWORD readsize = 0;
};

#endif // UXFILEMAPREAD_H
