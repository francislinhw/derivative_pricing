#ifndef POINTARRAY_H
#define POINTARRAY_H

#include "Array.hpp"
#include "Point.hpp"

namespace francis {
    namespace Containers {

        class PointArray : public Array<francis::CAD::Point> {
        public:
            PointArray();  // Default constructor
            PointArray(int size);  // Constructor with size parameter
            PointArray(const PointArray& pa);  // Copy constructor
            ~PointArray();  // Destructor
            
            PointArray& operator=(const PointArray& source);  // Assignment operator
            
            double Length() const;  // Calculate the total length between points
        };

    }
}

#endif // POINTARRAY_H
