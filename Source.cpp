#include <iostream>
#include <string>
#include <cmath>


class Fraction {
private:
    double chisl_;
    double znam_;

public:

     Fraction (double chisl, double znam) : chisl_(chisl), znam_( znam) {}
     Fraction(auto chisl, auto znam) : chisl_ (chisl), znam_( znam ) {}
     


    explicit Fraction(const std::string& str) {
        std::size_t  pos = str.find("/");
        if (pos == std::string::npos) {
            this-> chisl_ = stoi(str);  
            this->znam_ = 1;
        }
        else {
            this->chisl_ = stod (str.substr(0, pos));
            this->znam_ = std::stod(str.substr(pos + 1, str.length()));
        }
        if (znam_ == 0)
        {
            throw std::exception("Знаменатель не может быть 0");
        }
    }

    
    auto setChisl(auto chisl_)  {
        return this -> chisl_ = chisl_;
    }
    auto  setZnam(auto znam_) {
        return this->znam_ = znam_;
    }
    
    auto getChisl() const {
        return this->chisl_;
    }
    auto getZnam() const {
        return this->znam_;
    }

    void display () const 
    {
        std::cout << chisl_ << "/" << znam_ << std::endl;
    }

    void fraction () {
        if (abs(chisl_) >= abs(znam_)) {
           int x = chisl_ / znam_;
            std::cout << "Целая часть дроби: " << x << std::endl;
            this->chisl_ = fmod(abs(chisl_), abs(znam_));
            this->znam_ = abs(znam_);
            std::cout << "Нецелая часть дроби: " << chisl_ << "/" << znam_ << std::endl;
        }
        else
            std::cout << "Дробь правильная: " << chisl_ << "/" << znam_ << std::endl;
    }

    void fraction_obr() {
        std::swap(chisl_, znam_);
        std::cout << "Обратная дробь: " <<  chisl_ << "/" << znam_ << std::endl;
        }
    
    friend const Fraction operator * (const Fraction& one, const Fraction& two) {
        return Fraction(one.chisl_ * two.chisl_, one.znam_ * two.znam_);
    }

    friend const Fraction operator / (const Fraction& one, const Fraction& two) {
        return Fraction(one.chisl_ * two.znam_, one.znam_ * two.chisl_);
    }
    
    friend const Fraction operator + (const Fraction& one, const Fraction& two) {
        double x = one.znam_* two.znam_;
        return Fraction (x / one.znam_ * one.chisl_ + x / two.znam_ * two.chisl_,x);
    }
    friend const Fraction operator - (const Fraction& one, const Fraction& two) {
        double x = one.znam_ * two.znam_;
        return Fraction(x / one.znam_ * one.chisl_ - x / two.znam_ * two.chisl_, x);
    }

    Fraction& operator++()
    {
        ++chisl_; ++znam_;
        return *this;
    }

    Fraction& operator--()
    {
        --chisl_; --znam_;
        return *this;
    }
   
    const Fraction& operator+()
    {
        return  Fraction(+chisl_, +znam_);
    }

    const Fraction& operator-()
    {
       return  Fraction (-chisl_, -znam_);
    }

    friend std:: ostream& operator << (std::ostream& output, const Fraction& f)
    {
        output << f.chisl_ << "/" << f.znam_ << std::endl;
        return output;
    }

    friend std::istream& operator >> (std::istream& input, Fraction& f)
    {
        input >> f.chisl_;
        input.ignore(1);
        input >> f.znam_;
        return input;
    }

    bool is_greater () {
        if (chisl_ > znam_) 
            return true;
        else
            return false;
     }

    bool is_gress() {
       if (fmod(abs(chisl_), abs(znam_)) == 0) 
           return true;
        else
            return false;
    }
    
   



    ~Fraction() { chisl_; znam_; }
};





int main()
{
    setlocale(LC_ALL, "Russian");

    Fraction c (6.6, 1);
    std::cout << c << std::endl;
    std::cout << c.is_greater () << std::endl;
    std::cout << c.is_gress() << std::endl;
  
    
    
    c.fraction_obr();;
    c.setChisl(8.5);
    c.setZnam(8);
    c.display();
    c.fraction();
    c.setChisl(5);
    c.setZnam(8);
    c.operator++();
    c.display();
    c.operator--();
    c.display();
   
    Fraction j = -c;
    j.display();
    
    std::string str1;
    std::cout << "Введите первую дробь \n";
    std::getline(std::cin, str1);
    Fraction a(str1);
    
    std::string str2;
    std::cout << "Введите вторую дробь \n";
    std::getline(std::cin, str2);
    Fraction b(str2);
    

    Fraction one(a.getChisl(), a.getZnam());
    Fraction two(b.getChisl(), b.getZnam());
    
    std::cout << "Умножение: \n"; 
    Fraction mult = one * two;
    mult.display();

     std::cout << "Деление: \n"; 
     Fraction divide = one / two;
     divide.display();

    std::cout << "Сложение: \n";
    Fraction add = one + two;
    add.display();

    std::cout << "Вычитание: \n";
    Fraction subtraction = one - two;
    subtraction.display();
    
    return 0;
}