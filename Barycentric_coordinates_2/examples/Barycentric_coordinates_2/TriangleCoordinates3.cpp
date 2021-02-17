#include <CGAL/Simple_cartesian.h>
#include <CGAL/Barycentric_coordinates_2/Triangle_coordinates_2.h>

// this is where i've defined the `compute_triangle_coordinates_3` function.
#include <CGAL/Barycentric_coordinates_2/BarycentricCoordinates3.h>


// Some convenient typedefs.
typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 Point;

using std::cout; using std::endl; using std::string;

int main()
{
    // Let these are the four vertices of the tetrahedron.
    const Point first_vertex(0.0f, 0.0f, 0.0f);
    const Point second_vertex(3.0f, 0.0f, 0.0f);
    const Point third_vertex(0.0f, 4.0f, 0.0f);
    const Point fourth_vertex(0.0f, 0.0f, 1.0f);


    const Point query_points[] = { Point(0.5f , 0.5f, 0.0f), Point(1.0f, 0.5f, 0.0f), Point(1.0f , 0.75f, 0.0f), Point(1.0f , 1.0f, 0.0f),
                                    Point(0.0f, 4.0f, 1.0f), Point(1.5f, 2.5f, 0.75f), Point(0.0f, 0.0f, 1.0f),};
    const int number_of_query_points = 7;


    for (int i = 0; i < number_of_query_points; i++) {
        auto getl = compute_triangle_coordinates_3(first_vertex, second_vertex, third_vertex, fourth_vertex, query_points[i]);
        for (auto val : getl) {
            cout << val << " ";
        }

        cout << "\n";
    }

    return EXIT_SUCCESS;
}
