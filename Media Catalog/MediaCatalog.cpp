// Media Catalog (Books + Movies)
// Description:
// Develop a polymorphic media catalog that can store and display information about books and movies.
// Use inheritance to demonstrate runtime polymorphism.
// Requirements:
    // Base class:
        // class Media {
        // public:
        //     virtual void printInfo() const = 0; // pure virtual function
        // };
    // Derived classes:
        // Book: with title, author
        // Movie: with title, rating, duration
    // Create a vector<unique_ptr<Media>> to hold both Book and Movie objects.
    // Implement:
        // Add new book or movie.
        // Display all media.
        // Search by title.
        // (Optional) Validate movie rating between 0 and 10.
        // (Optional) Save and load data from file.