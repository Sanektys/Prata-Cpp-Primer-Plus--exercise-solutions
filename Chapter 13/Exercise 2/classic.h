class Cd
{
    public :
        Cd(const char* perf, const char* label, int select, double playtime);
        Cd(const Cd&);
        Cd();
        virtual ~Cd();

        virtual void report() const;

        const Cd& operator=(const Cd&);

    private :
        char* performance_;
        char* label_;
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
        Classic();
       ~Classic() override;

        void report() const override;

        const Classic& operator=(const Classic&);

    private :
        char* mainComposition_;
};
