#include "PointArray.hpp"
#include "Point.hpp"

namespace francis {
    namespace Containers {

        PointArray::PointArray() : Array<francis::CAD::Point>() {}

        PointArray::PointArray(int size) : Array<francis::CAD::Point>(size) {}

        PointArray::PointArray(const PointArray& pa) : Array<francis::CAD::Point>(pa) {}

        PointArray::~PointArray() {}

        PointArray& PointArray::operator=(const PointArray& source) {
            if (this == &source) {
                return *this;
            }
            Array::operator=(source); // Call base class assignment operator
            Array<CAD::Point>::operator=(source);
            return *this;
        }

        double PointArray::Length() const {
            double totalLength = 0.0;
            for (int i = 1; i < Size(); ++i) {
                totalLength += GetElement(i).Distance(GetElement(i - 1));
            }
            return totalLength;
        }

    }
}
