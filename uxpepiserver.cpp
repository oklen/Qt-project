#include "uxpepiserver.h"

UXPIPESERVER::UXPIPESERVER()
{


}


void UXPIPESERVER::InitServer()
{
    hPipe = CreateNamedPipe(
                lpszPipename,
                PIPE_ACCESS_DUPLEX,
                PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                PIPE_UNLIMITED_INSTANCES,
                BUFSIZ, //output buffer size
                BUFSIZ, // Input buffer size !Should expand to fit row data
                0,
                NULL);

    if(hPipe == INVALID_HANDLE_VALUE)
    {
        printf("CreateNamedPipe failed, GLE=%d.\n", GetLastError());
    }


    for(;;)
    {


        printf("\nPipe Serve: Main Thread awaiting client connection");


        //Wait for the client to connect;

        printf("\nTry connecting!");

    fConnected = ConnectNamedPipe(hPipe, NULL);

    if(fConnected)
    {
        printf("Client Connected\n");
    }
    else
    {
        printf("Connect fail!");
    }

    HANDLE hHeap = GetProcessHeap();
    TCHAR* pchRequest = (TCHAR*)HeapAlloc(hHeap, 0, BUFSIZ*sizeof(TCHAR));
    TCHAR* pchReply = (TCHAR*)HeapAlloc(hHeap, 0, BUFSIZ*sizeof(TCHAR));

    DWORD cbBytesRead = 0, cbReplyBytes = 0, cbWritten = 0;
    BOOL fSuccess = FALSE;

    //Do some extra error checking since the app will keep running even if the thread fails.

    LPVOID lpvParam = (LPVOID)hPipe;

    if(lpvParam == NULL)
    {
        printf("\nERROR - Pipe Server Failure:\n");
        printf("  InstanceThread got an unexpected NULL value in lpvParam.\n");
        if(pchReply != NULL) HeapFree(hHeap, 0, pchReply);
        if(pchRequest != NULL) HeapFree(hHeap, 0, pchRequest);
    }

    if(pchRequest == NULL)
    {
        printf("\nERROR - Pipe Server Failure:\n");
        printf("  InstanceThread got an unexpected NULL value in lpvParam.\n");
        if(pchRequest != NULL) HeapFree(hHeap, 0, pchRequest);
    }

    if(pchReply == NULL)
    {
        printf("\nERROR - Pipe Server Failure:\n");
        printf("  InstanceThread got an unexpected NULL value in lpvParam.\n");
        if(pchReply != NULL) HeapFree(hHeap, 0, pchReply);
    }

    printf("InstanceThread created, receiving and processing message.\n");

    hPipe = (HANDLE)lpvParam;

    while(1)
    {
        fSuccess = ReadFile(hPipe,
                            pchRequest,
                            BUFSIZ*sizeof(TCHAR),
                            &cbBytesRead,
                            NULL);

        if (!fSuccess || cbBytesRead ==0)
        {
            if(GetLastError() == ERROR_BROKEN_PIPE)
            {
                printf("InstanceThread: client disconnected.\n");
            }
            else
            {
                printf("InstanceThread ReadFile failed");
            }
            break;
        }
        if(fSuccess)
            break;

    }
    w.setText("Get to write");

    GetAnswerToResquest(pchRequest,pchReply,&cbBytesRead);
    w.setText("Get to write");
    fSuccess = WriteFile(
                hPipe,
                pchReply,
                cbReplyBytes,
                &cbWritten,
                NULL);

    if(!fSuccess || cbReplyBytes != cbWritten)
    {
        w.setText("Write Failed");
    }
    FlushFileBuffers(hPipe);
    DisconnectNamedPipe(hPipe);
//    CloseHandle(hPipe);

    HeapFree(hHeap, 0, pchRequest);
    HeapFree(hHeap, 0, pchReply);
    w.setText(QString::fromStdString(messageHead));
//    box.messageHead = messageHead;
//    box.paraVector = paramList;
    paramList.clear();
//    box.doupdate();
}

}

std::vector<std::string> messageParse(TCHAR *source)
{
    //Convert to std::string
    int iLen = WideCharToMultiByte(CP_ACP, 0,source, -1, NULL, 0, NULL, NULL);

     char* chRtn =new char[iLen*sizeof(char)];

     WideCharToMultiByte(CP_ACP, 0, source, -1, chRtn, iLen, NULL, NULL);


     std::string sourcep = std::string(chRtn);
     std::vector<std::string> result;
     int findin[10] {0};
     int count = 0;
     int lastfind = 0;

     for(;;)
     {
         if(sourcep.find_first_of(" ",lastfind) != sourcep.npos)
         {
             findin[count] = sourcep[sourcep.find_first_of(" ",lastfind)];
             result.push_back(sourcep.substr(lastfind,sourcep.find_first_of(" ",lastfind)-lastfind));
             lastfind = sourcep.find_first_of(" ",lastfind) + 1;
             count++;
         }
         else
         {
             break;
         }
     }
     return result;
}

VOID UXPIPESERVER::GetAnswerToResquest(TCHAR* pchRequest, TCHAR* pchRely, LPDWORD pchBytes)
{
    w.setText(QString::fromUtf16((ushort*)pchRequest));
    std::vector<std::string> result = messageParse(pchRequest);

    w.setText(QString::fromUtf16((ushort*)pchRequest));
    messageHead = result.at(0);


    w.setText(QString::fromStdString(messageHead));
    if(result.size() == 1)
    {
        headOnly = true;
        if(messageHead.c_str() == "UMSG_PG_OVER_LINE")
            emit emiter.m3();
        if(messageHead.c_str() == "UMSG_PG_OVER_SCAN")
            emit emiter.m4();
    }
    else
    {
        std::reverse(result.begin(),result.end());
        result.pop_back();
        std::reverse(result.begin(),result.end());
        paramList = result;
        if(messageHead.c_str() == "UMSG_PG_FOUR_QUAD")
            emiter.dom1(paramList);
        if(messageHead.c_str() == "UMSG_PG_SCAN_DATA")
            emiter.dom2(paramList);
        if(messageHead.c_str() == "UMSG_PG_PROBE_COOR")
            emiter.dom5(paramList);
        if(messageHead.c_str() == "UMSG_PG_SAMPLE_COOR")
            emiter.dom6(paramList);
        headOnly = false;
    }

    // Do Some Check here
    StringCchCopy(pchRely,BUFSIZ,TEXT("OK!WOdone"));
    *pchBytes = (lstrlen(pchRely)+1)*sizeof(TCHAR);
}

void UXPIPESERVER::StartServer()
{
    t = std::thread(&UXPIPESERVER::InitServer,this);
//    t.detach();

}
