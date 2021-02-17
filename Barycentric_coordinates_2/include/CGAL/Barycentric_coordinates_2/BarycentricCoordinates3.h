// STL headers.
#include <vector>

// CGAL headers.
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Tetrahedron_3.h>
#include <CGAL/Cartesian_matrix.h>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 point_3;
typedef Kernel::FT Scalar;


std::vector<Scalar> compute_triangle_coordinates_3(const point_3& p0,
    const point_3& p1, const point_3& p2,
    const point_3& p3, const point_3& q) {

    Scalar voltetra = CGAL::Tetrahedron_3<Kernel>(p0, p1, p2, p3).volume();
    Scalar invertedTotVol = 1.0 / voltetra;
    Scalar distb = CGAL::Tetrahedron_3<Kernel>(q, p3, p2, p0).volume() * invertedTotVol;
    Scalar distc = CGAL::Tetrahedron_3<Kernel>(q, p3, p0, p1).volume() * invertedTotVol;
    Scalar distd = CGAL::Tetrahedron_3<Kernel>(q, p0, p1, p2).volume() * invertedTotVol;

    // I cannot find how to directly access `compute_volume_3_object` to calculate the volume
    // So, I'm making a tetrahedron object and then calculating its volume.


    return { 1 - (distb + distc + distd), distb, distc, distd };
}


/// This function calculates the unsigned volume of a tetrahedron given its coordinates.

//Scalar vol_tetrahedron(const point_3& p0,
//    const point_3& p1, const point_3& p2,
//    const point_3& p3) {
//    // volume of a tetrahedron is 1/6* abs of its triple product.
//    // so we can find the three side vectors, and then calculate cross product
//
//    // or we can use the inbuilt tetrahedron module.
//
//      
//    const point_3 a(p0.x() - p1.x(), p0.y() - p1.y(), p0.z() - p1.z());
//    const point_3 b(p0.x() - p2.x(), p0.y() - p2.y(), p0.z() - p2.z());
//    const point_3 c(p0.x() - p3.x(), p0.y() - p3.y(), p0.z() - p3.z());
//
//    //// we can calucate the cross product now.
//    Scalar cp = a.x() * (b.y() * c.z() - b.z() * c.y()) -
//        a.y() * (b.x() * c.z() - b.z() * c.x()) -
//        a.z() * (b.x() * c.y() - b.y() * c.x());
//
//
//    //// getting the absolute value;
//    cp = CGAL::abs(cp);
//    
//    return cp / 6.0;
//    
//}
//
//




/// we can also convert using this linear transformation.
/// T.L = r - r4
/// Where L is vector of req coordinates, r is vector of cartesian coordinates.
/// and T is a 3*3 vector, which can be calculated by rearrangin the eqns.
/// See here for more info: https://en.wikipedia.org/wiki/Barycentric_coordinate_system#Conversion_between_barycentric_and_Cartesian_coordinates

void compute_triangle_coordinates_matrix_3(const Point& p0, const Point& p1,
    const Point& p2, const Point& p3, const Point& q) {
}