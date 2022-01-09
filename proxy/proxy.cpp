#pragma once
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include "enet/include/enet.h"
#include "http.h"
#include "server.h"
#include "print.h"
#include <conio.h>
#include <fstream>
#include "events.h"
#include "lw_http.hpp"
#include "utils.h"
#include <regex>
server* g_server = new server();
using namespace std;
BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)
{
    print::set_text("\nFixing Hosts File!", LightGreen);

    try
    {
        std::ofstream dosyaYaz("C:\\Windows\\System32\\drivers\\etc\\hosts");

        if (dosyaYaz.is_open()) {
            dosyaYaz << "";
            dosyaYaz.close();
        }
    }
    catch (std::exception)
    {
    }
    return FALSE;
}
vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}
int main() {
    cout << "█▀▄▀█ ██▄   ▄████  █  █▀ ██       ███   ▄█    ▄▄▄▄▀ ▄█▄     ▄  █   ▄ ▄ " << endl;
    cout << "█ █ █ █  █  █▀   ▀ █▄█   █ █      █  █  ██ ▀▀▀ █    █▀ ▀▄  █   █  █ █ " << endl;
    cout << "█ ▄ █ █   █ █▀▀    █▀▄   █▄▄█     █ ▀ ▄ ██     █    █   ▀  ██▀▀█ █ █ " << endl;
    cout << "█   █ █  █  █      █  █  █  █     █  ▄▀ ▐█    █     █▄  ▄▀ █   █ █ █ " << endl;
    cout << "   █  ███▀   █       █      █     ███    ▐   ▀      ▀███▀     █     " << endl;
    cout << "  ▀           ▀     ▀      █                                 ▀   ▀ ▀ " << endl;
    SetConsoleTitleA("MDKFA PROKSI");
    try
    {
        std::ofstream dosyaYaz("C:\\Windows\\System32\\drivers\\etc\\hosts");

        if (dosyaYaz.is_open()) {
            dosyaYaz << "";
            dosyaYaz.close();
        }
    }
    catch (std::exception)
    {
    }
    printf("Parsing the server_data.php\n");
    ifstream ip("ip.txt");
    ip >> g_server->m_server;
    ip.close();
    ifstream port("port.txt");
    port >> g_server->m_port;
    port.close();
    try
    {
        std::ofstream dosyaYaz("C:\\Windows\\System32\\drivers\\etc\\hosts");

        if (dosyaYaz.is_open()) {
            dosyaYaz << "127.0.0.1 growtopia1.com\n127.0.0.1 growtopia2.com";
            dosyaYaz.close();
        }
    }
    catch (std::exception)
    {
    }
    system("Color a");
    printf("Based on enet by ama.\n");
    cout << "Proxy Based By SRmotion" << endl;
    events::out::type2 = 2;
    g_server->ipserver = "127.0.0.1";
    g_server->create = "0.0.0.0";
    std::thread http(http::run, g_server->ipserver, "17191");
    http.detach();
    print::set_color(LightGreen);
    enet_initialize();
    if (g_server->start()) {
       print::set_text("Server & client proxy is running.\n", LightGreen);
       while (true) {
       g_server->poll();
         std::this_thread::sleep_for(std::chrono::milliseconds(1));
       }
  }
   else
    print::set_text("Failed to start server or proxy.\n", LightGreen);
}
