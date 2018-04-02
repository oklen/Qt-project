#include "uxfilemapread.h"

UXFILEMAPREAD::UXFILEMAPREAD()
{
    setReadSize(16);
    TCHAR szName[]=TEXT("Global\\MyFileMappingObject");
//    hMapFile = CreateFileMapping(
//        INVALID_HANDLE_VALUE,    // use paging file, Creating Named Shared Memory
//        NULL,                    // default security
//        PAGE_READWRITE,          // read/write access
//        0,                       // max. object size
//        BUF_SIZE,                // low order buffer size
//        szName);                 // name of mapping object
    hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,                    // default security
                TRUE,
        szName);                 // name of mapping object


    if (hMapFile == NULL || hMapFile == INVALID_HANDLE_VALUE)
    {
        printf("Could not create file mapping object (%d).\n",
            GetLastError());
    }

}

void UXFILEMAPREAD::read()
{
    pBuf = (LPTSTR) MapViewOfFile(hMapFile,   // handle to map object
        FILE_MAP_ALL_ACCESS, // read/write permission
        0,
        0, // Select where to begin read in low-order
        BUFSIZ
        );
    qDebug() << "R:Get Threre";

    TCHAR* cache = new TCHAR[readsize/sizeof(TCHAR)+1];
    CopyMemory(cache,(PVOID)(pBuf+currentpos),readsize);
    cache[readsize/sizeof(TCHAR)] = '\0';
    qDebug() << QString::fromUtf16(reinterpret_cast<ushort*>(cache));
    storeText = QString::fromUtf16(reinterpret_cast<ushort*>(cache));
   qDebug() << "R:Get Threre2";
    UnmapViewOfFile(pBuf);
    addCurrentPos(2);
//    addCurrentPos(16);

}

void UXFILEMAPREAD::setReadSize(DWORD size)
{
    readsize = size;
}

void UXFILEMAPREAD::addCurrentPos(DWORD cp)
{
    currentpos += cp;
}

void UXFILEMAPREAD::close()
{
    CloseHandle(hMapFile);
}

QString UXFILEMAPREAD::readText()
{
    read();
    return storeText;
}

UXFILEMAPREAD::~UXFILEMAPREAD()
{
    close();
}
