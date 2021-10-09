#include <iostream>

#include "tv.h"


int main() {
    Tv s42;
    std::cout << R"(Initial settings for 42" TV:)" << std::endl;
    s42.settings();
    s42.onOff();
    s42.channelUp();
    std::cout << "\nAdjusted settings for 42\" TV:\n";

    s42.settings();
    Remote grey;
    grey.setChannel(s42, 10);
    grey.volumeUp(s42);
    grey.volumeUp(s42);
    std::cout << "\n42\" settings after using remote:\n";

    s42.settings();
    Tv s58(Tv::ON);
    s58.setMode();
    grey.setChannel(s58, 28);
    std::cout << "\n58\" settings:\n";
    s58.settings();
    
    std::cout << "\nCheck remote interactive mode state:\n";
    grey.showInteractiveState();
    std::cout << "Toggle remote mode...\n";
    s58.switchRemoteInteractive(grey);
    grey.showInteractiveState();


    return 0;
}