#ifndef TV_H
#define TV_H

class Tv;

class Remote
{
    public :
        enum State {OFF, ON};
        enum {MIN_VALUE, MAX_VALUE = 20};
        enum {ANTENNA, CABLE};
        enum Mode {TV, DVD};

    public :
        Remote(Mode m = TV) : mode_(m),
                              isInteractive_(false) {}

        bool volumeUp(Tv& t);
        bool volumeDown(Tv& t);

        void onOff(Tv& t);

        void channelUp(Tv& t);
        void channelDown(Tv& t);

        void setMode(Tv& t);
        void setInput(Tv& t);
        void setChannel(Tv& t, int c);

        void showInteractiveState() const;

    private :
        Mode mode_;
        bool isInteractive_;

        friend Tv;
};


class Tv
{
    public :
        enum State {OFF, ON};
        enum {MIN_VALUE, MAX_VALUE = 20};
        enum {ANTENNA, CABLE};
        enum {TV, DVD};

    public :
        Tv(int s = OFF, int mc = 125) : state_(s), volume_(5), maxChannel_(mc),
                                        channel_(2), mode_(CABLE),
                                        input_(TV) {}
        
        void onOff() { state_ = (state_ == ON) ? OFF : ON; }
        bool isOn() const { return state_ == ON; }

        void switchRemoteInteractive(Remote& r) const;

        bool volumeUp();
        bool volumeDown();

        void channelUp();
        void channelDown();

        void setMode() { mode_ = (mode_ == ANTENNA) ? CABLE : ANTENNA; }
        void setInput() { input_ = (input_ == TV) ? DVD : TV; }
        
        void settings() const;

    private :
        int state_;
        int volume_;
        int maxChannel_;
        int channel_;
        int mode_;
        int input_;

        friend Remote;
};

inline bool Remote::volumeUp(Tv& t) { return t.volumeUp(); }
inline bool Remote::volumeDown(Tv& t) { return t.volumeDown(); }
inline void Remote::onOff(Tv& t) { t.onOff(); }
inline void Remote::channelUp(Tv& t) { t.channelUp(); }
inline void Remote::channelDown(Tv& t) { t.channelDown(); }
inline void Remote::setMode(Tv& t) { t.setMode(); }
inline void Remote::setInput(Tv& t) { t.setInput(); }
inline void Remote::setChannel(Tv& t, int c) { t.channel_ = c; }

#endif