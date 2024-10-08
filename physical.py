# jarvis_commands.py

from jarvis_utils import speak, config

def handle_commands(user_query):
    """Handle various commands received from the user"""

    if "created" in user_query and config.ROBOT_NAME in user_query:
        if config.port:
            config.port.write(b'g')
        speak("I was created by Rehaan")

    elif "you" in user_query and "good" in user_query:
        speak("What can I say? Thank you.")
        if config.port:
            config.port.write(b'y')

    elif "dance" in user_query and config.ROBOT_NAME in user_query:
        if config.port:
            config.port.write(b'c')

    elif user_query == config.ROBOT_NAME:
        if config.port:
            config.port.write(b'h')

    elif "idiot" in user_query:
        speak("How dare you?")
        if config.port:
            config.port.write(b"e")

    elif "take over" in user_query:
        speak("You creating me got me closer to our goals.")

    elif "left" in user_query:
        if config.port:
            config.port.write(b'k')

    elif "right" in user_query:
        if config.port:
            config.port.write(b'l')

    elif "forward" in user_query:
        if config.port:
            config.port.write(b'j')

    elif "dab" in user_query:
        if config.port:
            config.port.write(b'g')

    elif "sit" in user_query:
        if config.port:
            config.port.write(b'a')

    elif "exercise" in user_query:
        if config.port:
            config.port.write(b'o')

    elif "ape" in user_query:
        if config.port:
            config.port.write(b'i')

    elif "bow" in user_query:
        if config.port:
            config.port.write(b'y')

    elif "shake" in user_query and "hand" in user_query:
        if config.port:
            config.port.write(b's')

    elif "hand" in user_query and "down" in user_query:
        if config.port:
            config.port.write(b'd')
