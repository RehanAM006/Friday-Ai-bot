# jarvis_commands.py
import pywhatkit, wikipedia,os
import random
import webbrowser
from jarvis_utils import take_command,speak, get_current_date, send_whatsapp_message, get_future_date, capture_photo, extract_city, weather, config

def handle_desk_commands(user_query):
    """Process user commands and take appropriate actions"""
    
    if "hey" in user_query:
        if config.port:
            config.port.write(b'h')
        speak(f"{random.choice(config.hi)}, I am ready")

    elif "date" in user_query and config.ROBOT_NAME in user_query and "today" in user_query:
        current_date = get_current_date()
        speak(f"Today's date is {current_date}")

    # Weather
    elif "weather" in user_query and config.ROBOT_NAME in user_query:
        city_name = extract_city(user_query)
        if city_name:
            weather_info = weather(city_name)
            print(weather_info)
            speak(weather_info)
        else:
            speak("Please specify a city to get the weather information.")

    elif "message" in user_query and "baba" in user_query and config.ROBOT_NAME in user_query:
        recipient_phone_number = "03335499594"  # Replace with the recipient's phone number
        message_content = extract_city(user_query)  # Use your function to extract the message content
        send_whatsapp_message(recipient_phone_number, message_content)

    elif "date" in user_query and "after" in user_query:
        try:
            days = int(
                user_query.replace("date", "").replace("after", "").replace("days", "").replace(config.ROBOT_NAME,
                                                                                                "").replace(
                    "what", "").replace("is", "").replace("the", "").strip())
            future_date = get_future_date(days)
            if config.port:
                config.port.write(b'u')
            speak(f"The date after {days} days is {future_date}")
        except ValueError:
            speak("Sorry, I couldn't understand the number of days.")

    elif "play" in user_query and config.ROBOT_NAME in user_query and "youtube" in user_query:
        video_query = user_query.replace("play", "").replace(config.ROBOT_NAME, "").replace("on youtube", "").strip()
        speak(f"Playing {video_query} on YouTube")
        if config.port:
            config.port.write(b'u')
        pywhatkit.playonyt(video_query)
        if config.port:
            config.port.write(b'l')

    elif "info" in user_query and config.ROBOT_NAME in user_query:
        search_query = user_query.replace("info", "").replace(config.ROBOT_NAME, "").strip()
        if config.port:
            config.port.write(b'u')
        speak("Getting information")
        results = wikipedia.summary(search_query, sentences=2)
        speak("According to Wikipedia...")
        print(results)
        speak(results)

    elif "search" in user_query and config.ROBOT_NAME in user_query:
        search_query = user_query.replace("search", "").replace(config.ROBOT_NAME, "").strip()
        if config.port:
            config.port.write(b'u')
        speak("Searching...")
        pywhatkit.search(search_query)
        if config.port:
            config.port.write(b'l')

    elif config.ROBOT_NAME in user_query and "music" in user_query:
        speak("What would you like to listen to?")
        music_query = take_command().lower()
        if music_query == "none":
            return
                
        if "english" in music_query:
            music_dir = "F:\\ENTERTAINMENT\\songs\\english"
            songs = os.listdir(music_dir)
            print(songs)
            if config.port:
                config.port.write(b'u')
            os.startfile(os.path.join(music_dir, songs[0]))
            speak("Playing English music.")
        elif "indian" in music_query:
            music_dir2 = "F:\\ENTERTAINMENT\\songs\\indian"
            songs2 = os.listdir(music_dir2)
            print(songs2)
            if config.port:
                config.port.write(b'u')
            os.startfile(os.path.join(music_dir2, songs2[0]))
            speak("Playing Indian music.")
        if config.port:
            config.port.write(b'c')
            speak("Get ready to dance")

    elif "open" in user_query and config.ROBOT_NAME in user_query:
        website_query = user_query.replace("open", "").replace(config.ROBOT_NAME, "").strip().rstrip('/')
        url = f"http://{website_query}.com"
        if config.port:
            config.port.write(b'u')
        speak("Opening the website")
        webbrowser.open(url)
        if config.port:
            config.port.write(b'd')

    elif "capture" in user_query:
        photo_file_path = "F:\\Robot\\photo.jpg"  # Specify the correct file path
        capture_photo(photo_file_path)
