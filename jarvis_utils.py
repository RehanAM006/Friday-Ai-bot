# jarvis_utils.py

import os
import pyttsx3
import datetime
import speech_recognition as sr
import cv2
import pywhatkit
import serial
import random
from weather import weather
#from extract_city import extract_city
from jarvis_config import JarvisConfig  # Import the JarvisConfig class

# Initialize the JarvisConfig class
config = JarvisConfig()

def speak(audio):
    """Convert text to speech"""
    config.engine.say(audio)
    config.engine.runAndWait()

def wish_me():
    """Wish the user based on the current time"""
    hour = int(datetime.datetime.now().hour)
    if 0 <= hour < 12:
        speak("Good Morning!")
    elif 12 <= hour < 18:
        speak("Good Afternoon!")
    else:
        speak('Good Evening!')
    speak("What's up Sir?")
    if config.port:
        config.port.write(b'h')

def capture_photo(file_path):
    """Capture photo using the webcam"""
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("Failed to open the camera")
        return
    ret, frame = cap.read()
    if ret:
        try:
            cv2.imwrite(file_path, frame)
            print("Photo captured and saved successfully")
        except cv2.error as e:
            print(f"Failed to save photo: {e}")
    else:
        print("Failed to capture photo")
    cap.release()

def take_command():
    """Listen and recognize voice command"""
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening....")
        r.pause_threshold = 0.5
        r.energy_threshold = 1000
        audio = r.listen(source)
    try:
        print("Recognizing....")
        command = r.recognize_google(audio, language='en-us')
        print(f"User said: {command}\n")
    except sr.UnknownValueError:
        print("Could not understand the audio")
        return "NONE"
    except sr.RequestError as e:
        print(f"Could not request results; {e}")
        return "NONE"
    return command.lower()

def get_current_date():
    """Get the current date in a readable format"""
    today = datetime.date.today()
    return today.strftime("%B %d, %Y")

def send_whatsapp_message(phone_number, message):
    """Send a WhatsApp message using pywhatkit"""
    pywhatkit.sendwhatmsg_instantly(f"+{phone_number}", message, 10, tab_close=True)
    print(f"Message '{message}' sent to {phone_number} via WhatsApp.")

def get_future_date(days):
    """Get the date after a certain number of days"""
    today = datetime.date.today()
    future_date1 = today + datetime.timedelta(days=days)
    return future_date1.strftime('%A, %B %d, %Y')


