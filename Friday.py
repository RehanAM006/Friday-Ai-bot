import os
import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import serial
import random
import cv2
import pywhatkit
import requests


# Robot name
robot_name = 'jarvis'

# Greetings
hi = ["hi", "hello", "hey", "how you doing?"]
bye = ["tata", "hasta la vista"]
r_u_there = ['you there']



# Initializing text-to-speech engine
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# Set the voice using its ID
engine.setProperty('voice', 'HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\TTS_MS_EN-US_DAVID_11.0')


# Alternatively, set the voice using its index in the voices list
# engine.setProperty('voice', voices[0].id)
# [1] for female, [0] for male


def speak(audio):
    """Convert text to speech"""
    engine.say(audio)
    engine.runAndWait()


# Connect with NaNo motor driver board over serial communication
try:
    port = serial.Serial("COM11", 9600)
    print("Physical body connected.")
except serial.SerialException:
    print("Unable to connect to my physical body")
    port = None


def wishMe():
    """Wish the user based on the current time"""
    hour = int(datetime.datetime.now().hour)
    if 0 <= hour < 12:
        speak("Good Morning!")
    elif 12 <= hour < 18:
        speak("Good Afternoon!")
    else:
        speak('Good Evening!')
    speak("What's up Sir?")
    if port:
        port.write(b'h')


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


def weather(city):

    api_key = ""  # Replace with your OpenWeatherMap API key
    base_url = ""
    params = {
        "q": city,
        "appid": api_key,
        "units": "metric"  # Units can be "metric" for Celsius or "imperial" for Fahrenheit
    }

    try:
        response = requests.get(base_url, params=params)
        weather_data = response.json()

        if response.status_code == 200:
            temperature = weather_data['main']['temp']
            description = weather_data['weather'][0]['description']
            return f"The current temperature in {city} is {temperature}°C and the weather is {description}."
        else:
            return f"Failed to retrieve weather information for {city}. Error: {response.status_code}"
    except requests.RequestException as e:
        return f"An error occurred: {e}"

def takeCommand():
    """Listen and recognize voice command"""
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening....")
        r.pause_threshold = 0.5
        r.energy_threshold = 1000
        audio = r.listen(source)
    try:
        print("Recognizing....")
        query1 = r.recognize_google(audio, language='en-us')
        print(f"User said: {query1}\n")
    except sr.UnknownValueError:
        print("Could not understand the audio")
        return "NONE"
    except sr.RequestError as e:
        print(f"Could not request results; {e}")
        return "NONE"
    return query1.lower()


def get_current_date():
    """Get the current date in a readable format"""
    today = datetime.date.today()
    return today.strftime("%B %d, %Y")

def send_whatsapp_message(phone_number, message):
    # Remove any unnecessary phrases or words here if needed
    # For example, you may want to strip "send message to" or similar phrases
    # Ensure phone number is in international format without '+' or '00'
    pywhatkit.sendwhatmsg_instantly(f"+{phone_number}", message, 10, tab_close=True)
    print(f"Message '{message}' sent to {phone_number} via WhatsApp.")

def get_future_date(day1):
    """Get the date after a certain number of days"""
    today = datetime.date.today()
    future_date1 = today + datetime.timedelta(days=day1)
    return future_date1.strftime('%A, %B %d, %Y')


def extract_city(query):
    # Define words or phrases to remove
    remove_words = ["weather", "in", "for", "about", "tell me", "what", "is", "the", robot_name, "send", "message", "to", "Baba"]

    # Split the query into words
    words = query.lower().split()

    # Use list comprehension to filter out remove_words
    cleaned_words = [word for word in words if word not in remove_words]

    # Join cleaned_words into a string and return
    cleaned_query = " ".join(cleaned_words)

    return cleaned_query


if __name__ == "__main__":
    wishMe()
    while True:
        query = takeCommand()

        if query == "none":

            continue

        # Logic to execute tasks:
        if "hey" in query:
            if port:
                port.write(b'h')
            speak(f"{random.choice(hi)}, I am ready")

        elif "date" in query and robot_name in query and "today" in query:
            current_date = get_current_date()
            speak(f"Today's date is {current_date}")

        elif "weather" in query and robot_name in query:
            city = extract_city(query)
            if city:
                weather_info = weather(city)
                print(weather_info)
                speak(weather_info)

            else:
                speak("Please specify a city to get the weather information.")

        elif "message" and "baba" and robot_name in query:
            phone_number = ""  # Replace with the recipient's phone number
            message = extract_city(query)  # Use your function to extract the message content
            send_whatsapp_message(phone_number, message)


        elif "date" in query and "after" in query:
            try:
                days = int(query.replace("date", "").replace("after", "").replace("days", "").replace(robot_name, "").replace("what", "").replace("is", "").replace("the", "").strip())
                future_date = get_future_date(days)
                if port:
                    port.write(b'u')
                speak(f"The date after {days} days is {future_date}")
            except ValueError:
                speak("Sorry, I couldn't understand the number of days.")

        elif "play" in query and robot_name in query and "youtube" in query:
            video_query = query.replace("play", "").replace(robot_name, "").replace("on youtube", "").strip()
            speak(f"Playing {video_query} on YouTube")
            if port:
                port.write(b'u')
            pywhatkit.playonyt(video_query)
            if port:
                port.write(b'l')

        elif "info" in query and robot_name in query:
            search_query = query.replace("info", "").replace(robot_name, "").strip()
            if port:
                port.write(b'u')
            speak("Getting information")
            results = wikipedia.summary(search_query, sentences=2)
            speak("According to Wikipedia...")
            print(results)
            speak(results)

        elif "search" in query and robot_name in query:
            search_query = query.replace("search", "").replace(robot_name, "").strip()
            if port:
                port.write(b'u')
            speak("Searching...")
            pywhatkit.search(search_query)
            if port:
                port.write(b'l')

        elif robot_name in query and "music" in query:
            speak("What would you like to listen to?")
            music_query = takeCommand().lower()
            if music_query == "none":
                continue
            if "english" in music_query:
                music_dir = ""
                songs = os.listdir(music_dir)
                print(songs)
                if port:
                    port.write(b'u')
                os.startfile(os.path.join(music_dir, songs[0]))
                speak("Playing English music.")
            elif "indian" in music_query:
                music_dir2 = ""
                songs2 = os.listdir(music_dir2)
                print(songs2)
                if port:
                    port.write(b'u')
                os.startfile(os.path.join(music_dir2, songs2[0]))
                speak("Playing Indian music.")
            if port:
                port.write(b'c')
                speak("Get ready to dance")

        elif "open" in query and robot_name in query:
            website_query = query.replace("open", "").replace(robot_name, "").strip().rstrip('/')
            url = f"http://{website_query}.com"
            if port:
                port.write(b'u')
            speak("Opening the website")
            webbrowser.open(url)
            if port:
                port.write(b'd')

        elif "created" in query and robot_name in query:
            if port:
                port.write(b'g')
            speak("I was created by Rehaan")

        elif "you" in query and "good" in query:
            speak("What can I say? Thank you.")
            if port:
                port.write(b'y')

        elif "dance" in query and robot_name in query:
            if port:
                port.write(b'c')

        elif query == robot_name:
            if port:
                port.write(b'h')

        elif "idiot" in query:
            speak("How dare you?")
            if port:
                port.write(b"e")

        elif "take over" in query:
            speak("You creating me got me closer to our goals.")

        elif "left" in query:
            if port:
                port.write(b'k')

        elif "right" in query:
            if port:
                port.write(b'l')

        elif "forward" in query:
            if port:
                port.write(b'j')

        elif "dab" in query:
            if port:
                port.write(b'g')

        elif "sit" in query:
            if port:
                port.write(b'a')

        elif "exercise" in query:
            if port:
                port.write(b'o')

        elif "ape" in query:
            if port:
                port.write(b'i')

        elif "bow" in query:
            if port:
                port.write(b'y')

        elif "shake" in query and "hand" in query:
            if port:
                port.write(b's')

        elif "hand" in query and "down" in query:
            if port:
                port.write(b'd')

        elif "capture" in query:
            photo_file_path = "F:\\Robot\\photo.jpg"  # Specify the correct file path
            capture_photo(photo_file_path)
