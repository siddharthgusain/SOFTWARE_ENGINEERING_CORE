#include <iostream>
#include <string>
#include <memory>

// Target Interface
class MediaPlayer
{
public:
    virtual void play(const std::string &audioType, const std::string &fileName) = 0;
    virtual ~MediaPlayer() = default;
};

// Adaptee Class
class AdvancedMediaPlayer
{
public:
    void playMP4(const std::string &fileName)
    {
        std::cout << "Playing MP4 file: " << fileName << std::endl;
    }

    void playVLC(const std::string &fileName)
    {
        std::cout << "Playing VLC file: " << fileName << std::endl;
    }
};

// Adapter Class
class MediaPlayerAdapter : public MediaPlayer
{
private:
    std::unique_ptr<AdvancedMediaPlayer> advancedMediaPlayer; // Object Composition

public:
    MediaPlayerAdapter()
    {
        advancedMediaPlayer = std::make_unique<AdvancedMediaPlayer>();
    }

    void play(const std::string &audioType, const std::string &fileName) override
    {
        if (audioType == "mp4")
        {
            advancedMediaPlayer->playMP4(fileName); // Adapt MP4 functionality
        }
        else if (audioType == "vlc")
        {
            advancedMediaPlayer->playVLC(fileName); // Adapt VLC functionality
        }
        else
        {
            std::cout << "Unsupported format: " << audioType << std::endl;
        }
    }
};

// Client Code
int main()
{
    // Create an adapter
    std::unique_ptr<MediaPlayer> player = std::make_unique<MediaPlayerAdapter>();

    // Play different types of files
    player->play("mp4", "movie.mp4"); // Playing MP4 file
    player->play("vlc", "video.vlc"); // Playing VLC file
    player->play("mp3", "song.mp3");  // Unsupported format

    return 0;
}
