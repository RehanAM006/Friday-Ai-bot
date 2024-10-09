import serial
import pyttsx3

class JarvisConfig:
    def __init__(self):
        self.ROBOT_NAME = 'jarvis'

        # Greetings
        self.hi = ["hi", "hello", "hey", "how you doing?"]
        self.bye = ["tata", "hasta la vista"]
        self.r_u_there = ['you there']


        # Initializing text-to-speech engine
        self.engine = pyttsx3.init('sapi5')
        self.voices = self.engine.getProperty('voices')
        self.engine.setProperty('voice', 'HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\TTS_MS_EN-US_DAVID_11.0')

        # Connect with NaNo motor driver board over serial communication
        try:
            self.port = serial.Serial("COM11", 9600)
            print("Physical body connected.")
        except serial.SerialException:
            print("Unable to connect to my physical body")
            self.port = None