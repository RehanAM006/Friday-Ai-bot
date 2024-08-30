# Main script

# Libraries
import os
import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import random
import cv2
import pywhatkit
import win32print
import win32ui

# Functions
from weather import weather
from extract_city import extract_city
from config import JarvisConfig  # Import the configuration
from jarvis_commands import handle_commands  # Physical Commands
from jarvisDesk import handle_desk_commands  # Desktop Commands
from jarvis_utils import take_command, wish_me, get_current_date, send_whatsapp_message, get_future_date, capture_photo
from printer import print_paragraph  # Update to import the print_paragraph function

# Initialize the JarvisConfig class
config = JarvisConfig()

if __name__ == "__main__":
    wish_me()
    while True:
        user_query = take_command()

        if user_query == "none":
            continue

        # Handle printing commands
        print_paragraph(user_query)

        # Handle desktop and physical commands
        handle_desk_commands(user_query)
        handle_commands(user_query)
