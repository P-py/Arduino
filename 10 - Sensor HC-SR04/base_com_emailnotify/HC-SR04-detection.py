"""
*********************************************************************
HC-SR04-detection - integrated with ArduinoUNO + HC-SR04
(c) Copyright (c) 2021 Pedro Salviano Santos
License: MIT.
*********************************************************************
"""
import serial #To comunicate with arduino board ~ https://pyserial.readthedocs.io/en/latest/pyserial.html
import time #Time management.
from emailAlarm import email_send #Sub-function to send email alert.

#Try to connect to the board
try:
    ser = serial.Serial("COM6")
    #Waits for the board reboot
    time.sleep(3)
#Caso não consiga se conectar imprime uma mensagem de erro
except:
    for i in range(3):
        print("A placa não está conectada ou está na porta errada! Conecte na porta COM6!!")
        break

#Loop infinito
while True:
    #Verifica se a placa está aberto e coloca isso em uma condicional
    state = ser.is_open
    if state:
        linha = ser.readline()
        linha = linha.decode()
        linha = linha.split(' ')
        print(' '.join(linha))
        if linha[0] == 'Com':
            for i in range(10):
                print("Enviando e-mail de ALERTA!")
            try:
                email_send('ALARME ATIVADO! Possível intruso no perímetro!', 'O sensor detectou um movimento acima do normal!', 'pedrosalviano170@gmail.com')
            except:
                print("Erro ao enviar o e-mail!")
            time.sleep(5)
    else:
        pass