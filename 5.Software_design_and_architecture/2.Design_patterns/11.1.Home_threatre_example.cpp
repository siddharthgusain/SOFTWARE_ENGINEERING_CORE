#include <iostream>
#include <string>

// Subsystem 1: DVD Player
class DVDPlayer
{
public:
    void on()
    {
        std::cout << "DVD Player is ON\n";
    }

    void play()
    {
        std::cout << "DVD Player is playing the movie\n";
    }

    void stop()
    {
        std::cout << "DVD Player has stopped playing\n";
    }

    void off()
    {
        std::cout << "DVD Player is OFF\n";
    }
};

// Subsystem 2: Projector
class Projector
{
public:
    void on()
    {
        std::cout << "Projector is ON\n";
    }

    void setInputSource(const std::string &source)
    {
        std::cout << "Projector input source set to " << source << "\n";
    }

    void off()
    {
        std::cout << "Projector is OFF\n";
    }
};

// Subsystem 3: Sound System
class SoundSystem
{
public:
    void on()
    {
        std::cout << "Sound System is ON\n";
    }

    void setVolume(int level)
    {
        std::cout << "Sound System volume set to " << level << "\n";
    }

    void off()
    {
        std::cout << "Sound System is OFF\n";
    }
};

// Subsystem 4: Lights
class Lights
{
public:
    void dim()
    {
        std::cout << "Lights are dimmed\n";
    }

    void on()
    {
        std::cout << "Lights are ON\n";
    }
};

// Facade: Home Theater System
class HomeTheaterFacade
{
private:
    DVDPlayer dvdPlayer; // Aggregation not composition
    Projector projector;
    SoundSystem soundSystem;
    Lights lights;

public:
    void watchMovie()
    {
        std::cout << "Preparing to watch the movie...\n";
        lights.dim();
        projector.on();
        projector.setInputSource("DVD");
        soundSystem.on();
        soundSystem.setVolume(10);
        dvdPlayer.on();
        dvdPlayer.play();
    }

    void endMovie()
    {
        std::cout << "Ending the movie...\n";
        dvdPlayer.stop();
        dvdPlayer.off();
        soundSystem.off();
        projector.off();
        lights.on();
    }
};

int main()
{
    // Using the Facade
    HomeTheaterFacade homeTheater;
    homeTheater.watchMovie();
    std::cout << "\n";
    homeTheater.endMovie();

    return 0;
}
