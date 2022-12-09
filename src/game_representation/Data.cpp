#include "Data.h"

void view::Data::load()
{
    loadAsset(rightTexture, "../Data/Texture/right.png");
    loadAsset(leftTexture, "../Data/Texture/left.png");
    loadAsset(platformTexture, "../Data/Texture/platform.png");
    loadAsset(horizontalPlatformTexture, "../Data/Texture/horizontal_platform.png");
    loadAsset(verticalPlatformTexture, "../Data/Texture/vertical_platform.png");
    loadAsset(bonusSpringTexture, "../Data/Texture/jetpack.png");
    loadAsset(tile, "../Data/Texture/tile.png");
    loadAsset(temporaryPlatformTexture, "../Data/Texture/temp.png");
    loadAsset(bonusJetpackTexture, "../Data/Texture/spring.png");
    loadAsset(bonusHPTexture, "../Data/Texture/HP.png");
    loadAsset(bonusSpikeTexture, "../Data/Texture/spike.png");
    loadAsset(horizontalTeleportPlatformTexture, "../Data/Texture/HorizontalTeleport.png");
    loadAsset(verticalTeleportPlatformTexture, "../Data/Texture/VerticalTeleport.png");
    loadAsset(bonusSimpleEnemyTexture, "../Data/Texture/SimpleEnemy.png");
    loadAsset(bonusComplexEnemyTexture, "../Data/Texture/ComplexEnemy.png");
    //loadAsset(voidPlatformTexture, "resource/void_platform.png");
/*    loadAsset(backgroundTexture, "resource/background.png");
    loadAsset(federBoostTexture, "resource/feder.png");
    loadAsset(federBoostUpTexture, "resource/feder_up.png");
    loadAsset(trampolineBoostTexture, "resource/trampoline.png");
    loadAsset(trampolineBoostUpTexture, "resource/trampoline_up.png");
    loadAsset(gameOverTexture, "resource/game_over.png");
    loadAsset(playAgainTexture, "resource/play_again.png");

    for (size_t i = 0; i < 4; i++)
        loadAsset(brokenPlatformTextures[i], "resource/broken_platform" + std::to_string(i) + ".png");
    for (size_t i = 0; i < 3; i++)
        loadAsset(explosivePlatformTextures[i], "resource/explosive_platform" + std::to_string(i) + ".png");*/

    loadAsset(font, "../Data/Font/arial.ttf");
/*
    loadAsset(platformBreakSoundBuffer, "resource/platform_break.wav");
    loadAsset(platformExplosionSoundBuffer, "resource/exploding_platform.wav");
    loadAsset(jumpSoundBuffer, "../Data/Audio/jump.wav");
    loadAsset(fallSoundBuffer, "../Data/Audio/fall.wav");
    loadAsset(federSoundBuffer, "resource/feder.wav");
    loadAsset(trampolineSoundBuffer, "resource/trampoline.wav");

    platformBreakSound.setBuffer(platformBreakSoundBuffer);
    platformExplosionSound.setBuffer(platformExplosionSoundBuffer);*/
}
