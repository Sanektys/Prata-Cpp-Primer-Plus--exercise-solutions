#pragma once


class Golf {
    public :
        Golf() { fullname_[0] = '\0'; handicap_ = 0; }
        Golf(const char* name, int handicap);

        int setGolf();
        void handicap(int handicap) { handicap_ = handicap; }
        void show() const;

    private :
        static const int LEN = 40;
        char fullname_[LEN];
        int handicap_;
};
