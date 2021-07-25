"""
*********************************************************************
Email sending alarm - integrated with ArduinoUNO + HC-SR04
(c) Copyright (c) 2021 Pedro Salviano Santos
License: MIT.
*********************************************************************

To be able to use it properly:
PLEASE READ THE DOCUMENTATION ON github.com/P-py/arduino/base_com_emailnotify.

"""

import smtplib
from email.message import EmailMessage

def email_send(subject, body, to):
    #Create the message and sets the body/content of it
    message = EmailMessage()
    message.set_content(body)
    message['subject'] = subject
    message['to'] = to

    """
    If you want to use it you'll need to change this variables.

    By knowing that, PLEASE READ THE DOCUMENTATION ON github.com/P-py/arduino/base_com_emailnotify.

    PLEASE READ THE DOCUMENTATION ON github.com/P-py/arduino/base_com_emailnotify.
    PLEASE READ THE DOCUMENTATION ON github.com/P-py/arduino/base_com_emailnotify.
    PLEASE READ THE DOCUMENTATION ON github.com/P-py/arduino/base_com_emailnotify.
    """
    user = "###"
    password = "###"
    message['from'] = user

    server = smtplib.SMTP("smtp.gmail.com", 587)
    #Gmail requires
    server.starttls()
    server.login(user, password)
    server.send_message(message)
    server.quit()

if __name__ == "__main__":
    email_send("Testing SMTP - python", "This is a test of SMTPlib in python", "pedrosalviano170@gmail.com")

