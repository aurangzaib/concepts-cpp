

// function in a class:
// in cpp --> member function
// in other languages --> method
int main() {
    // struct:
    // same as class
    // by default has public properties and methods
    struct my_struct {
        int a;
        string b;
        double c;

        // ctor
        my_struct(int a, string b) : a(a), b(b) {}

        // dtor
        ~my_struct() {}

        // member function
        double a_func() {
            return c;
        }
    } x, y;

    struct nested_struct {
        my_struct nested_property;
        string some_str;
    };

    my_struct z;
    // x,y,z are instances of my_struct
    x.a;
    // pointer to struct
    my_struct *ptr = &z;
    // access property using pointer
    ptr->a;
    (*ptr).a;
    // for (*ptr).a, brackets are necessary

    // instance of nested structure
    nested_struct nested_inst();
    // pointer to instance
    nested_struct *nested_ptr = &nested_inst;
    // access nested property using instance
    nested_inst.nested_property.b;
    // access nested property using pointer
    nested_ptr->nested_property.b;
    (*nested_ptr).nested_property.b;
}