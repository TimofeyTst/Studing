from telebot import TeleBot
from telebot import types

TOKEN = "5557079358:AAHKgPej8q5-TPYgZsV4YRSp0Uy0Zy4xo3Y"
bot = TeleBot(TOKEN)

@bot.message_handler(commands=['start'])
def onStart(message):
    markup = types.ReplyKeyboardMarkup(resize_keyboard=True)
    for i in range(2):
        markup.add(types.KeyboardButton("View"),
                    types.KeyboardButton("Add"),
                    types.KeyboardButton("Erase"))
    markup.add('Am I?', 'Am you?')
    bot.send_message(message.chat.id, 'I am Artem - the best thing you might know', reply_markup=markup)

@bot.message_handler(content_types='text')
def ViewOnPressed(message):
    if message.text=='View':
        bot.send_message(message.chat.id, "Let`s View a big house")
    x = PrettyTable()
    x.field_names = ['Month', 'Lose', 'Get', 'Total']
    x.add_row(['August', '25000', '30000', '5000'])
    x.add_row(['September', '25000', '30000', '5000'])
    x.add_row(['October', '25000', '30000', '5000'])

    bot.send_message(message.chat.id, x)
    print(x)

if __name__ == '__main__':
    bot.infinity_polling()