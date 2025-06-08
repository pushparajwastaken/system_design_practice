`Static Function`
Static members of a class are not associated with the objects of the class. Just like a static variable once declared is allocated with memory that can't be changed every object points to the same memory. Once a static member is declared it will be treated as same for all the objects associated with the class.
Static Member Function in a class is the function that is declared as static because of which function attains certain properties as defined below:

A static member function is independent of any object of the class.
A static member function can be called even if no objects of the class exist.
A static member function can also be accessed using the class name through the scope resolution operator.
A static member function can access static data members and static member functions inside or outside of the class.
Static member functions have a scope inside the class and cannot access the current object pointer.
You can also use a static member function to determine how many objects of the class have been created.
The reason we need Static member function:
Static members are frequently used to store information that is shared by all objects in a class.
For instance, you may keep track of the quantity of newly generated objects of a specific class type using a static data member as a counter. This static data member can be increased each time an object is generated to keep track of the overall number of objects.
