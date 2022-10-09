#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>


void getProcessList(){
HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
if(hSnap != INVALID_HANDLE_VALUE){
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if(Process32First(hSnap, &pe)){
        do{
            std::wcout << pe.szExeFile << " " << pe.th32ProcessID << std::endl;
        }while(Process32Next(hSnap, &pe));
    }
}

}

int main(){

    getProcessList();
}