class Cd
{
    public :
        Cd(const char* perf, const char* label, int select, double playtime);
        Cd(const Cd&);
        Cd() = default;
        virtual ~Cd() {}

        virtual void report() const;

        const Cd& operator=(const Cd&);

    private :
        char performance_[50];
        char label_[20];
        int selections_;
        double playtime_;
};


class Classic : public Cd
{
    public :
        Classic(const char* mainComp, const char* perf, const char* label,
                int select, double playtime);
        explicit Classic(const Cd& cd, const char* mainComp = "none");
        Classic(const Classic&);
        Classic() = default;
        ~Classic() override {}

        void report() const override;

        const Classic& operator=(const Classic&);

    private :
        char mainComposition_[40];
};
