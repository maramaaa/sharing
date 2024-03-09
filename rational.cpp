Rational::Rational(int value) {
    this->numer_ = value;
    this->denom_ = 1;
}

Rational::Rational() {};

Rational::Rational(int numer, int denom) {

    if (denom == 0) {
        throw RationalDivisionByZero{};
    }
    this->numer_ = numer;
    this->denom_ = denom;
    Simplify(*this);
}

int Rational::GetNumerator() const {
    return this->numer_;
}

int Rational::GetDenominator() const {
    return this->denom_;
}

void Rational::SetNumerator(int value) {
    this->numer_ = value;
}

void Rational::SetDenominator(int value) {
    this->denom_ = value;
}

std::ostream& operator<<(std::ostream& os, const Rational& ratio) {
    os << ratio.GetNumerator() << '\\' << ratio.GetDenominator();
    return os;
}

std::istream& operator>>(std::istream& is, Rational& ratio) {
    is >> ratio.numer_ >> ratio.denom_;
    return is;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational answer(1, 1);
    int gcd = Gcd(lhs.GetDenominator(), rhs.GetDenominator());
    answer.SetNumerator(lhs.GetNumerator() * rhs.GetDenominator() / gcd +
                        rhs.GetNumerator() * lhs.GetDenominator() / gcd);
    answer.SetDenominator(Lcm(lhs.GetDenominator(), rhs.GetDenominator()));
    Simplify(answer);
    return answer;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational answer(1, 1);
    int gcd = Gcd(lhs.GetDenominator(), rhs.GetDenominator());
    answer.SetNumerator(lhs.GetNumerator() * rhs.GetDenominator() / gcd -
                        rhs.GetNumerator() * lhs.GetDenominator() / gcd);
    answer.SetDenominator(Lcm(lhs.GetDenominator(), rhs.GetDenominator()));
    Simplify(answer);
    return answer;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational answer(1, 1);
    answer.SetNumerator(lhs.GetNumerator() * rhs.GetNumerator());
    answer.SetDenominator(lhs.GetDenominator() * rhs.GetDenominator());
    Simplify(answer);
    return answer;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational answer(1, 1);
    answer.SetNumerator(lhs.GetNumerator() * rhs.GetDenominator());
    answer.SetDenominator(lhs.GetDenominator() * rhs.GetNumerator());
    Simplify(answer);
    return answer;
}

Rational& operator+=(Rational& lhs, const Rational& rhs) {
    Rational c = lhs + rhs;
    lhs = c;
    return lhs;
}

Rational& operator-=(Rational& lhs, const Rational& rhs) {
    Rational c = lhs - rhs;
    lhs = c;
    return lhs;
}

Rational& operator*=(Rational& lhs, const Rational& rhs) {
    Rational c = lhs * rhs;
    lhs = c;
    return lhs;
}

Rational& operator/=(Rational& lhs, const Rational& rhs) {
    Rational c = lhs * rhs;
    lhs = c;
    return lhs;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    if (lhs.GetDenominator() == rhs.GetDenominator() && lhs.GetNumerator() == rhs.GetDenominator()) {
        return true;
    }
    return false;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    int gcd = Gcd(lhs.GetDenominator(), rhs.GetDenominator());
    int lhs_n = lhs.GetNumerator() * rhs.GetDenominator() / gcd;
    int rhs_n = rhs.GetNumerator() * lhs.GetDenominator() / gcd;
    if (lhs_n < rhs_n) {
        return true;
    }
    return false;
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    if (rhs < lhs) {
        return true;
    }
    return false;
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
    if (lhs < rhs or rhs == lhs) {
        return true;
    }
    return false;
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
    if (lhs < rhs or rhs == lhs) {
        return true;
    }
    return false;
}

Rational operator++(Rational& ratio, int) {
    ratio = ratio + Rational(1, 1);
    return ratio;
}


Rational operator--(Rational& ratio, int) {
    ratio = ratio - Rational(1, 1);
    return ratio;
}

Rational& operator++(Rational& ratio) {
    ratio.numer_ += ratio.denom_;
    Simplify(ratio);
    return ratio;
}  // faster than += 1

Rational& operator--(Rational& ratio) {
    ratio.numer_ -= ratio.denom_;
    Simplify(ratio);
    return ratio;
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    if (rhs == lhs) {
        return false;
    }
    return true;
}

Rational operator+(const Rational& ratio) {
    if (ratio.GetDenominator() >= 0 && ratio.GetNumerator() >= 0) {
        return Rational(1, 1);
    } else if (ratio.GetDenominator() <= 0 && ratio.GetNumerator() <= 0) {
        return Rational(1, 1);
    }
    return false;
}

Rational operator-(const Rational& ratio) {
    if (+ratio.GetNumerator() == 1) {
        return Rational(-1, 1);
    }
    return Rational(1, 1);
}
