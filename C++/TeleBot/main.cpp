#include <stdio.h>
#include <iostream>
#include <tgbot/tgbot.h>
#include <fstream>

//For logs
    void add_user(std::string text, std::string file_name = "logs.txt");
    void add_message(std::string text, std::string file_name = "Messages.txt");
//
void addEvents(TgBot::Bot &bot);

//************************************************************************************//

int main() {
    TgBot::Bot bot("5557079358:AAHKgPej8q5-TPYgZsV4YRSp0Uy0Zy4xo3Y");
    addEvents(bot);

    try 
    {
        std::cout << "Bot username: " << bot.getApi().getMe()->username.c_str() << std::endl;
        TgBot::TgLongPoll longPoll(bot);
        size_t iter = 1;
        while (true) {
            std::cout << "\nLong poll iter #" << iter << std::endl;
            iter++;
            longPoll.start();
        }
    } catch (TgBot::TgException& e) 
    {
        std::cout << "Error ditacted: " << e.what() << std::endl;
    }
    return 0;
}

//************************************************************************************//
void addEvents(TgBot::Bot &bot)
{
    bot.getEvents().onCommand("start", // std::initializer_list<std::string> 
    [&bot](TgBot::Message::Ptr message) 
    {
        bot.getApi().sendMessage(message->chat->id, "Welcome. My name is Status");
    });
    

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) 
    {
        
        if (StringTools::startsWith(message->text, "/start")) {
            std::cout << "NEW USER: " << message->text.c_str() << "\tChat id: " << message->chat->id << std::endl;
            add_user("Chat id: " + std::to_string(message->chat->id));
            return;
        }
        else {
            std::cout << "User wrote: " << message->text.c_str() << "\tChat id: " << message->chat->id << std::endl;
            bot.getApi().sendMessage(message->chat->id, "Твое сообщение было: " + message->text);
            add_message("Chat id: " + std::to_string(message->chat->id) + "\n\tMessage: " + message->text.c_str());
        }
    });


};
// For logs
    void add_user(std::string text, std::string file_name) {
        std::ofstream file;
        try {
            file.open("__" + file_name, std::ios::app);
            file << text << '\n';            
        } catch (const std::exception &e) 
        {
            std::cout << e.what() << "\tError: Can`t open file: " << file_name << std::endl;
        }
    }
    void add_message(std::string text, std::string file_name)
    {
        add_user(text, file_name);
    }
//