#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

PROCESS_INFORMATION procinfo = {0};
STARTUPINFOA sti = {0};
SECURITY_ATTRIBUTES sats;
HANDLE in_r, in_w, out_r, out_w; 
char sfPath[50] = "stockfish_13_win_x64_bmi2.exe";
BYTE buffer[2048];
DWORD write, excode, read, available;

void startFish(char sfPath[]){
  sats.nLength = sizeof(sats);
  sats.bInheritHandle = 1;
  sats.lpSecurityDescriptor = 0;
  
  CreatePipe(&out_r, &out_w, &sats, 0);
  CreatePipe(&in_r, &in_w, &sats, 0);

  sti.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
  sti.wShowWindow = SW_HIDE;
  sti.hStdInput = in_r;
  sti.hStdOutput = out_w;
  sti.hStdError = out_w;

  CreateProcessA(0, sfPath, 0, 0, 1, 0, 0, 0, &sti, &procinfo);
}

std::string fishMove(std::string movehistory){
  std::string q; //input on stockfish
  int depth = 10;
  q="position startpos moves " + movehistory + "\ngo depth " + std::to_string(depth) + "\n";
  std::string resposta;
  WriteFile(in_w, q.c_str(), q.length(), &write, 0);
  Sleep(500);
  PeekNamedPipe(out_r, buffer, sizeof(buffer), &read, &available, 0);
  do{
    ZeroMemory(buffer, sizeof(buffer));
    if(!ReadFile(out_r, buffer, sizeof(buffer), &read, 0) || !read) break;
    buffer[read]=0;
    resposta+=(char*)buffer;
  }
  while((read >= sizeof(buffer)) && (resposta.find("bestmove")==std::string::npos));

  int n = resposta.find("bestmove");
  if (n!=-1)
    return resposta.substr(n+9, 4);
  else
    return "NoMoveError";
}

/*
position startpos moves e2e4 e7e5
go depth 8
*/
