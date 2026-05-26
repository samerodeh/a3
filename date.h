class Date {



    private: 

        int month;
        int day;
        int year;
    
    public: 

        Date(int month, int day, int year);
        ~Date();

        int get_month() const;
        int get_day() const;
        int get_year() const;

        void set_month(int month);
        void set_day(int day);
        void set_year(int year);

        void print();



};
