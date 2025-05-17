# Jarvis - Personal Assistant Robot

Jarvis is a personal assistant robot designed to perform a variety of tasks using voice commands. The assistant integrates several functionalities such as text-to-speech, speech recognition, web browsing, playing music, fetching information from Wikipedia, and face recognition. This project showcases how various Python libraries can be combined to create a versatile and interactive assistant.

---

## Features

| Feature                | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| **Voice Interaction**   | Communicate with Jarvis using voice commands.                               |
| **Text-to-Speech**      | Jarvis responds using a synthesized voice.                                  |
| **Date and Time**       | Get the current date or the date after a specified number of days.           |
| **Music Playback**      | Play music from YouTube or local directories.                               |
| **Web Browsing**        | Open websites using voice commands.                                         |
| **Information Retrieval** | Fetch summaries from Wikipedia.                                             |
| **Face Recognition**    | Recognize and identify faces using a webcam.                                |
| **Camera Control**      | Capture photos using a webcam.                                              |

---

## Libraries Used

| Library          | Purpose                                                        |
|------------------|----------------------------------------------------------------|
| **pyttsx3**      | Text-to-speech conversion.                                      |
| **speech_recognition** | Recognizing voice commands.                                 |
| **wikipedia**    | Fetching summaries from Wikipedia.                              |
| **webbrowser**   | Opening web pages.                                              |
| **serial**       | Communicating with external hardware.                           |
| **random**       | Generating random responses.                                    |
| **cv2 (OpenCV)** | Computer vision tasks such as capturing photos.                 |
| **pywhatkit**    | Playing YouTube videos.                                         |
| **face_recognition** | Recognizing and identifying faces using a webcam.           |

---

## Installation

1. **Prerequisites:**
    - Python 3.6+
    - Virtual Environment (recommended)

2. **Clone the Repository:**

    ```bash
    git clone https://github.com/RehanAM006/Friday-Ai-bot 
    cd Friday-Ai-bot
    ```

3. **Create a Virtual Environment (Optional but Recommended):**

    ```bash
    python3 -m venv env
    source env/bin/activate   # For Linux/macOS
    .\env\Scripts\activate    # For Windows
    ```

4. **Install the Required Libraries:**

    ```bash
    pip install -r requirements.txt
    ```

5. **Additional Setup:**
    - Install `PyAudio` for voice recognition (may require additional steps depending on your OS).
    - Install OpenCV (`cv2`) for face recognition and camera functionality.

---

## Usage

1. **Activate the Virtual Environment (if you created one):**

    ```bash
    source env/bin/activate   # For Linux/macOS
    .\env\Scripts\activate    # For Windows
    ```

2. **Run Jarvis:**

    ```bash
    python jarvis.py
    ```

3. **Example Voice Commands:**
    - "What is the time?"
    - "Play a song from YouTube."
    - "Tell me about Albert Einstein."
    - "Open Google."

---

## Contributing

Feel free to contribute to this project by opening issues or submitting pull requests. Please ensure that your contributions align with the project goals and guidelines.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
