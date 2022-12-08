import speech_recognition as sr
import requests

r = sr.Recognizer()

#with sr.Microphone() as source:
 #   print("Say something!")
  #  audio = r.listen(source)

try:
    #text = r.recognize_google(audio)
    text = input()
    print("You said: " + text)

    # Parse the recognized text to control the servos
    if "servo one" in text:
        pos = text.split()[-1]
        url = "http://192.168.29.14/servo1?pos=" + pos
        response = requests.get(url)
        print(response.text)
    elif "servo two" in text:
        pos = text.split()[-1]
        url = "http://192.168.29.14/servo2?pos=" + pos
        response = requests.get(url)
        print(response.text)
    elif "servo three" in text:
        pos = text.split()[-1]
        url = "http://192.168.29.14/servo3?pos=" + pos
        response = requests.get(url)
        print(response.text)
except sr.UnknownValueError:
    print("Could not understand audio")
except sr.RequestError as e:
    print("Error: Could not request results from Google Speech Recognition service; {0}".format(e))
