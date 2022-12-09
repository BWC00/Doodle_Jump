#ifndef DOODLE_JUMP_VIEW_CONCRETEFACTORY_aaH
#define DOODLE_JUMP_VIEW_CONCRETEFACTORY_aaH

#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <array>
//#include <random>
#include <exception>
namespace view {
namespace Data {
/*    class MissingAsset : public std::exception {
    private:
        const std::string m_error;
    public:
        explicit MissingAsset(const std::string &path) : m_error("missing asset : " + path) {}
        ~MissingAsset() override = default;
        [[nodiscard]] inline const char *what() const noexcept override {return m_error.c_str();}
    };*/

    //inline sf::Texture backgroundTexture{};
    inline sf::Texture rightTexture;
    inline sf::Texture leftTexture;
    inline sf::Texture platformTexture;
    inline sf::Texture verticalPlatformTexture;
    inline sf::Texture horizontalPlatformTexture;
    inline sf::Texture voidPlatformTexture;
    inline sf::Texture bonusSpringTexture;
    inline sf::Texture bonusJetpackTexture;
    inline sf::Texture temporaryPlatformTexture;
    inline sf::Texture bonusHPTexture;
    inline sf::Texture bonusSpikeTexture;
    inline sf::Texture horizontalTeleportPlatformTexture;
    inline sf::Texture verticalTeleportPlatformTexture;
    inline sf::Texture bonusSimpleEnemyTexture;
    inline sf::Texture bonusComplexEnemyTexture;
    //inline sf::Texture federBoostTexture{};
    //inline sf::Texture federBoostUpTexture{};
    //inline sf::Texture trampolineBoostTexture{};
    //inline sf::Texture trampolineBoostUpTexture{};
    //inline sf::Texture gameOverTexture{};
    //inline sf::Texture playAgainTexture{};
    inline sf::Texture tile;
    //inline std::array<sf::Texture, 4> brokenPlatformTextures{};
    //inline std::array<sf::Texture, 3> explosivePlatformTextures{};

    inline sf::Font font;

    inline sf::SoundBuffer jumpSoundBuffer;
    inline sf::SoundBuffer fallSoundBuffer;
    //inline sf::SoundBuffer platformBreakSoundBuffer{};
    //inline sf::SoundBuffer platformExplosionSoundBuffer{};
    //inline sf::SoundBuffer federSoundBuffer{};
    //inline sf::SoundBuffer trampolineSoundBuffer{};

    //inline sf::Sound platformBreakSound{};
    //inline sf::Sound platformExplosionSound{};

    void load();

    template<typename T>
    void loadAsset(T &asset, const std::string &path)
    {
        if (!asset.loadFromFile(path)) {}
            //throw MissingAsset(path);
    }
};
}

#endif