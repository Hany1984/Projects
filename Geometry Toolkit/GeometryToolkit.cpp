// ⚙️ Geometry Toolkit
// Description:
// Build a small geometry system to calculate the area of different shapes using inheritance and virtual functions.
// Requirements:
    // Base abstract class:
        // class Shape {
        // public:
        //     virtual double area() const = 0;
        // };
    // Derived classes:
        // Rectangle → has length, width
        // Circle → has radius
        // (Optional) Triangle → base and height
    // Store shapes in vector<unique_ptr<Shape>>.
    // Let the user add shapes and display the total area of all shapes.
    // Use const correctness and constructors for initialization.