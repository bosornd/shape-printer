# 2_four_callable_objects

## Mission
* Learn with AI - std::function and callable objects.
* Demonstrate 4 callable objects - lambda function, function pointer, functor and std::bind.
* Define interfaces (pure abstract class) - InsideShape and Shape.

```c++
int main() {
    // case 1. print a diamond shape using lambda function
    printShape(1, [](int x, int y, int n) {
        return std::abs(x) + std::abs(y) < n;
    });

    // case 2. print a diamond shape using a named function
    printShape(2, insideDiamond);

    // case 3. print a diamond shape using a functor
    printShape(3, InsideDiamond());

    // case 4. print a diamond shape using a Diamond class
    Diamond diamond;
    printShape(4, std::bind(&Diamond::inside, &diamond, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

}
```
