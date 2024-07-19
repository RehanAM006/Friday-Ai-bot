import requests

def weather(city):
    api_key = "48e895ba1790f7cf1708f66ec4135d85"  # Replace with your OpenWeatherMap API key
    base_url = "http://api.openweathermap.org/data/2.5/weather"
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

# Example usage
city = "islamabad"
print(weather(city))
