#include <iostream>


struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void showBox(box);
void setBoxVolume(box*);

int main() {
    box catCarrier{"Kotolampus ink", 0.8f, 0.35f, 1.2f};

    setBoxVolume(&catCarrier);
    showBox(catCarrier);


    return 0;
}

void showBox(box box) {
    std::cout << box.maker << std::endl;
    std::cout << "- box height: " << box.height << std::endl;
    std::cout << "- box widht: "  << box.width  << std::endl;
    std::cout << "- box length: " << box.length << std::endl;
    std::cout << "- volume: "     << box.volume << std::endl;
}

void setBoxVolume(box* box) {
    box->volume = box->height * box->width * box->length;
}
