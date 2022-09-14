t:
cd T:\Projects\C++\VS_Code_C++\TeleBot
wsl.exe g++ main.cpp -o telegram_bot --std=c++14 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto -lpthread
wsl.exe ./telegram_bot