#include <stdexcept>
#include <string>


class Sales
{
    public :
        enum {MONTHS = 12};

    public :
        explicit Sales(int year = 0);
        Sales(int year, const double* gross, int n);

        virtual ~Sales() {}

        int year() const { return year_; }

        virtual double operator[](int i) const;
        virtual double& operator[](int i);

    public :
        class BadIndex : public std::logic_error
        {
            public :
                explicit BadIndex(int ix, const std::string& str = "Index"
                                          " error in Sales object\n");
                
                virtual ~BadIndex() noexcept {}

                int badIndexValue() const { return badIndex_; }

            private :
                int badIndex_;
        };

    private :
        double gross_[MONTHS];
        int year_;
};


class LabeledSales : public Sales
{
    public :
        explicit LabeledSales(const std::string& label = "none", int year = 0);
        LabeledSales(const std::string& label, int year,
                     const double* gross, int n);
        
        virtual ~LabeledSales() override {}

        const std::string& label() const { return label_; }

        virtual double operator[](int i) const override;
        virtual double& operator[](int i) override;

    public :
        class LabelBadIndex : public Sales::BadIndex
        {
            public :
                LabelBadIndex(const std::string& lb, int ix,
                              const std::string& str = "Index error"
                              " in LabeledSales objects\n");
                virtual ~LabelBadIndex() noexcept {}
                
                const std::string& labelValue() const { return labelValue_; }

            private :
                std::string labelValue_;
        };

    private :
        std::string label_;
};