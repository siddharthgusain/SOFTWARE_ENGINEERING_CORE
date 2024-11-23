#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Observer Interface
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~Observer() = default;
};

// Subject Interface
class Subject {
public:
    virtual void attach(shared_ptr<Observer> observer) = 0;
    virtual void detach(shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;
};

// Concrete Subject
class WeatherData : public Subject {
private:
    vector<shared_ptr<Observer>> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    void attach(shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void detach(shared_ptr<Observer> observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (auto& observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notify();
    }
};

// Concrete Observer
class CurrentConditionsDisplay : public Observer {
private:
    float temperature;
    float humidity;

public:
    void update(float temp, float hum, float /*pressure*/) override {
        temperature = temp;
        humidity = hum;
        display();
    }

    void display() {
        cout << "Current conditions: " << temperature << "°C and " << humidity << "% humidity" << endl;
    }
};

class StatisticsDisplay : public Observer {
private:
    vector<float> temperatures;

public:
    void update(float temp, float /*humidity*/, float /*pressure*/) override {
        temperatures.push_back(temp);
        display();
    }

    void display() {
        float sum = 0;
        for (float temp : temperatures) {
            sum += temp;
        }
        float average = temperatures.empty() ? 0 : sum / temperatures.size();
        cout << "Average temperature: " << average << "°C" << endl;
    }
};

// Main function demonstrating the Observer Pattern
int main() {
    // Create a WeatherData object (Subject)
    WeatherData weatherData;

    // Create Observers
    auto currentDisplay = make_shared<CurrentConditionsDisplay>();
    auto statisticsDisplay = make_shared<StatisticsDisplay>();

    // Attach Observers to Subject
    weatherData.attach(currentDisplay);
    weatherData.attach(statisticsDisplay);

    // Simulate weather data updates
    weatherData.setMeasurements(25.0, 65.0, 1013.0);
    weatherData.setMeasurements(28.0, 70.0, 1012.0);
    weatherData.setMeasurements(22.0, 80.0, 1011.0);

    return 0;
}
