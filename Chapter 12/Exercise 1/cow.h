class Cow
{
    public :
        Cow() : name(), hobby(nullptr), weight(0.0) {}
        Cow(const char* name, const char* hobby, double weight);
        Cow(const Cow&);
        ~Cow();

        Cow& operator=(const Cow&);
        void showCow() const;

    private :
        char name[20];
        char* hobby;
        double weight;
};
