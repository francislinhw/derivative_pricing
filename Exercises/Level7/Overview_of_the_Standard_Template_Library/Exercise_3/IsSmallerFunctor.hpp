#ifndef IS_SMALLER_FUNCTOR_HPP
#define IS_SMALLER_FUNCTOR_HPP

// Function object for comparison
class IsSmallerFunctor {
private:
    double threshold;

public:
    IsSmallerFunctor(double t) : threshold(t) {}

    bool operator()(double value) const {
        return value < threshold;
    }
};
#endif