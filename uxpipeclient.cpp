#include "uxpipeclient.h"

UXPIPECLIENT::UXPIPECLIENT()
{

}

void UXPIPECLIENT::pipeSend()
{
    HANDLE hPipe;
    TCHAR chBuf[BUFSIZ];
    BOOL fSuccess = FALSE;
    DWORD cbRead, cbToWrite, cbWritten, dwMode;
    LPTSTR lpszPipename = TEXT("\\\\.\\pipe\\uxserve");
            mlab.setText(QString("wait!") + mlab.text());

    while(1)
    {
        hPipe = CreateFile(
                    lpszPipename,
                    GENERIC_READ|
                    GENERIC_WRITE,
                    0,
                    NULL,
                    OPEN_EXISTING,
                    0,
                    NULL);

        if(hPipe != INVALID_HANDLE_VALUE)
            break;

        if(GetLastError() != ERROR_PIPE_BUSY)
        {
            mlab.setText(QString( "Could not open pipe"));
        }
        mlab.setText("Waiting to connect!");
        if(!WaitNamedPipe(lpszPipename,100000));
        {
            mlab.setText("waitFail!");
            return;
        }
    }
    mlab.setText(QString( "While out"));
    dwMode = PIPE_READMODE_MESSAGE;
    fSuccess = SetNamedPipeHandleState(
                hPipe,
                &dwMode,
                NULL,
                NULL);
    if(! fSuccess)
    {
        printf("SetNamedPipeHandleState failed");
    }

    cbToWrite = (lstrlen(lpvMessage)+1)*sizeof(TCHAR);

    fSuccess = WriteFile(
                hPipe,
                lpvMessage,
                cbToWrite,
                &cbWritten,
                NULL);
    if(!fSuccess)
    {
        mlab.setText("Write fail!");
    }
    mlab.setText(QString("do read"));
    do
    {
        mlab.setText(QString("read\n")+mlab.text());

        fSuccess = ReadFile(
                    hPipe,
                    chBuf,
                    BUFSIZ*sizeof(TCHAR),
                    &cbRead,
                    NULL);
        mlab.setText(QString("read\n")+mlab.text());

    }while(!fSuccess);
    CloseHandle(hPipe);
}

void UXPIPECLIENT::m_pipeSend(TCHAR *m)
{
    lpvMessage=(LPCWSTR)m;
    t = std::thread(&UXPIPECLIENT::pipeSend,this);
    t.join();

}
